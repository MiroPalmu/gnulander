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

#pragma once

#include <array>
#include <concepts>
#include <filesystem>
#include <functional>
#include <future>
#include <iterator>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

#include "gnulander/byte_vec.hpp"

struct pipe_filter_gi;

namespace gnulander {

template<typename T>
using immovable_memory = std::unique_ptr<T>;

using exit_code_type = int;

/// Run a subprocess which stdin can be written and stdout read.
///
/// All subprocesses have corresponging exit code future,
/// which will be set after subprocess::kill or destructor.
/// If it is done in destructor there is possibility of a excpetion (i.e. std::abort()).
///
/// If subprocess launched in constructor is still alive in destructor,
/// it has to be killed. This might throw exception which is stored to exit code future.
/// This will never happen if subprocess::kill is called.
class subprocess {
    struct stdout_read_closure {
        sstd::byte_vec buff_                     = sstd::byte_vec(1u << 4u);
        sstd::byte_vec::iterator next_read_here_ = buff_.begin();

      public:
        auto bytes_used() -> std::ranges::range_difference_t<decltype(buff_)>;
        /// % of how full buff_ is.
        auto fullness() -> double;
        /// Doubles buff_ capacity.
        void double_capacity();
        auto where_to_read() -> std::span<std::byte>;
        void use_n_bytes(const std::size_t n);
        auto release_buff() -> std::string;
        void kill();
    };

    /// Shared in callbacks that read subrocess's stdout.
    ///
    /// Needs to be immovable, as subprocess can be moved between callback invocations.
    /// When moving subprocess object, the pointer to shared data can not be updated.
    immovable_memory<stdout_read_closure> stdout_read_callback_private_data_{
        std::make_unique<stdout_read_closure>()
    };
    std::optional<pipe_filter_gi*> pipe_filter_ptr_{};
    std::promise<exit_code_type> exit_code_promise_{};

    subprocess(const std::string_view program,
               const std::span<const std::string_view> program_args = {});

  public:
    /// Make (subprocess, exit code future)-pair. Throws on error.
    template<typename... Args>
        requires(std::constructible_from<std::string_view,
                                         decltype(std::forward<Args>(std::declval<Args>()))>
                 and ...)
    friend auto launch_subprocess(const std::string_view program, Args&&... args)
        -> std::pair<subprocess, std::future<exit_code_type>> {
        const auto arg_arr =
            std::array<std::string_view, sizeof...(Args)>{ std::forward<Args>(args)... };

        auto p = subprocess{ program, std::span{ arg_arr } };
        auto f = p.exit_code_promise_.get_future();
        return std::make_pair(std::move(p), std::move(f));
    }

    ~subprocess();

    subprocess(const subprocess&)            = delete;
    subprocess& operator=(const subprocess&) = delete;
    subprocess(subprocess&&) noexcept;
    subprocess& operator=(subprocess&&) noexcept;

    /// Release stdout read buffer.
    [[nodiscard]] auto stdout() -> std::string;
    /// Kill subprocess. Throws on error.
    void kill();
    /// Write to stdin. Throws on error.
    friend void operator|(const std::string_view input, subprocess& s);
};

/// Introduce launch_subprocess to outside scope as it can not be found using ADL.
///
/// Friend functions delcared in classes are not visible in outside scope.
/// They are usually found with ADL.
template<typename... Args>
    requires(std::constructible_from<std::string_view,
                                     decltype(std::forward<Args>(std::declval<Args>()))>
             and ...)
auto launch_subprocess(const std::string_view program,
                       Args&&... args) -> std::pair<subprocess, std::future<exit_code_type>>;

} // namespace gnulander
