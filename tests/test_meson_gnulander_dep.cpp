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

#include <boost/ut.hpp> // import boost.ut;

/// @file
/// This test file assumes that this executable is compiled with meson as follows:
///
///     executable(
///         "...",
///         files(<__FILE__>),
///         dependencies: [<boost_ut_dep>, <gnulander_dep>],
///         ...
///     )

// Include before potential config.h, as it should error out (gnulib feature)
// if gnulib stddef.h is found and config.h is not include.
#include <stddef.h>
#if __has_include(<config.h>)
#    include <config.h>
#endif
#include <string_view>
#include <format>

#include "gnulander/pipe.hpp"

int main() {
    using namespace boost::ut;
    cfg<override> = { .tag = { "meson" } };

    // Compilation of this translation unit should fail if the wrapped headrs are found,
    // as stddef.h is included before config.h (see above).
    tag("meson")
        / "depending on gnulander_dep does not 'wrap' libc headers"_test = [] { expect(true); };


    tag("meson") / "depending on gnulander_dep does not maek gnulib config.h to be found"_test = [] {
        using namespace std::literals;
#ifdef PACKAGE
        expect(false) << std::format("PACKAGE cpp macro defined to be: {}", PACKAGE);
#else
        expect(true);
#endif
    };

    tag("meson") / "depending on gnulander_dep does not make gnulib headers to be found"_test = [] {
#if __has_include("full-read.h")
      expect(false) << "full-read.h found";
#elif __has_include("full-write.h")
      expect(false) << "full-write.h found";
#else
      expect(true);
#endif
    };
}
