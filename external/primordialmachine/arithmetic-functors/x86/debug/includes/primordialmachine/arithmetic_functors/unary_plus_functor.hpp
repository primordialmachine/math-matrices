///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Arithmetic Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
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

#include <type_traits>

namespace primordialmachine {

template<typename OPERAND, typename ENABLED = void>
struct unary_plus_functor;

template<typename OPERAND>
auto
unary_plus(const OPERAND& operand)
  -> decltype(unary_plus_functor<OPERAND>()(operand))
{
  return unary_plus_functor<OPERAND>()(operand);
}

template<typename OPERAND>
auto
operator+(const OPERAND& operand) -> decltype(unary_plus(operand))
{
  return unary_plus(operand);
}

// Default implementation for floating point types.
template<typename OPERAND>
struct unary_plus_functor<OPERAND,
                          std::enable_if_t<std::is_floating_point_v<OPERAND>>>
{
  using operand_type = OPERAND;
  using result_type = OPERAND;
  result_type operator()(operand_type x) const noexcept(noexcept(+x))
  {
    return +x;
  }
}; // struct unary_plus_functor

} // namespace primordialmachine
