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
// number of columns of first matrix must be equal to number of rows of second
// matrix. the result has the number of rows of the first matrix and the number
// of columns of the second matrix.
template<typename A, typename B>
struct binary_star_functor<
  A,
  B,
  enable_if_t<is_matrix_v<A> && is_matrix_v<B> && is_degenerate_v<A> &&
              is_degenerate_v<B> &&
              is_same_v<element_type_t<A>, element_type_t<B>> &&
              number_of_columns_v<A> == number_of_rows_v<B>>>
{
  using result_element_type = element_type_t<A>;
  using left_operand_type = A;
  using right_operand_type = B;
  // "Die Zeilenzahl (row count) der Ergebnismatrix entspricht derjenigen der
  // ersten Matrix," "ihre Spaltenzahl (column count) derjenigen der zweiten
  // Matrix".
  using result_traits = matrix_traits<result_element_type,
                                      number_of_columns_v<B>,
                                      number_of_rows_v<A>>;
  using result_type = matrix<result_traits>;
  result_type operator()(const left_operand_type& left_operand,
                         const right_operand_type& right_operand) const
  {
    return result_type();
  }
}; // struct binary_star_functor

// non-degenerated case
// number of columns of first matrix must be equal to number of rows of second
// matrix. the result has the number of rows of the first matrix and the number
// of columns of the second matrix.
template<typename A, typename B>
struct binary_star_functor<
  A,
  B,
  enable_if_t<is_matrix_v<A> && is_matrix_v<B> && is_non_degenerate_v<A> &&
              is_non_degenerate_v<B> &&
              is_same_v<element_type_t<A>, element_type_t<B>> &&
              number_of_columns_v<A> == number_of_rows_v<B>>>
{
  using result_element_type = element_type_t<A>;
  using left_operand_type = A;
  using right_operand_type = B;
  // "Die Zeilenzahl (row count) der Ergebnismatrix entspricht derjenigen der
  // ersten Matrix," "ihre Spaltenzahl (column count) derjenigen der zweiten
  // Matrix".
  using result_traits = matrix_traits<result_element_type,
                                      number_of_columns_v<B>,
                                      number_of_rows_v<A>>;
  using result_type = matrix<result_traits>;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    result_type temporary;
    for (size_t i = 0; i < number_of_rows_v<left_operand_type>;
         i++) { // i-th row of left operand.
      for (size_t j = 0; j < number_of_columns_v<right_operand_type>;
           j++) { // j-th column of right operand
        for (size_t k = 0;
             k < number_of_columns_v<left_operand_type> /*or
                                        number_of_rows_v<right_operand_type>*/
             ;
             k++) { // k-th column of first operand, k-th row of second operand
          temporary(i, j) += left_operand(i, k) * right_operand(k, j);
        }
      }
    }
    return temporary;
  }
}; // struct binary_star_functor

template<typename M>
struct star_assignment_functor<
  M,
  M,
  enable_if_t<is_matrix_v<M> && is_degenerate_v<M>>>
{
  using left_operand_type = M;
  using right_operand_type = M;
  using result_type = M;
  result_type& operator()(left_operand_type& left_operand,
                          const right_operand_type& right_operand) const
  {
    return left_operand;
  }
}; // struct star_assignment_functor

template<typename M>
struct star_assignment_functor<
  M,
  M,
  enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M> && is_square_v<M>>>
{
  using left_operand_type = M;
  using right_operand_type = M;
  using result_type = M;
  result_type& operator()(left_operand_type& left_operand,
                          const right_operand_type& right_operand) const
  {
    left_operand = left_operand * right_operand;
    return left_operand;
  }
}; // struct star_assignment_functor

} // namespace primordialmachine
