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

#include "primordialmachine/math/matrices/matrix.hpp"
#include "primordialmachine/math/matrices/trace_functor.hpp"

namespace primordialmachine {

template<typename T>
struct trace_functor<
  T,
  enable_if_t<is_matrix_v<T> && is_non_degenerate_v<T> && is_square_v<T>>>
{
  using result_type = element_type_t<T>;
  using operand_type = T;
  auto operator()(const operand_type& a) const
  {
    struct predicate
    {
      constexpr bool operator()(size_t i) const
      {
        auto t = to_index_2(index_1{ i }, number_of_columns_v<T>);
        return t.i() == t.j();
      }
    };
    using indices =
      decltype(filter_seq(make_element_indices<T>{}, predicate{}));
    return impl(a, indices{});
  }

  template<size_t... Is>
  auto impl(const operand_type& a, index_sequence<Is...>) const
  {
    return (a(Is) + ...);
  }
}; // struct trace_functor

} // namespace primordialmachine
