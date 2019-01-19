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

#include "primordialmachine/math/matrices/adjugate_functor.hpp"
#include "primordialmachine/math/matrices/inverse_functor.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"

namespace primordialmachine {

// Specialization for non-degenerate square matrices.
template<typename M>
struct inverse_functor<
  M,
  enable_if_t<is_matrix_v<M> && is_square_v<M> &&
              (number_of_rows_v<M> > 0) &&
              (number_of_columns_v<M> > 0)>>
{
  using scalar_type = element_type_t<M>;
  using result_type = M;
  using operand_type = M;
  auto operator()(const operand_type& m) const
  {
    return (one<scalar_type>() / determinant(m)) * adjugate(m);
  }
}; // struct inverse_functor

} // namespace primordialmachine
