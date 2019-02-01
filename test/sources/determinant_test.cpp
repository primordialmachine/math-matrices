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

#include "primordialmachine/math/matrices/include.hpp"
#include "gtest/gtest.h"

using namespace primordialmachine;

using scalar_type = float;
template<size_t D>
using matrix_type = matrix<matrix_traits<scalar_type, D, D>>;

#define STATIC_ASSERT(expr)                                                    \
  static_assert(expr, "static assertion `" #expr " failed")

template<size_t DIMENSIONALITY>
static void
check();

template<size_t DIMENSIONALITY>
static void
check()
{
  scalar_type d;
  // clang-format off
  d = determinant(matrix_type<DIMENSIONALITY>());
  ASSERT_FLOAT_EQ(zero<float>(), d);
  d = determinant(identity<matrix_type<DIMENSIONALITY>>());
  ASSERT_FLOAT_EQ(one<float>(), d);
  // clang-format on
}

TEST(matrices_tests, determinant_0_0)
{
  scalar_type d;
  //
  d = determinant(matrix_type<0>());
  ASSERT_FLOAT_EQ(1.f, d);
  //
  check<1>();
  d = determinant(matrix_type<1>(7.f));
  ASSERT_FLOAT_EQ(7.f, d);
  // clang-format off
  check<2>();
  d = determinant(matrix_type<2>(7.f, 2.f,
                                 3.f, 5.f));
  ASSERT_FLOAT_EQ(29.f, d);
  //
  check<3>();
  // m_00 (m11 * m22 - m12 * m21)
  d = determinant(matrix_type<3>(7.f,   2.f,  3.f,
                                 5.f,  11.f, 13.f,
                                 17.f, 19.f, 23.f));
  ASSERT_FLOAT_EQ(7.f * (11.f * 23.f - 13.f * 19.f) -
                  2.f * ( 5.f * 23.f - 13.f * 17.f)  +
                  3.f * ( 5.f * 19.f - 11.f * 17.f), d);
  // clang-format on
}
