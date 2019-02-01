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
#include "primordialmachine/math/matrices/matrix.hpp"
#include "primordialmachine/math/matrices/minor_functor.hpp"

namespace primordialmachine {

// Specialization for non-degenerate square matrices.
template<typename M, size_t ROW, size_t COLUMN>
struct cofactor_functor<
  M,
  ROW,
  COLUMN,
  enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M> &&
              is_square_v<M> && (ROW < number_of_rows_v<M>) &&
              (COLUMN < number_of_columns_v<M>)>>
{
  using result_type = element_type_t<M>;
  using operand_type = M;
  auto operator()(const operand_type& m) const
  {
    using S = element_type_t<M>;
    auto sign = ((ROW + COLUMN) % 2 != 0) ? -one<S>() : +one<S>();
    return sign * minor<M, ROW, COLUMN>(m);
  }

}; // struct cofactor_functor

} // namespace primordialmachine
