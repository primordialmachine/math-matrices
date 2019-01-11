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

#pragma once

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/scalars/include.hpp"
#include "primordialmachine/matrices/matrix.hpp"
#include "primordialmachine/one_zero_functors/include.hpp"
#include <type_traits>

namespace primordialmachine {

// SFINAE for the struct type.
#pragma push_macro("STRUCT_CONDITION")
#define STRUCT_CONDITION()                                                     \
  std::enable_if_t<(std::is_scalar<typename TRAITS::element_type>::value) &&   \
                   (TRAITS::number_of_columns >= 1) &&                         \
                   (TRAITS::number_of_rows >= 1)>

// SFINAE for the constructor.
#pragma push_macro("CONSTRUCTOR_CONDITION_1")
#define CONSTRUCTOR_CONDITION_1(_NUMBER_OF_ARGUMENTS)                          \
  ((1 + sizeof...(ARGUMENTS)) == _NUMBER_OF_ARGUMENTS)

#pragma push_macro("CONSTRUCTOR_CONDITION_2")
#define CONSTRUCTOR_CONDITION_2()                                              \
  (std::is_convertible_v<                                                      \
    std::decay_t<ARGUMENT>,                                                    \
    typename TRAITS::element_type>)&&(... &&                                   \
                                      std::is_convertible_v<                   \
                                        std::decay_t<ARGUMENTS>,               \
                                        typename TRAITS::element_type>)

#pragma push_macro("CONSTRUCTOR_CONDITION")
#define CONSTRUCTOR_CONDITION()                                                \
  std::enable_if_t<CONSTRUCTOR_CONDITION_1(TRAITS::number_of_elements) &&      \
                   CONSTRUCTOR_CONDITION_2()>

template<typename TRAITS>
struct is_matrix<matrix<TRAITS>>
{
  static constexpr bool value = true;
};

template<typename TRAITS>
struct matrix<TRAITS, STRUCT_CONDITION()>
{
  using traits_type = TRAITS;
  using element_type = typename TRAITS::element_type; /*TODO: Remove this.*/
  static constexpr size_t number_of_rows =
    TRAITS::number_of_rows; /*TODO: Remove this.*/
  static constexpr size_t number_of_columns =
    TRAITS::number_of_columns; /*TODO: Remove this.*/
  static constexpr size_t number_of_elements =
    TRAITS::number_of_elements; /*TODO: Remove this.*/

  matrix();

  template<typename ARGUMENT,
           typename... ARGUMENTS,
           typename ENABLED = CONSTRUCTOR_CONDITION()>
  matrix(ARGUMENT&& argument, ARGUMENTS&&... arguments);

  element_type const& operator()(size_t i) const;
  element_type& operator()(size_t i);

  element_type const& operator()(size_t i, size_t j) const;
  element_type& operator()(size_t i, size_t j);

  element_type* data();
  element_type const* data() const;

private:
  union
  {
    typename TRAITS::element_type m_elements_2d[TRAITS::number_of_rows]
                                               [TRAITS::number_of_columns];
    typename TRAITS::element_type m_elements_1d[TRAITS::number_of_elements];
  };
};

#pragma push_macro("TYPE")
#define TYPE matrix<TRAITS, STRUCT_CONDITION()>

template<typename TRAITS>
TYPE::matrix()
  : m_elements_1d{}
{
  std::fill_n(
    m_elements_1d, number_of_elements, zero<typename TRAITS::element_type>());
}

template<typename TRAITS>
template<typename ARGUMENT, typename... ARGUMENTS, typename ENABLED>
TYPE::matrix(ARGUMENT&& argument, ARGUMENTS&&... arguments)
  : m_elements_1d{ static_cast<typename TRAITS::element_type>(argument),
                   static_cast<typename TRAITS::element_type>(arguments)... }
{}

template<typename TRAITS>
typename TRAITS::element_type const&
TYPE::operator()(size_t i) const
{
  return m_elements_1d[i];
}

template<typename TRAITS>
typename TRAITS::element_type&
TYPE::operator()(size_t i)
{
  return m_elements_1d[i];
}

template<typename TRAITS>
typename TRAITS::element_type const&
TYPE::operator()(size_t i, size_t j) const
{
  return m_elements_2d[i][j];
}

template<typename TRAITS>
typename TRAITS::element_type&
TYPE::operator()(size_t i, size_t j)
{
  return m_elements_2d[i][j];
}

template<typename TRAITS>
typename TRAITS::element_type const*
TYPE::data() const
{
  return m_elements_1d;
}

template<typename TRAITS>
typename TRAITS::element_type*
TYPE::data()
{
  return m_elements_1d;
}

#undef TYPE
#pragma pop_macro("TYPE")

#undef CONSTRUCTOR_CONDITION_2
#pragma pop_macro("CONSTRUCTOR_CONDITION_2")

#undef CONSTRUCTOR_CONDITION_1
#pragma pop_macro("CONSTRUCTOR_CONDITION_1")

#undef CONSTRUCTOR_CONDITION
#pragma pop_macro("CONSTRUCTOR_CONDITION")

#undef STRUCT_CONDITION
#pragma pop_macro("STRUCT_CONDITION")

template<typename TRAITS, typename OPERATOR>
using elementwise_unary_matrix_functor =
  elementwise_unary_functor<matrix<TRAITS>,
                            matrix<TRAITS>,
                            TRAITS::number_of_elements,
                            OPERATOR,
                            void>;

template<typename TRAITS, typename OPERATOR>
using elementwise_binary_matrix_functor =
  elementwise_binary_functor<matrix<TRAITS>,
                             matrix<TRAITS>,
                             matrix<TRAITS>,
                             TRAITS::number_of_elements,
                             OPERATOR,
                             void>;

} // namespace primordialmachine
