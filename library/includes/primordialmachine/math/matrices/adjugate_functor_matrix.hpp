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
#include "primordialmachine/math/matrices/cofactor_matrix_functor.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"
#include "primordialmachine/math/matrices/transpose_functor.hpp"

namespace primordialmachine {

template<typename M>
struct adjugate_functor<
  M,
  enable_if_t<is_matrix_v<M> && is_non_degenerate_v<M> &&
              is_square_v<M>>>
{
  using cofactor_matrix_functor_type = cofactor_matrix_functor<M>;
  using transpose_functor_type =
    transpose_functor<result_type_t<cofactor_matrix_functor_type>>;
  using result_type = result_type_t<transpose_functor_type>;
  using operand_type = M;
  auto operator()(const operand_type& m) const
  {
    return transpose_functor_type()(cofactor_matrix_functor_type()(m));
  }
}; // struct adjugate_functor

} // namespace primordialmachine
