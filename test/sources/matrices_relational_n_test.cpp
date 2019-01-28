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

using matrix_traits_type = primordialmachine::matrix_traits<float, 2, 2>;
using matrix_type = primordialmachine::matrix<matrix_traits_type>;

TEST(matrices_tests, symmetric_equal_to_matrix_n_test)
{
  using namespace primordialmachine;
  using matrix_traits_type = matrix_traits<float, 2, 2>;
  using matrix_type = matrix<matrix_traits_type>;
  ASSERT_TRUE(matrix_type(4.f, 4.f, 4.f, 4.f) ==
              matrix_type(4.f, 4.f, 4.f, 4.f));
  ASSERT_FALSE(matrix_type(4.f, 4.f, 4.f, 4.f) ==
               matrix_type(2.f, 2.f, 2.f, 2.f));
}

TEST(matrices_tests, asymmetric_equal_to_matrix_n_test)
{
  using namespace primordialmachine;
  using matrix_traits_type = matrix_traits<float, 2, 3>;
  using matrix_type = matrix<matrix_traits_type>;
  ASSERT_TRUE(matrix_type(4.f, 4.f, 4.f, 4.f, 4.f, 4.f) ==
              matrix_type(4.f, 4.f, 4.f, 4.f, 4.f, 4.f));
  ASSERT_FALSE(matrix_type(4.f, 4.f, 4.f, 4.f, 4.f, 4.f) ==
               matrix_type(2.f, 2.f, 2.f, 2.f, 2.f, 2.f));
}

TEST(matrices_tests, not_equal_to_matrix_n_test)
{
  using namespace primordialmachine;
  ASSERT_FALSE(matrix_type(4.f, 4.f, 4.f, 4.f) !=
               matrix_type(4.f, 4.f, 4.f, 4.f));
  ASSERT_TRUE(matrix_type(4.f, 4.f, 4.f, 4.f) !=
              matrix_type(2.f, 2.f, 2.f, 2.f));
}
