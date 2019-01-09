#pragma once

#include "primordialmachine/matrices/integer_sequence.hpp"
#include "primordialmachine/matrices/matrix_default_implementation.hpp"
#include "primordialmachine/matrices/trace_functor.hpp"

namespace primordialmachine {

template<typename T>
struct trace_functor<T, std::enable_if_t<is_matrix<T>::value && T::traits_type::is_square>>
{
  using result_type = typename T::traits_type::element_type;
  using operand_type = T;
  auto operator()(const operand_type& a) const
  {
    struct predicate
    {
      constexpr bool operator()(size_t i) const
      {
        auto t = to_index_2(index_1{i}, T::traits_type::number_of_columns);
        return t.i() == t.j();
      }
    };
    using indices = decltype(filter_seq::apply(
      std::make_index_sequence<T::traits_type::number_of_elements>{}, predicate{}));
    return impl(a, indices{});
  }
  
  template<size_t... Is>
  auto impl(const operand_type& a, std::index_sequence<Is...>) const
  {
    return (a(Is) + ...);
  }
}; // struct trace_functor

} // namespace primordialmachine
