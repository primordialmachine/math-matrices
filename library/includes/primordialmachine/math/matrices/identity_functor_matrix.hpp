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

#include "primordialmachine/math/matrices/identity_functor.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_0.hpp"
#include "primordialmachine/math/matrices/matrix_default_implementation_n.hpp"

namespace primordialmachine {

template<typename A>
struct identity_functor<matrix<A>, std::enable_if_t<A::is_square>>
{
  using result_type = matrix<A>;
  auto operator()() const
  {
    using indices = std::make_index_sequence<A::number_of_elements>;
    return impl(indices{});
  }
  template<typename T>
  constexpr const T& value(size_t i) const
  {
    static const auto ZERO = zero<T>();
    static const auto ONE = one<T>();
    auto x = i % A::number_of_columns;
    auto y = i / A::number_of_columns;
    if (x == y) {
      return ONE;
    } else {
      return ZERO;
    }
  }

  template<size_t... Is>
  auto impl(std::index_sequence<Is...>) const
  {
    return result_type{value<typename A::element_type>(Is) ...};
  }
}; // struct trace_functor

} // namespace primordialmachine
