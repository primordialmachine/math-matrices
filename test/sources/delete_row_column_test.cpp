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

#include "primordialmachine/math/matrices/include.hpp"
#include "gtest/gtest.h"

using namespace primordialmachine;

static_assert(is_matrix<matrix<matrix_traits<float, 3, 3>>>::value,
              "not a matrix type");

using matrix_traits_type = matrix_traits<float, 3, 3>;
using matrix_type = matrix<matrix_traits_type>;

#define STATIC_ASSERT(expr)                                                    \
  static_assert(expr, "static assertion `" #expr " failed")

TEST(matrices_tests, delete_column_row_test)
{
  // clang-format off
  auto a = matrix_type(1.f, 2.f, 3.f,
                       4.f, 5.f, 6.f,
                       7.f, 8.f, 9.f);
  // clang-format on
  using A = delete_column_view<matrix_type, 1>;
  using B = delete_row_view<A, 1>;
  auto x = A(a);
  auto t = B(x);
  STATIC_ASSERT(number_of_rows_v<B> == 2);
  STATIC_ASSERT(number_of_columns_v<B> == 2);
  STATIC_ASSERT(is_matrix_v<B>);
  ASSERT_TRUE(t(0, 0) == 1.f);
  ASSERT_TRUE(t(0, 1) == 3.f);
  ASSERT_TRUE(t(1, 0) == 7.f);
  ASSERT_TRUE(t(1, 1) == 9.f);
}

TEST(matrices_tests, delete_row_column_test)
{
  // clang-format off
  auto a = matrix_type(1.f, 2.f, 3.f,
                       4.f, 5.f, 6.f,
                       7.f, 8.f, 9.f);
  // clang-format on
  using A = delete_row_view<matrix_type, 1>;
  using B = delete_column_view<A, 1>;
  auto x = A(a);
  auto t = B(x);
  STATIC_ASSERT(number_of_rows_v<B> == 2);
  STATIC_ASSERT(number_of_columns_v<B> == 2);
  STATIC_ASSERT(is_matrix_v<B>);
  ASSERT_TRUE(t(0, 0) == 1.f);
  ASSERT_TRUE(t(0, 1) == 3.f);
  ASSERT_TRUE(t(1, 0) == 7.f);
  ASSERT_TRUE(t(1, 1) == 9.f);
}