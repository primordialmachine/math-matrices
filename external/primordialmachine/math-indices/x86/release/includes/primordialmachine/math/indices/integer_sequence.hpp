///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Indices Library
// Copyright (C) 2019 Michael Heilmann
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

#include <utility>

namespace primordialmachine {

/* Concatenate two integer_sequence values. */
struct concat_seq
{
  /* Concatenate two integer_sequence values. */
  template<typename T, T... A, T... B>
  constexpr auto operator()(std::integer_sequence<T, A...>,
                            std::integer_sequence<T, B...>) const
    -> decltype(std::integer_sequence<T, A..., B...>{});
}; // struct concat_seq

/* Reverse an integer_sequence. */
struct reverse_seq
{
  template<typename T, T... A>
  constexpr auto operator()(std::integer_sequence<T, A...>) const
    -> decltype(std::integer_sequence<T, sizeof...(A) - 1U - A...>{});
}; // struct reverse_seq

/* Filter an integer sequence by a predicate. */
struct filter_seq
{
  template<typename T, T... A, typename P>
  constexpr auto operator()(std::integer_sequence<T, A...>, P p) const
  {
    return filter(std::integer_sequence<T, (A)...>{}, p);
  }

  // case of a sequence of length 0.
  template<typename T, typename P>
  static constexpr auto filter(std::integer_sequence<T>, P p)
  {
    return std::integer_sequence<T>{};
  }

  // case of a sequence of length 1.
  template<typename T, T a, typename P>
  static constexpr auto filter(std::integer_sequence<T, a>, P p)
  {
    if constexpr (p(a))
      return std::integer_sequence<T, a>{};
    else
      return std::integer_sequence<T>{};
  }

  // recursive case.
  template<class T, T a, T... b, typename P>
  static constexpr auto filter(std::integer_sequence<T, a, b...>, P p)
  {
    return concat_seq()(filter(std::integer_sequence<T, a>{}, p),
                        filter(std::integer_sequence<T, b...>{}, p));
  }
}; // struct filter_seq

/* Keep odd elements (0 is even), remove all even elements. */
struct odd_seq
{
  template<typename T, T... A>
  constexpr auto operator()(std::integer_sequence<T, A...>) const
  {
    struct predicate
    {
      constexpr bool operator()(T x) const { return x % 2 != 0; }
    };
    return filter_seq()(std::integer_sequence<T, (A)...>{}, predicate{});
  }
}; // struct odd_seq

/* Keep even elements (0 is even), remove all odd elements. */
struct even_seq
{
  template<typename T, T... A>
  constexpr auto operator()(std::integer_sequence<T, A...>) const
  {
    struct predicate
    {
      constexpr bool operator()(size_t x) const { return x % 2 == 0; }
    };
    return filter_seq()(std::integer_sequence<T, (A)...>{}, predicate{});
  }
}; // struct even_seq

} // namespace primordialmachine
