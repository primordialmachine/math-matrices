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

#include "primordialmachine/math/indices/include.hpp"

namespace primordialmachine {

/* TODO: Move into matrix.hpp. */
template<typename M>
using make_column_indices =
  std::make_index_sequence<M::traits_type::number_of_columns>;

/*TODO: Move into matrix.hpp.*/
template<typename M>
using make_row_indices =
  std::make_index_sequence<M::traits_type::number_of_rows>;

/*TODO: Move into matrix.hpp.*/
template<typename M>
using make_element_indices =
  std::make_index_sequence<M::traits_type::number_of_elements>;

constexpr index_1
to_index_1(index_1 source, size_t stride)
{
  return source;
}

constexpr index_1
to_index_1(index_2 source, size_t stride)
{
  return { source.i() * stride + source.j() };
}

constexpr index_2
to_index_2(index_1 source, size_t stride)
{
  return { source.i() / stride, source.i() % stride };
}

constexpr index_2
to_index_2(index_2 source, size_t stride)
{
  return source;
}

template<typename ELEMENT_TYPE, size_t NUMBER_OF_COLUMNS, size_t NUMBER_OF_ROWS>
struct matrix_traits
{
  static constexpr size_t number_of_rows = NUMBER_OF_ROWS;
  static constexpr size_t number_of_columns = NUMBER_OF_COLUMNS;
  static constexpr size_t number_of_elements =
    NUMBER_OF_ROWS * NUMBER_OF_COLUMNS;
  using element_type = ELEMENT_TYPE;
  static constexpr bool is_square = number_of_rows == number_of_columns;
  // true if the matrix type is a degenerated case i.e.
  // its number of rows is 0 or its number of columns is 0.
  static constexpr bool is_degenerate =
    NUMBER_OF_ROWS == 0 || NUMBER_OF_COLUMNS == 0;
  // true if the matrix type is a non-degenerated case i.e.
  // its number of rows is greater than 0 and its number of columns is greater
  // than 0.
  static constexpr bool is_non_degenerate = false == is_degenerate;
}; // struct matrix_traits

template<typename TYPE, typename ENABLED = void>
struct is_matrix
{
  static constexpr bool value = false;
};

template<typename TRAITS, typename ENABLED = void>
struct matrix;

} // namespace primordialmachine
