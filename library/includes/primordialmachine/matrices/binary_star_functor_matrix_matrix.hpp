///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Matrices Library
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
#include "primordialmachine/matrices/matrix_default_implementation.hpp"

namespace primordialmachine {

// number of columns of first matrix must be equal to number of rows of second matrix.
// the result has the number of rows of the first matrix and the number of columns of the second matrix.
template<typename LEFT_OPERAND_TRAITS, typename RIGHT_OPERAND_TRAITS>
struct binary_star_functor<matrix<LEFT_OPERAND_TRAITS>, matrix<RIGHT_OPERAND_TRAITS>,
                           std::enable_if_t<std::is_same_v<typename LEFT_OPERAND_TRAITS::element_type,
                                                           typename RIGHT_OPERAND_TRAITS::element_type>
                                           && LEFT_OPERAND_TRAITS::number_of_columns == RIGHT_OPERAND_TRAITS::number_of_rows>>
{
  using result_element_type = typename LEFT_OPERAND_TRAITS::element_type;
  using left_operand_type = matrix<LEFT_OPERAND_TRAITS>;
  using right_operand_type = matrix<RIGHT_OPERAND_TRAITS>;
  using result_traits = matrix_traits<result_element_type,
                                      right_operand_type::number_of_columns,
                                      left_operand_type::number_of_rows>;
  using result_type = matrix<result_traits>;
  auto operator()(const left_operand_type& left_operand, const right_operand_type& right_operand) const
  {
    result_type temporary;
    for (size_t i = 0; i < LEFT_OPERAND_TRAITS::number_of_rows; i++) { // i-th row of left operand.
      for (size_t j = 0; j < RIGHT_OPERAND_TRAITS::number_of_columns; j++) { // j-th column of right operand
        for (size_t k = 0; k < LEFT_OPERAND_TRAITS::number_of_columns/*or RIGHT_OPERAND_TRAITS::number_of_rows*/; k++) { // k-th column of first operand, k-th row of second operand
          temporary(i, j) += left_operand(i, k) * right_operand(k, j);
        }
      }
    }
    return temporary;
  }
};

template<typename TRAITS>
auto operator*(matrix<TRAITS> const& u, matrix<TRAITS> const& v)
{
  return binary_star_functor<matrix<TRAITS>, matrix<TRAITS>>()(u, v);
}

template<typename TRAITS>
auto& /*TODO: Does this return a reference? Is this the best method?*/
operator*=(matrix<TRAITS>& u, const matrix<TRAITS>& v)
{
  u = u * v;
  return u;
}

} // namespace primordialmachine
