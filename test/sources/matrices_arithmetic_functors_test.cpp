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

#include "primordialmachine/matrices/include.hpp"
#include "gtest/gtest.h"

using matrix_traits = primordialmachine::matrix_traits<float, 2, 2>;
using matrix_type = primordialmachine::matrix<matrix_traits>;

TEST(matrices_tests, matrix_default_constructor_test)
{
  using namespace primordialmachine;
  matrix_type();
}

TEST(matrices_tests, matrix_constructor_test)
{
  using namespace primordialmachine;
  matrix_type(0.f, 1.f, 2.f, 3.f);
}

TEST(matrices_tests, binary_plus_matrix_matrix)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(6.f, 6.f, 6.f, 6.f) ==
    matrix_type(4.f, 4.f, 4.f, 4.f) + matrix_type(2.f, 2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}

TEST(matrices_tests, plus_assignment_matrix_matrix_test)
{
  using namespace primordialmachine;
  auto lhs = matrix_type(4.f, 4.f, 4.f, 4.f);
  lhs += matrix_type(2.f, 2.f, 2.f, 2.f);
  auto result = matrix_type(6.f, 6.f, 6.f, 6.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(matrices_tests, binary_minus_matrix_matrix_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(2.f, 2.f, 2.f, 2.f) ==
    matrix_type(4.f, 4.f, 4.f, 4.f) - matrix_type(2.f, 2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}

TEST(matrices_tests, minus_assignment_matrix_matrix__test)
{
  using namespace primordialmachine;
  auto lhs = matrix_type(4.f, 4.f, 4.f, 4.f);
  lhs -= matrix_type(2.f, 2.f, 2.f, 2.f);
  auto result = matrix_type(2.f, 2.f, 2.f, 2.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(matrices_tests, binary_star_matrix_matrix_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(1.f, 0.f, 1.f, 0.f) ==
    matrix_type(1.f, 0.f, 1.f, 0.f) * matrix_type(1.f, 0.f, 1.f, 0.f);
  ASSERT_TRUE(result);
}

TEST(matrices_tests, binary_slash_matrix_matrix_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(2.f, 2.f, 2.f, 2.f) ==
    matrix_type(4.f, 4.f, 4.f, 4.f) / matrix_type(2.f, 2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}

TEST(matrices_tests, slash_assignment_matrix_matrix_test)
{
  using namespace primordialmachine;
  auto lhs = matrix_type(4.f, 4.f, 4.f, 4.f);
  lhs /= matrix_type(2.f, 2.f, 2.f, 2.f);
  auto result = matrix_type(2.f, 2.f, 2.f, 2.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(matrices_tests, unary_plus_matrix_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(4.f, 4.f, 4.f, 4.f) == +matrix_type(4.f, 4.f, 4.f, 4.f);
  ASSERT_TRUE(result);
}

TEST(matrices_tests, unary_minus_matrix_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(-4.f, -4.f, -4.f, -4.f) == -matrix_type(4.f, 4.f, 4.f, 4.f);
  ASSERT_TRUE(result);
}

TEST(matrices_tests, binary_star_matrix_scalar_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(8.f, 8.f, 8.f, 8.f) == matrix_type(4.f, 4.f, 4.f, 4.f) * 2.f;
  ASSERT_TRUE(result);
}

TEST(matrices_tests, star_assignment_matrix_scalar_test)
{
  using namespace primordialmachine;
  auto lhs = matrix_type(4.f, 4.f, 4.f, 4.f);
  lhs *= 2.f;
  auto result = matrix_type(8.f, 8.f, 8.f, 8.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(matrices_tests, binary_star_scalar_matrix_test)
{
  using namespace primordialmachine;
  auto lhs = matrix_type(8.f, 8.f, 8.f, 8.f);
  auto rhs = 2.f * matrix_type(4.f, 4.f, 4.f, 4.f);
  auto result = lhs == rhs;
  ASSERT_TRUE(result);
}

TEST(matrices_tests, binary_slash_matrix_scalar_test)
{
  using namespace primordialmachine;
  auto result =
    matrix_type(2.f, 2.f, 2.f, 2.f) == matrix_type(4.f, 4.f, 4.f, 4.f) / 2.f;
  ASSERT_TRUE(result);
}
TEST(matrices_tests, slash_assignment_matrix_scalar_test)
{
  using namespace primordialmachine;
  auto lhs = matrix_type(4.f, 4.f, 4.f, 4.f);
  lhs /= 2.f;
  auto result = matrix_type(2.f, 2.f, 2.f, 2.f) == lhs;
  ASSERT_TRUE(result);
}
