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
#include <type_traits>

TEST(integer_sequence_tests, concat_seq_test)
{
  using namespace primordialmachine;
  using u = std::index_sequence<0, 1, 2, 0, 1, 2, 3>;
  using v = decltype(concat_seq::apply<size_t>(std::make_index_sequence<3>(),
                                               std::make_index_sequence<4>{}));
  static_assert(std::is_same_v<u, v>);
}

TEST(integer_sequence_tests, reverse_seq_test)
{
  using namespace primordialmachine;
  using u = std::index_sequence<3, 2, 1, 0>;
  using v = decltype(reverse_seq::apply<size_t>(std::make_index_sequence<4>{}));
  static_assert(std::is_same_v<u, v>);
}

TEST(integer_sequence_tests, even_seq_test)
{
  using namespace primordialmachine;
  using u = std::index_sequence<0, 2>;
  using v = decltype(even_seq::apply<size_t>(std::make_index_sequence<4>{}));
  static_assert(std::is_same_v<u, v>);
}

TEST(integer_sequence_tests, odd_seq_test)
{
  using namespace primordialmachine;
  using u = std::index_sequence<1, 3>;
  using v = decltype(odd_seq::apply<size_t>(std::make_index_sequence<4>{}));
  static_assert(std::is_same_v<u, v>);
}

TEST(integer_sequence_tests, filter_seq_test)
{
  using namespace primordialmachine;
  using u = std::index_sequence<1, 3>;
  struct predicate
  {
    constexpr bool operator()(size_t x) const { return x % 2 != 0; }
  };
  using v =
    decltype(filter_seq::apply(std::make_index_sequence<4>{}, predicate{}));
  static_assert(std::is_same_v<u, v>);
}
