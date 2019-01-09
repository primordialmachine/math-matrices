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

template<typename LEFT_OPERAND, typename RIGHT_OPERAND, typename ENABLED = void>
struct binary_minus_functor;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
auto
binary_minus(const LEFT_OPERAND& left_operand,
             const RIGHT_OPERAND& right_operand)
  -> decltype(
    binary_minus_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                        right_operand))
{
  return binary_minus_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                             right_operand);
}

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
auto
operator-(const LEFT_OPERAND& left_operand, const RIGHT_OPERAND& right_operand)
  -> decltype(binary_minus(left_operand, right_operand))
{
  return binary_minus(left_operand, right_operand);
}

// Default implementation for floating point types.
template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
struct binary_minus_functor<
  LEFT_OPERAND,
  RIGHT_OPERAND,
  std::enable_if_t<std::is_floating_point_v<LEFT_OPERAND> &&
                   std::is_floating_point_v<RIGHT_OPERAND>>>
{
  using left_operand_type = LEFT_OPERAND;
  using right_operand_type = RIGHT_OPERAND;
  using result_type = std::common_type_t<left_operand_type, right_operand_type>;
  result_type operator()(left_operand_type x, right_operand_type y) const
    noexcept(noexcept(x - y))
  {
    return x - y;
  }
}; // struct binary_minus_functor

} // namespace primordialmachine
