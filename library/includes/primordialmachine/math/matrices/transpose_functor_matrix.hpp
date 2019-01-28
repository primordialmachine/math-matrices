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
#include "primordialmachine/math/matrices/transpose_functor.hpp"

namespace primordialmachine {

template<typename T>
struct transpose_functor<T, enable_if_t<is_matrix_v<T>>>
{
  using operand_type = T;
  using B = matrix_traits<element_type_t<T>,
                          number_of_rows_v<T>,
                          number_of_columns_v<T>>;
  using result_type = matrix<B>;
  result_type operator()(const operand_type& operand) const
  {
    result_type result;
    apply(result, operand, make_index_sequence<number_of_elements_v<T>>{});
    return result;
  }

  template<size_t... Is>
  void apply(result_type& result,
             const operand_type& operand,
             index_sequence<Is...>) const
  {
    int dummy[] = { (
      apply(result, operand, to_index_2({ Is }, number_of_columns_v<T>)))... };
  }

  constexpr int apply(result_type& result,
                      const operand_type& operand,
                      const index_2& i) const
  {
    result(i.j(), i.i()) = operand(i.i(), i.j());
    return 0;
  }

}; // struct transpose_functor

} // namespace primordialmachine
