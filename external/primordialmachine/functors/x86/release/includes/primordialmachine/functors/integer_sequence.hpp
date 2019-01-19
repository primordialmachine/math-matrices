///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Functors Library
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

// Alias for std::size_t.
using size_t = std::size_t;

// Alias for std::integer_sequence.
template<typename T, T... Integers>
using integer_sequence = std::integer_sequence<T, Integers...>;

// Alias for std::make_integer_sequence.
template<typename T, T N>
using make_integer_sequence = std::make_integer_sequence<T, N>;

// Alias for std::index_sequence.
template<size_t... Indices>
using index_sequence = std::integer_sequence<size_t, Indices...>;

// Alias for std::make_index_sequence.
template<size_t N>
using make_index_sequence = std::make_index_sequence<N>;

// Concatenate two integer_sequence values.
struct concat_seq_impl
{
  /* Concatenate two integer_sequence values. */
  template<typename T, T... A, T... B>
  constexpr auto operator()(integer_sequence<T, A...>,
                            integer_sequence<T, B...>) const
    -> decltype(integer_sequence<T, A..., B...>{});
}; // struct concat_seq_impl

template<typename T, T... A, T... B>
constexpr auto
concat_seq(integer_sequence<T, A...> a, integer_sequence<T, B...> b)
  -> decltype(concat_seq_impl()(a, b))
{
  return concat_seq_impl()(a, b);
}

// Reverse an integer_sequence.
struct reverse_seq_impl
{
  template<typename T, T... A>
  constexpr auto operator()(integer_sequence<T, A...>) const
    -> decltype(integer_sequence<T, sizeof...(A) - 1U - A...>{});
}; // struct reverse_seq_impl

template<typename T, T... A>
constexpr auto
reverse_seq(integer_sequence<T, A...> a) -> decltype(reverse_seq_impl()(a))
{
  return reverse_seq_impl()(a);
}

// Filter an integer sequence by a predicate.
struct filter_seq_impl
{
  template<typename T, T... A, typename P>
  constexpr auto operator()(integer_sequence<T, A...>, P p) const
  {
    return filter(integer_sequence<T, (A)...>{}, p);
  }

private:
  // case of a sequence of length 0.
  template<typename T, typename P>
  static constexpr auto filter(integer_sequence<T>, P p)
  {
    return integer_sequence<T>{};
  }

  // case of a sequence of length 1.
  template<typename T, T a, typename P>
  static constexpr auto filter(integer_sequence<T, a>, P p)
  {
    if constexpr (p(a))
      return integer_sequence<T, a>{};
    else
      return integer_sequence<T>{};
  }

  // recursive case.
  template<class T, T a, T... b, typename P>
  static constexpr auto filter(integer_sequence<T, a, b...>, P p)
  {
    return concat_seq(filter(integer_sequence<T, a>{}, p),
                      filter(integer_sequence<T, b...>{}, p));
  }
}; // struct filter_seq_impl

template<typename T, T... A, typename P>
constexpr auto
filter_seq(integer_sequence<T, A...> a, P p)
  -> decltype(filter_seq_impl()(a, p))
{
  return filter_seq_impl()(a, p);
}

// Keep odd elements (0 is even), remove all even elements.
struct odd_seq_impl
{
  template<typename T, T... A>
  constexpr auto operator()(integer_sequence<T, A...>) const
  {
    struct predicate
    {
      constexpr bool operator()(T x) const { return x % 2 != 0; }
    };
    return filter_seq(integer_sequence<T, (A)...>{}, predicate{});
  }
}; // struct odd_seq_impl

template<typename T, T... A>
constexpr auto
odd_seq(integer_sequence<T, A...> a) -> decltype(odd_seq_impl()(a))
{
  return odd_seq_impl()(a);
}

// Keep even elements (0 is even), remove all odd elements.
struct even_seq_impl
{
  template<typename T, T... A>
  constexpr auto operator()(integer_sequence<T, A...>) const
  {
    struct predicate
    {
      constexpr bool operator()(size_t x) const { return x % 2 == 0; }
    };
    return filter_seq(integer_sequence<T, (A)...>{}, predicate{});
  }
}; // struct even_seq_impl

template<typename T, T... A>
constexpr auto
even_seq(integer_sequence<T, A...> a) -> decltype(even_seq_impl()(a))
{
  return even_seq_impl()(a);
}

} // namespace primordialmachine
