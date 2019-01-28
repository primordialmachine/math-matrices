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

#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"
#include "primordialmachine/relational_functors/include.hpp"

namespace primordialmachine {

// Specialization for n == 0 or m == 0 matrices.
// A, B degenerate matrix types
template<typename A, typename B>
struct equal_to_functor<A,
                        B,
                        enable_if_t<is_matrix_v<A> && is_degenerate_v<A> &&
                                    is_matrix_v<B> && is_degenerate_v<B>>>
{
  using left_operand_type = A;
  using right_operand_type = B;
  using result_type = bool;

  bool operator()(const left_operand_type& a, const right_operand_type& b) const
  {
    return true;
  }

}; // struct equal_to_functor

// Specialization for n > 0 and m > 0 matrices.
// M a matrix type
template<typename M>
struct equal_to_functor<M,
                        M,
                        enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M>>>
{
  using left_operand_type = M;
  using right_operand_type = M;
  using result_type = bool;
  bool operator()(const left_operand_type& a, const right_operand_type& b) const
  {
    return impl(a, b, make_index_sequence<number_of_elements_v<M>>());
  }

  template<size_t... N>
  constexpr bool impl(const left_operand_type& a,
                      const right_operand_type& b,
                      index_sequence<N...>) const
  {
    auto op = equal_to_functor<element_type_t<M>, element_type_t<M>>();
    return ((op(a(N), b(N))) && ...);
  }
}; // struct equal_to_functor

} // namespace primordialmachine
