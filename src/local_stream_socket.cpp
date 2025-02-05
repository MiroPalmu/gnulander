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
// For O_CLOEXEC macro and fd_safer_flag.
#include "unistd-safer.h"
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <cstring>
#include <format>
#include <tuple>

#include "gnulander/fd_handle.hpp"
#include "gnulander/local_stream_socket.hpp"
#include "gnulander/sstd.hpp"

namespace gnulander {

[[nodiscard]] auto open_local_stream_socket_pair()
    -> std::pair<local_stream_socket, local_stream_socket> {
    std::array<fd_native_type, 2> raw_fds;

    if (-1 == socketpair(PF_LOCAL, SOCK_STREAM, 0, raw_fds.data())) {
        // Opening failure.
        sstd::throw_generic_system_error();
    }

    // Prevent std{in,out,err} globbing and set O_CLOEXEC.
    for (auto& fd : raw_fds) {
        fd = fd_safer_flag(fd, O_CLOEXEC);
        if (fd == -1) sstd::throw_generic_system_error();
    }

    return { fd_handle{ raw_fds.front() }, fd_handle{ raw_fds.back() } };
}

[[nodiscard]] auto open_local_stream_socket_connected_to(const std::filesystem::path& server_path)
    -> local_stream_socket {
    // Test that server_path is not too long before calling gnulib::socket(...).
    const auto server_path_str = server_path.native();
    if (server_path_str.size() >= 107) {
        throw std::runtime_error{ std::format(
            "Path '{}'\nis logner than max path length (108 chars) for sockaddr_un::sun_path",
            server_path_str) };
    }

    // server_path is not too long so we can proceed.
    auto sock_to_be_connected = gnulib::socket(AF_LOCAL, SOCK_STREAM, 0);
    if (-1 == sock_to_be_connected) { sstd::throw_generic_system_error(); }

    // Prevent std{in,out,err} globbing and set O_CLOEXEC.
    sock_to_be_connected = ::fd_safer_flag(sock_to_be_connected, O_CLOEXEC);
    if (-1 == sock_to_be_connected) { sstd::throw_generic_system_error(); }

    auto socket_addres = [&] {
        auto addres = ::sockaddr_un{ .sun_family = AF_LOCAL, .sun_path = {} };
        std::memcpy(addres.sun_path, server_path_str.c_str(), server_path_str.size());
        return addres;
    }();

    const auto connect_call = gnulib::connect(sock_to_be_connected,
                                              reinterpret_cast<::sockaddr*>(&socket_addres),
                                              sizeof(socket_addres));
    if (-1 == connect_call) {
        // Opened socket which failed to connect has to be cleaned up.
        // But store errno before closing it as the close can also fail.
        const auto stored_errno = errno;
        if (-1 == gnulib::close(sock_to_be_connected)) { sstd::throw_generic_system_error(); }
        errno = stored_errno;
        sstd::throw_generic_system_error();
    }

    return { sock_to_be_connected };
}

} // namespace gnulander
