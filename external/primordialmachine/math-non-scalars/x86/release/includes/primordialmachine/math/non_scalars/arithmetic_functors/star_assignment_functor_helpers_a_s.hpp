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

#include "primordialmachine/math/non_scalars/arithmetic_functors/arithmetic_functors_helpers.hpp"

namespace primordialmachine {

// Case of a *= s where a is of type A and s is of type S.
// A is a degenerate non-scalar type.
// S is a scalar type.
template<typename A, typename S>
struct default_elementwise_star_assignment_functor<
  A,
  S,
  enable_if_t<is_non_scalar_v<A> && is_degenerate_v<A> && is_scalar_v<S>>>
{
  using left_operand_type = A;
  using right_operand_type = S;
  using result_type = A;
  constexpr result_type& operator()(
    left_operand_type& left_operand,
    const right_operand_type& right_operand) const noexcept
  {
    return left_operand;
  }
}; // struct default_elementwise_star_assignment_functor

// Case of a *= s where a is of type A and s is of type S.
// A is a non-degenerate non-scalar type.
// S is a scalar type.
template<typename A, typename S>
struct default_elementwise_star_assignment_functor<
  A,
  S,
  enable_if_t<is_non_scalar_v<A> && is_non_degenerate_v<A> && is_scalar_v<S>>>
{
  using left_operand_type = A;
  using right_operand_type = S;
  using result_type = A;
  result_type& operator()(left_operand_type& left_operand,
                          const right_operand_type& right_operand) const
    noexcept(noexcept(left_operand = left_operand * right_operand))
  {
    left_operand = left_operand * right_operand;
    return left_operand;
  }
}; // struct default_elementwise_star_assignment_functor

} // namespace primordialmachine
