#pragma once

#include <utility>

namespace primordialmachine {

/* Concatenate two integer_sequence values. */
struct concat_seq
{
  /* Concatenate two integer_sequence values. */
  template<typename T, T... A, T... B>
  static constexpr auto apply(std::integer_sequence<T, A...>,
                              std::integer_sequence<T, B...>)
  {
    return std::integer_sequence<T, A..., B...>{};
  }
}; // struct concat_seq

/* Reverse an integer_sequence. */
struct reverse_seq
{
  template<typename T, T... A>
  static constexpr auto apply(std::integer_sequence<T, A...>)
    -> decltype(std::integer_sequence<T, sizeof...(A) - 1U - A...>{});
}; // struct reverse_seq

/* Filter an integer sequence by a predicate. */
struct filter_seq
{
  template<typename T, T... A, typename P>
  static constexpr auto apply(std::integer_sequence<T, A...>, P p)
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
    return concat_seq::apply(filter(std::integer_sequence<T, a>{}, p),
                             filter(std::integer_sequence<T, b...>{}, p));
  }
}; // struct filter_seq

/* Keep odd elements (0 is even), remove all even elements. */
struct odd_seq
{
  template<typename T, T... A>
  static constexpr auto apply(std::integer_sequence<T, A...>)
  {
    struct predicate
    {
      constexpr bool operator()(T x) const { return x % 2 != 0; }
    };
    return filter_seq::apply(std::integer_sequence<T, (A)...>{}, predicate{});
  }
}; // struct odd_seq

/* Keep even elements (0 is even), remove all odd elements. */
struct even_seq
{
  template<typename T, T... A>
  static constexpr auto apply(std::integer_sequence<T, A...>)
  {
    struct predicate
    {
      constexpr bool operator()(size_t x) const { return x % 2 == 0; }
    };
    return filter_seq::apply(std::integer_sequence<T, (A)...>{}, predicate{});
  }
}; // struct even_seq

} // namespace primordialmachine
