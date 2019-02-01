///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Non Scalars Library
// Copyright (c) 2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "primordialmachine/functors/include.hpp"
#include "primordialmachine/math/non_scalars/is_non_scalar.hpp"

namespace primordialmachine {

template<typename T, typename E = void>
struct is_non_degenerate;

// clang-format off
// As the constexpr member variable
// is_non_degenerate::value
// is only defined for non scalar types, we also define the constexpr variable
// is_non_degenerate_v
// only for non scalar types.
// clang-format on
template<typename T>
constexpr enable_if_t<is_non_scalar_v<T>, bool> is_non_degenerate_v =
  is_non_degenerate<T>::value;

} // namespace primordialmachine
