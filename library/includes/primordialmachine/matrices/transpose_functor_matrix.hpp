#pragma once

#include "primordialmachine/matrices/matrix_default_implementation.hpp"
#include "primordialmachine/matrices/transpose_functor.hpp"

namespace primordialmachine {

template<typename A>
struct transpose_functor<matrix<A>, void>
{
  using operand_type = matrix<A>;
  using B = matrix_traits<typename A::element_type,
                          A::number_of_rows,
                          A::number_of_columns>;
  using result_type = matrix<B>;
  result_type operator()(const operand_type& operand) const
  {
    result_type result;
    apply(result, operand, std::make_index_sequence<A::number_of_elements>{});
    return result;
  }

  static constexpr size_t row(size_t index, size_t stride) noexcept
  {
    return index / stride;
  }

  static constexpr size_t column(size_t index, size_t stride) noexcept
  {
    return index % stride;
  }

  template<size_t... Is>
  void apply(result_type& result,
             const operand_type& operand,
             std::index_sequence<Is...>) const
  {
    int dummy[] = { (
      apply<row(Is, A::number_of_columns), column(Is, A::number_of_columns)>(
        result, operand))... };
  }

  template<size_t ROW, size_t COLUMN>
  constexpr int apply(result_type& result, const operand_type& operand) const
  {
    result(COLUMN, ROW) = operand(ROW, COLUMN);
    return 0;
  }

}; // struct transpose_functor

} // namespace primordialmachine
