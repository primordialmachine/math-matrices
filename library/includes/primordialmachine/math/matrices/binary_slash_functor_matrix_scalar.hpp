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
#include "primordialmachine/math/matrices/matrix.hpp"
#include "primordialmachine/math/non_scalars/include.hpp"

namespace primordialmachine {

// Case of a / s where a is of type M and s is of type S.
// M is a matrix type, S is a scalar type.
template<typename M, typename S>
struct binary_slash_functor<M, S, enable_if_t<is_matrix_v<M> && is_scalar_v<S>>>
  : public default_elementwise_binary_slash_functor<M, S>
{}; // struct binary_slash_functor

// Case of a /= b where a and b are of type M.
// M is a matrix type.
template<typename M, typename S>
struct slash_assignment_functor<M,
                                S,
                                enable_if_t<is_matrix_v<M> && is_scalar_v<S>>>
  : public default_elementwise_slash_assignment_functor<M, S>
{}; // struct slash_assignment_functor

} // namespace primordialmachine
