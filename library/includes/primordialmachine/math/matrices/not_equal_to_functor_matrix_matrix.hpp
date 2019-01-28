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

template<typename T>
struct not_equal_to_functor<T,
                            T,
                            enable_if_t<is_matrix_v<T> && is_degenerate_v<T>>>
{
  using left_operand_type = T;
  using right_operand_type = T;
  using result_type = bool;
  result_type operator()(const left_operand_type& a,
                         const right_operand_type& b) const
  {
    return false;
  }
};

template<typename T>
struct not_equal_to_functor<
  T,
  T,
  enable_if_t<is_matrix_v<T> && is_non_degenerate_v<T>>>
{
  using left_operand_type = T;
  using right_operand_type = T;
  using result_type = bool;
  result_type operator()(const left_operand_type& a,
                         const right_operand_type& b) const
  {
    return impl(a, b, make_index_sequence<number_of_elements_v<T>>());
    return true;
  }

  template<size_t... N>
  constexpr bool impl(const left_operand_type& a,
                      const right_operand_type& b,
                      index_sequence<N...>) const
  {
    auto op = not_equal_to_functor<element_type_t<T>, element_type_t<T>>();
    return ((op(a(N), b(N))) || ...);
  }
};

} // namespace primordialmachine
