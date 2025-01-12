// Copyright (C) 2024 Miro Palmu.
//
// This file is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this file.  If not, see <https://www.gnu.org/licenses/>.

#include <config.h>
// Required to make gnulib not define macros for libc functions.
//
// For more information see gnulander sphinx docs: Usage of Gnulib.
#define GNULIB_NAMESPACE gnulib
#include "pipe-filter.h"

#include <algorithm>
#include <cstddef>

/// Suppress warning from using ::pthread_once and not gnulib::pthread_once.
#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wattribute-warning"
#endif
#include <filesystem>
#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

#include <print>
#include <ranges>
#include <stdexcept>

#include "gnulander/byte_vec.hpp"
#include "gnulander/sstd.hpp"
#include "gnulander/subprocess.hpp"

namespace gnulander {

auto subprocess::stdout_read_closure::bytes_used()
    -> std::ranges::range_difference_t<decltype(buff_)> {
    return std::ranges::distance(buff_.begin(), next_read_here_);
}

auto subprocess::stdout_read_closure::fullness() -> double {
    return static_cast<double>(bytes_used()) / buff_.size();
}

void subprocess::stdout_read_closure::double_capacity() {
    const auto num_bytes = bytes_used();
    /// Invalidates pointers.
    buff_.resize(2u * buff_.size());
    next_read_here_ = std::ranges::next(buff_.begin(), num_bytes);
}

auto subprocess::stdout_read_closure::where_to_read() -> std::span<std::byte> {
    return { next_read_here_, buff_.end() };
}

auto subprocess::stdout_read_closure::release_buff() -> std::string {
    const auto buff_begin_as_char_ptr     = reinterpret_cast<char const*>(buff_.data());
    const auto next_read_here_as_char_ptr = reinterpret_cast<char const*>(&*next_read_here_);
    const auto what_have_been_read =
        std::string(buff_begin_as_char_ptr, next_read_here_as_char_ptr);

    buff_.resize(1u << 4u);
    next_read_here_ = buff_.begin();
    return what_have_been_read;
}

void subprocess::stdout_read_closure::use_n_bytes(const std::size_t n) {
    std::ranges::advance(next_read_here_, n, buff_.end());
}

subprocess::subprocess(const std::string_view program,
                       const std::span<const std::string_view> program_args) {
    const auto program_path     = std::filesystem::path{ program };
    const auto program_path_str = program_path.native();
    const auto program_name_str = program_path.filename().native();

    // Make program_args to vector of char const* which contains nullptr at the end.
    const auto arg_list =
        std::views::concat(std::views::single(program_path_str.c_str()),
                           program_args
                               | std::views::transform(
                                   [](const std::string_view word_str) { return word_str.data(); }),
                           std::views::single(static_cast<char const*>(nullptr)))
        | std::ranges::to<std::vector<char const*>>();

    const auto prep_read = [](std::size_t* size_of_returned_buffer,
                              void* private_data_ptr) -> void* {
        auto& private_data =
            *static_cast<decltype(stdout_read_callback_private_data_)::element_type*>(
                private_data_ptr);

        if (0.6 < private_data.fullness()) { private_data.double_capacity(); }

        const auto where_to_read = private_data.where_to_read();
        *size_of_returned_buffer = where_to_read.size();
        return static_cast<void*>(where_to_read.data());
    };

    const auto done_read =
        [](void*, const std::size_t num_bytes_read, void* private_data_ptr) -> void {
        auto& private_data =
            *static_cast<decltype(stdout_read_callback_private_data_)::element_type*>(
                private_data_ptr);

        private_data.use_n_bytes(num_bytes_read);
    };

    auto* const new_filter_ptr = ::pipe_filter_gi_create(program_name_str.c_str(),
                                                         program_path_str.c_str(),
                                                         arg_list.data(),
                                                         false,
                                                         false,
                                                         prep_read,
                                                         done_read,
                                                         stdout_read_callback_private_data_.get());

    // Documentation of pipe_filter_gi_create says that on failed launch of subprocess,
    // it should return NULL. However the implementation does not match this,
    // so we have to do a single fluff write, which will detect failed subprocess.
    //
    // if (new_filter_ptr == nullptr) { sstd::throw_generic_system_error(); }
    const auto some_valid_mem      = char{};
    const auto dont_write_anything = std::size_t{ 0 };
    const auto code = ::pipe_filter_gi_write(new_filter_ptr, &some_valid_mem, dont_write_anything);
    if (code == -1) {
        sstd::throw_generic_system_error();
    } else if (code == 0) {
        pipe_filter_ptr_ = new_filter_ptr;
    } else if (code > 0) {
        exit_code_promise_.set_value(code);
    } else {
        std::runtime_error{ "Should not happend." };
    }
}

subprocess::~subprocess() {
    try {
        kill();
    } catch (...) { exit_code_promise_.set_exception(std::current_exception()); }
}

subprocess::subprocess(subprocess&& p) noexcept {
    stdout_read_callback_private_data_ = std::move(p.stdout_read_callback_private_data_);
    pipe_filter_ptr_                   = p.pipe_filter_ptr_;
    p.pipe_filter_ptr_.reset();
    exit_code_promise_ = std::move(p.exit_code_promise_);
}
subprocess& subprocess::operator=(subprocess&& p) noexcept {
    stdout_read_callback_private_data_ = std::move(p.stdout_read_callback_private_data_);
    pipe_filter_ptr_                   = p.pipe_filter_ptr_;
    p.pipe_filter_ptr_.reset();
    exit_code_promise_ = std::move(p.exit_code_promise_);
    return *this;
}

auto subprocess::stdout() -> std::string {
    return stdout_read_callback_private_data_->release_buff();
}

void operator|(const std::string_view input, subprocess& s) {
    if (not s.pipe_filter_ptr_.has_value()) { return; }

    const auto code = ::pipe_filter_gi_write(s.pipe_filter_ptr_.value(),
                                             input.data(),
                                             std::span(input).size_bytes());
    if (code == -1) {
        sstd::throw_generic_system_error();
    } else if (code > 0) {
        s.exit_code_promise_.set_value(code);
        s.pipe_filter_ptr_.reset();
    }
}

void subprocess::kill() {
    if (not pipe_filter_ptr_.has_value()) return;

    const auto potential_exit_code = ::pipe_filter_gi_close(pipe_filter_ptr_.value());
    pipe_filter_ptr_.reset();
    const auto is_system_error = potential_exit_code == -1;
    if (is_system_error) { sstd::throw_generic_system_error(); }
    exit_code_promise_.set_value(potential_exit_code);
}

} // namespace gnulander
