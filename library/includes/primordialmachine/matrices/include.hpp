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

#include "primordialmachine/matrices/adjugate_functor.hpp"
#include "primordialmachine/matrices/determinant_functor.hpp"
#include "primordialmachine/matrices/binary_minus_functor_matrix_matrix.hpp"
#include "primordialmachine/matrices/binary_plus_functor_matrix_matrix.hpp"
#include "primordialmachine/matrices/binary_slash_functor_matrix_matrix.hpp"
#include "primordialmachine/matrices/binary_slash_functor_matrix_scalar.hpp"
#include "primordialmachine/matrices/binary_star_functor_matrix_matrix.hpp"
#include "primordialmachine/matrices/binary_star_functor_matrix_scalar.hpp"
#include "primordialmachine/matrices/equal_to_functor_matrix_matrix.hpp"
#include "primordialmachine/matrices/identity_functor.hpp"
#include "primordialmachine/matrices/inverse_functor.hpp"
#include "primordialmachine/matrices/matrix_default_implementation.hpp"
#include "primordialmachine/matrices/not_equal_to_functor_matrix_matrix.hpp"
#include "primordialmachine/matrices/trace_functor.hpp"
#include "primordialmachine/matrices/transpose_functor.hpp"
#include "primordialmachine/matrices/unary_minus_functor_matrix.hpp"
#include "primordialmachine/matrices/unary_plus_functor_matrix.hpp"
