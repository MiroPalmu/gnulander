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

#include <boost/ut.hpp> // import boost.ut;

#include <array>
#include <format>
#include <print>
#include <source_location>
#include <string_view>

#include "gnulander/subprocess.hpp"

void assert_subprocess_stdout(gnulander::subprocess& process,
                              const std::string_view expected,
                              std::source_location loc = std::source_location::current()) {
    const auto output = process.stdout();
    boost::ut::expect(output == expected) << std::format("{}:{}: expected '{}', got '{}'",
                                                         loc.file_name(),
                                                         loc.line(),
                                                         expected,
                                                         output);
}

int main() {
    using namespace boost::ut;
    cfg<override> = { .tag = { "gnu" } };

    tag("gnu") / "subprocess can set its exit code future"_test = [] {
        auto [process, exit_code_future] = gnulander::launch_subprocess("true");
        process.kill();
        expect(exit_code_future.get() == 0);
    };

    tag("gnu") / "subprocess can produce stdout"_test = [] {
        using namespace std::literals;
        auto [process, exit_code_future] = gnulander::launch_subprocess("echo", "foo", "bar");
        process.kill();
        expect(exit_code_future.get() == 0);
        assert_subprocess_stdout(process, "foo bar\n");
    };

    tag("gnu") / "trying to run non-existing program throws"_test = [] {
        using namespace std::literals;
        std::println(std::cerr, "Following error is expected part of a successful test:");
        expect(throws(
            [] { auto _ = gnulander::launch_subprocess("/gnulander/this/should/not/exists"); }));
    };

    tag("gnu") / "subprocess can take stdin"_test = [] {
        using namespace std::literals;
        auto [process, exit_code_future] = gnulander::launch_subprocess("cat", "-");
        "foo " | process;
        "bar" | process;
        process.kill();
        expect(exit_code_future.get() == 0);
        assert_subprocess_stdout(process, "foo bar");
    };
}
