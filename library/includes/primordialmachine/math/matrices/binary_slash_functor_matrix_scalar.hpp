///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Matrices Library
// Copyright (c) 2017-2019 Michael Heilmann
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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"

namespace primordialmachine {

// degenerated case
// M a matrix type
// S a scalar type
template<typename M, typename S>
struct binary_slash_functor<
  M,
  S,
  enable_if_t<is_matrix_v<M> && is_degenerate_v<M> && is_scalar_v<S>>>
{
  using left_operand_type = M;
  using right_operand_type = S;
  using result_type = matrix<matrix_traits<common_type_t<element_type_t<M>, S>,
                                           number_of_columns_v<M>,
                                           number_of_rows_v<M>>>;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return result_type();
  }
}; // struct binary_slash_functor

// non-degenerated case
// M a matrix type
// S a scalar type
template<typename M, typename S>
struct binary_slash_functor<
  M,
  S,
  enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M> && is_scalar_v<S>>>
{
  using functor =
    elementwise_binary_functor<M,
                               scalar_generator_functor<S>,
                               M,
                               number_of_elements_v<M>,
                               binary_slash_functor<element_type_t<M>, S>,
                               void>;
  using left_operand_type = M;
  using right_operand_type = S;
  using result_type = result_type_t<functor>;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return functor()(left_operand, scalar_generator_functor<S>(right_operand));
  }
}; // struct binary_slash_functor

template<typename M, typename S>
struct slash_assignment_functor<
  M,
  S,
  enable_if_t<is_matrix_v<M> && is_degenerate_v<M> && is_scalar_v<S>>>
{
  using left_operand_type = M;
  using right_operand_type = S;
  using result_type = M;
  result_type& operator()(left_operand_type& left_operand,
                          const right_operand_type& right_operand) const
  {
    return left_operand;
  }
}; // struct slash_assignment_functor

template<typename M, typename S>
struct slash_assignment_functor<
  M,
  S,
  enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M> && is_scalar_v<S>>>
{
  using left_operand_type = M;
  using right_operand_type = S;
  using result_type = M;
  result_type& operator()(left_operand_type& left_operand,
                          const right_operand_type& right_operand) const
  {
    left_operand = left_operand / right_operand;
    return left_operand;
  }
}; // struct slash_assignment_functor

} // namespace primordialmachine
