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

#include "gnulander/construct_allocator_adapter.hpp"

namespace gnulander {
namespace sstd {
using byte_vec_alloc =
    sstd::allocator::construct_allocator_adapter<sstd::allocator::default_init_construct,
                                                 std::byte>;
using byte_vec = std::vector<std::byte, byte_vec_alloc>;
} // namespace sstd
} // namespace gnulander
