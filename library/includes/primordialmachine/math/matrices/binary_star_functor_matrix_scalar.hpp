///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Matrices Library
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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"

namespace primordialmachine {

// non-degenerated case
// M a matrix type
// S a scalar type
template<typename M, typename S>
struct binary_star_functor<
  M,
  S,
  std::enable_if_t<is_matrix<M>::value && is_scalar<S>::value>>
{
  using functor = elementwise_binary_functor<
    M,
    scalar_generator_functor<S>,
    M,
    M::traits_type::number_of_elements,
    binary_star_functor<typename M::traits_type::element_type, S>,
    void>;
  using left_operand_type = M;
  using right_operand_type = S;
  using result_type = typename functor::result_type;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return functor()(left_operand, scalar_generator_functor<S>(right_operand));
  }
};

template<typename TRAITS, typename SCALAR>
auto& /*TODO: Does this return a reference? Is this the best method?*/
operator*=(matrix<TRAITS>& v, SCALAR s)
{
  v = v * s;
  return v;
}

template<typename S, typename M>
struct binary_star_functor<
  S,
  M,
  std::enable_if_t<is_scalar<S>::value && is_matrix<M>::value>>
{
  using functor = elementwise_binary_functor<
    scalar_generator_functor<S>,
    M,
    M,
    M::traits_type::number_of_elements,
    binary_star_functor<typename M::traits_type::element_type, S>,
    void>;
  using left_operand_type = S;
  using right_operand_type = M;
  using result_type = typename functor::result_type;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return functor()(scalar_generator_functor<S>(left_operand), right_operand);
  }
};

} // namespace primordialmachine
