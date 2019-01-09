#pragma once

#include "primordialmachine/matrices/matrix_default_implementation.hpp"
#include "primordialmachine/matrices/transpose_functor.hpp"

namespace primordialmachine {

template<typename T>
struct transpose_functor<T, std::enable_if_t<is_matrix<T>::value>>
{
  using operand_type = T;
  using B = matrix_traits<typename T::traits_type::element_type,
                          T::traits_type::number_of_rows,
                          T::traits_type::number_of_columns>;
  using result_type = matrix<B>;
  result_type operator()(const operand_type& operand) const
  {
    result_type result;
    apply(result, operand, std::make_index_sequence<T::traits_type::number_of_elements>{});
    return result;
  }

  template<size_t... Is>
  void apply(result_type& result,
             const operand_type& operand,
             std::index_sequence<Is...>) const
  {
    int dummy[] = { (
      apply(result, operand, to_index_2({Is}, T::traits_type::number_of_columns)))... };
  }
  
  constexpr int apply(result_type& result, const operand_type& operand, const index_2& i) const
  {
    result(i.j(), i.i()) = operand(i.i(), i.j());
    return 0;
  }

}; // struct transpose_functor

} // namespace primordialmachine
