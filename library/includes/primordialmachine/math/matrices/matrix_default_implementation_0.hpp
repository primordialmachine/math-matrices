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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/matrices/matrix.hpp"
#include "primordialmachine/math/scalars/include.hpp"
#include "primordialmachine/one_zero_functors/include.hpp"
#include <type_traits>

namespace primordialmachine {

// SFINAE for the struct type.
#pragma push_macro("STRUCT_CONDITION")
#define STRUCT_CONDITION()                                                     \
  std::enable_if_t<(                                                           \
    is_scalar<typename TRAITS::element_type>::value &&                         \
    (TRAITS::number_of_columns == 0 || TRAITS::number_of_rows == 0))>

template<typename TRAITS>
struct is_matrix<matrix<TRAITS>, STRUCT_CONDITION()>
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

  element_type* data();
  element_type const* data() const;

private:
  static constexpr void* dummy = nullptr;
};

#pragma push_macro("TYPE")
#define TYPE matrix<TRAITS, STRUCT_CONDITION()>

template<typename TRAITS>
TYPE::matrix()
{}

template<typename TRAITS>
typename TRAITS::element_type const*
TYPE::data() const
{
  return static_cast<typename TRAITS::element_type const*>(dummy);
}

template<typename TRAITS>
typename TRAITS::element_type*
TYPE::data()
{
  return static_cast<typename TRAITS::element_type *>(dummy);
}

#undef TYPE
#pragma pop_macro("TYPE")

#undef STRUCT_CONDITION
#pragma pop_macro("STRUCT_CONDITION")

} // namespace primordialmachine
