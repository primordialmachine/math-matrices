#pragma once

#include "primordialmachine/matrices/integer_sequence.hpp"
#include "primordialmachine/matrices/matrix_default_implementation.hpp"
#include "primordialmachine/matrices/trace_functor.hpp"

namespace primordialmachine {

template<typename A>
struct trace_functor<matrix<A>, std::enable_if_t<A::is_square>>
{
  using result_type = typename A::element_type;
  using operand_type = matrix<A>;
  auto operator()(const operand_type& a) const
  {
    struct predicate
    {
      constexpr bool operator()(size_t i) const
      {
        auto x = i % A::number_of_columns;
        auto y = i / A::number_of_columns;
        return x == y;
      }
    };
    using indices = decltype(filter_seq::apply(
      std::make_index_sequence<A::number_of_elements>{}, predicate{}));
    return impl(a, indices{});
  }
  
  template<size_t... Is>
  auto impl(const operand_type& a, std::index_sequence<Is...>) const
  {
    return (a(Is) + ...);
  }
}; // struct trace_functor

} // namespace primordialmachine
