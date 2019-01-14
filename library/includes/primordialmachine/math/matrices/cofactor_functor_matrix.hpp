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

#include "primordialmachine/math/matrices/cofactor_functor.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"
#include "primordialmachine/math/matrices/minor_functor.hpp"

namespace primordialmachine {

// Specialization for non-degenerate square matrices.
template<typename M, size_t ROW, size_t COLUMN>
struct cofactor_functor<
  M,
  ROW,
  COLUMN,
  std::enable_if_t<is_matrix<M>::value && M::traits_type::is_non_degenerate &&
                   M::traits_type::is_square &&
                   (ROW < M::traits_type::number_of_rows) &&
                   (COLUMN < M::traits_type::number_of_columns)>>
{
  using result_type = typename M::traits_type::element_type;
  using operand_type = M;
  auto operator()(const operand_type& m) const
  {
    using S = typename M::traits_type::element_type;
    auto sign = ((ROW + COLUMN) % 2 != 0) ? -one<S>() : +one<S>();
    return sign * minor<M, ROW, COLUMN>(m);
  }

}; // struct cofactor_functor

} // namespace primordialmachine
