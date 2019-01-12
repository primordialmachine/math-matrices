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

template<typename M>
struct binary_plus_functor<
  M,
  M,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_degenerate>>
{
  using left_operand_type = M;
  using right_operand_type = M;
  using result_type = M;
  result_type operator()(const left_operand_type& left_operand,
                         const right_operand_type& right_operand) const
  {
    return result_type();
  }
}; // struct binary_plus_functor


template<typename M>
struct binary_plus_functor<
  M,
  M,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_non_degenerate>>
  : public elementwise_binary_matrix_functor<
      typename M::traits_type,
      binary_plus_functor<typename M::traits_type::element_type,
                          typename M::traits_type::element_type>>
{};

template<typename TRAITS>
auto& /*TODO: Does this suffice to ensure the reference is returned?*/
operator+=(matrix<TRAITS>& u, const matrix<TRAITS>& v)
{
  u = u + v;
  return u;
}

} // namespace primordialmachine
