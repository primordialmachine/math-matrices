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

// degenerated case
// number of columns of first matrix must be equal to number of rows of second
// matrix. the result has the number of rows of the first matrix and the number
// of columns of the second matrix.
template<typename A, typename B>
struct binary_star_functor<
  A,
  B,
  std::enable_if_t<
    is_matrix<A>::value && is_matrix<B>::value &&
    A::traits_type::is_degenerate && B::traits_type::is_degenerate &&
    std::is_same_v<typename A::traits_type::element_type,
                   typename B::traits_type::element_type> &&
    A::traits_type::number_of_columns == B::traits_type::number_of_rows>>
{
  using result_element_type = typename A::traits_type::element_type;
  using left_operand_type = A;
  using right_operand_type = B;
  using result_traits = matrix_traits<result_element_type,
                                      A::traits_type::number_of_columns,
                                      B::traits_type::number_of_rows>;
  using result_type = matrix<result_traits>;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return result_type();
  }
};

// non-degenerated case
// number of columns of first matrix must be equal to number of rows of second
// matrix. the result has the number of rows of the first matrix and the number
// of columns of the second matrix.
template<typename A, typename B>
struct binary_star_functor<
  A,
  B,
  std::enable_if_t<is_matrix<A>::value &&
                   is_matrix<B>::value &&
                   A::traits_type::is_non_degenerate &&
                   B::traits_type::is_non_degenerate &&
                   std::is_same_v<typename A::traits_type::element_type,
                                  typename B::traits_type::element_type> &&
                   A::traits_type::number_of_columns ==
                   B::traits_type::number_of_rows>>
{
  using result_element_type = typename A::traits_type::element_type;
  using left_operand_type = A;
  using right_operand_type = B;
  using result_traits = matrix_traits<result_element_type,
                                      A::traits_type::number_of_columns,
                                      B::traits_type::number_of_rows>;
  using result_type = matrix<result_traits>;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    result_type temporary;
    for (size_t i = 0; i < left_operand_type::traits_type::number_of_rows;
         i++) { // i-th row of left operand.
      for (size_t j = 0; j < right_operand_type::traits_type::number_of_columns;
           j++) { // j-th column of right operand
        for (
          size_t k = 0;
          k <
          left_operand_type::traits_type::
            number_of_columns /*or
                                 right_operand_type::traits_type::number_of_rows*/
          ;
          k++) { // k-th column of first operand, k-th row of second operand
          temporary(i, j) += left_operand(i, k) * right_operand(k, j);
        }
      }
    }
    return temporary;
  }
};

template<typename TRAITS>
auto& /*TODO: Does this return a reference? Is this the best method?*/
operator*=(matrix<TRAITS>& u, const matrix<TRAITS>& v)
{
  u = u * v;
  return u;
}

} // namespace primordialmachine
