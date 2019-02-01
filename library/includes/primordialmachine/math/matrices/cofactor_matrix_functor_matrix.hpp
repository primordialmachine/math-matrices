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

#include "primordialmachine/math/matrices/cofactor_functor.hpp"
#include "primordialmachine/math/matrices/cofactor_matrix_functor.hpp"
#include "primordialmachine/math/matrices/matrix.hpp"

namespace primordialmachine {

// Specialization for non-degenerate square matrices.
template<typename M>
struct cofactor_matrix_functor<
  M,
  enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M> && is_square_v<M>>>
{
  using result_type = M;
  using operand_type = M;
  auto operator()(const operand_type& m) const
  {
    using indices_type = make_element_indices<M>;
    return impl0(m, indices_type{});
  }

  template<size_t... Is>
  static auto impl0(const operand_type& m, index_sequence<Is...>)
  {
    return result_type{ (impl1<Is>(m))... };
  }

  template<size_t I>
  constexpr static auto impl1(const operand_type& m)
  {
    constexpr auto t = to_index_2(index_1{ I }, number_of_columns_v<M>);
    return cofactor<M, t.i(), t.j()>(m);
  }

}; // struct cofactor_matrix_functor

} // namespace primordialmachine
