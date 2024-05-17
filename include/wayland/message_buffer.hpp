#pragma once

/// @file Implements container of Wayland protocol messages.

#include <cassert>
#include <cstddef>
#include <cstring>
#include <ranges>
#include <tuple>
#include <utility>

#include "byte_vec.hpp"
#include "type_utils.hpp"
#include "wayland/protocol_primitives.hpp"
#include <sstd.hpp>

namespace ger {
namespace wl {

class message_buffer {
    sstd::byte_vec buff_{};

  public:
    /// True if buffer does not contains any data.
    constexpr bool empty() { return buff_.empty(); }

    template<interface WObj, message_for_inteface<WObj> Message>
    constexpr void append(const Wobject<WObj> obj, const Message& msg) {
        const auto msg_primitives               = sstd::to_ref_tuple(msg);
        constexpr auto amount_of_msg_primitives = std::tuple_size_v<decltype(msg_primitives)>;

        auto msg_total_size = sizeof(message_header<WObj>);

        const auto write_element_32aligned = sstd::overloaded{
            [&](const Wstring& str) {
                const auto element_size_without_pad_wrong_type =
                    sizeof(Wstring::size_type) + str.size() + 1uz; // + 1 for \0 delimiter.
                assert(std::in_range<Wstring::size_type>(element_size_without_pad_wrong_type));
                const auto element_size_withou_pad =
                    static_cast<Wstring::size_type>(element_size_without_pad_wrong_type);

                const auto element_size =
                    element_size_without_pad_wrong_type
                    + sstd::round_upto_multiple_of<4>(element_size_without_pad_wrong_type);

                const auto buff_size_before = std::ranges::size(buff_);
                buff_.resize(buff_size_before + element_size);
                // size
                std::memcpy(std::addressof(buff_[buff_size_before]),
                            std::addressof(element_size_withou_pad),
                            sizeof(Wstring::size_type));
                // string
                std::memcpy(std::addressof(buff_[buff_size_before + sizeof(Wstring::size_type)]),
                            str.data(),
                            str.size());
                // null delimiter
                buff_.back() = std::byte{ 0 };

                msg_total_size += element_size;
            },
            [&](const Warray& arr) {
                const auto element_size_without_pad_wrong_type =
                    sizeof(Warray::size_type) + arr.size();
                assert(std::in_range<Warray::size_type>(element_size_without_pad_wrong_type));
                const auto element_size_without_pad =
                    static_cast<Warray::size_type>(element_size_without_pad_wrong_type);

                const auto element_size =
                    element_size_without_pad
                    + sstd::round_upto_multiple_of<4>(element_size_without_pad);

                const auto buff_size_before = std::ranges::size(buff_);
                buff_.resize(buff_size_before + element_size);
                // size
                std::memcpy(std::addressof(buff_[buff_size_before]),
                            std::addressof(element_size_without_pad),
                            sizeof(Wstring::size_type));
                // array
                std::memcpy(std::addressof(buff_[buff_size_before + sizeof(Wstring::size_type)]),
                            arr.data(),
                            arr.size());
                msg_total_size += element_size;
            },
            [&]<typename P>(const P& p) {
                constexpr auto pad          = sstd::round_upto_multiple_of<4>(sizeof(P));
                constexpr auto element_size = sizeof(P) + pad;

                const auto buff_size_before = std::ranges::size(buff_);
                buff_.resize(buff_size_before + element_size);
                std::memcpy(std::addressof(buff_[buff_size_before]), &p, sizeof(P));
                msg_total_size += element_size;
            }
        };

        const auto begin_of_header_index = std::ranges::size(buff_);
        // Have room for the header.
        buff_.resize(buff_.size() + sizeof(message_header<WObj>));

        // Loop over all msg primitives.
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (write_element_32aligned(std::get<I>(msg_primitives)), ...);
        }(std::make_index_sequence<amount_of_msg_primitives>());

        using underlying_size_t = sstd::underlying_integral_t<Wmessage_size_t>;
        const auto header       = message_header<WObj>{ obj,
                                                        static_cast<underlying_size_t>(msg_total_size),
                                                        Message::opcode };

        std::memcpy(std::addressof(buff_[begin_of_header_index]),
                    std::addressof(header),
                    sizeof(header));
    }

    constexpr auto release_data() -> sstd::byte_vec {
        return std::exchange(buff_, sstd::byte_vec{});
    };
};

} // namespace wl
} // namespace ger
