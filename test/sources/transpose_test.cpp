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

TEST(matrices_tests, symmetric_transpose_functor_test)
{
  using namespace primordialmachine;

  using src_matrix_traits = matrix_traits<float, 2, 2>;
  using src_matrix_type = matrix<src_matrix_traits>;

  using dst_matrix_traits = matrix_traits<float, 2, 2>;
  using dst_matrix_type = matrix<src_matrix_traits>;

  src_matrix_type src;
  dst_matrix_type dst;
  dst_matrix_type t;

  // clang-format off
  src = src_matrix_type(0.f, 0.f,
                        0.f, 0.f);
  dst = dst_matrix_type(0.f, 0.f,
                        0.f, 0.f);
  // clang-format on
  t = transpose(src);
  ASSERT_TRUE(t == dst);

  // clang-format off
  src = src_matrix_type(1.f, 0.f,
                        0.f, 1.f);
  dst = dst_matrix_type(1.f, 0.f,
                        0.f, 1.f);
  // clang-format on
  t = transpose(src);
  ASSERT_TRUE(t == dst);

  // clang-format off
  src = src_matrix_type(1.f, 2.f,
                        3.f, 4.f);
  dst = dst_matrix_type(1.f, 3.f,
                        2.f, 4.f);
  // clang-format on
  t = transpose(src);
  ASSERT_TRUE(t == dst);
}

TEST(matrices_tests, asymmetric_transpose_functor_test)
{
  using namespace primordialmachine;

  using src_matrix_traits = matrix_traits<float, 3, 2>;
  using src_matrix_type = matrix<src_matrix_traits>;

  using dst_matrix_traits = matrix_traits<float, 2, 3>;
  using dst_matrix_type = matrix<dst_matrix_traits>;

  src_matrix_type src;
  dst_matrix_type dst;
  dst_matrix_type t;

  // clang-format off
  src = src_matrix_type(0.f, 0.f, 0.f,
                        0.f, 0.f, 0.f);
  dst = dst_matrix_type(0.f, 0.f,
                        0.f, 0.f,
                        0.f, 0.f);
  t = transpose(src);
  // clang-format on
  ASSERT_TRUE(t == dst);

  // clang-format off
  src = src_matrix_type(1.f/*(0.0)->(0.0)*/, 2.f/*(0,1) -> (1.0)*/, 3.f/*(0,2) -> (2.0)*/,
                        4.f/*(1,0)->(0,1)*/, 5.f/*(1,1) -> (1,1)*/, 6.f/*(1,2) -> (2,1)*/);
  dst = dst_matrix_type(1.f, 4.f,
                        2.f, 5.f,
                        3.f, 6.f);
  t = transpose(src);
  // clang-format on
  ASSERT_TRUE(t == dst);
}
