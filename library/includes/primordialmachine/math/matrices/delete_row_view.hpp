///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Matrices Library
// Copyright (c) 2017-2019 Michael Heilmann
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

#include "primordialmachine/math/matrices/matrix.hpp"

namespace primordialmachine {

/*SOURCE must be a matrix or a matrix view.*/
template<typename SOURCE, size_t ROW>
struct const_delete_row_view
{
  using traits_type = matrix_traits<element_type_t<SOURCE>,
                                    number_of_columns<SOURCE>(),
                                    number_of_rows<SOURCE>() - 1>;

  const SOURCE& m_source;

  auto operator()(size_t i, size_t j) const
  {
    auto ij = to({ i, j });
    return m_source(ij.i(), ij.j());
  }

  auto operator()(size_t i) const
  {
    auto i_ = to(i);
    return m_source(i);
  }

  auto operator()(size_t i, size_t j)
  {
    auto ij = to({ i, j });
    return m_source(ij.i(), ij.j());
  }

  auto operator()(size_t i)
  {
    auto i_ = to(i);
    return m_source(i);
  }

  const_delete_row_view(const SOURCE& source) noexcept
    : m_source(source)
  {}

private:
  constexpr index_2 to(index_2 source) const noexcept
  {
    /* Skip deleted row.*/
    if (source.i() >= ROW) {
      return { source.i() + 1, source.j() };
    } else {
      return source;
    }
  }

  constexpr index_1 to(index_1 source) const noexcept
  {
    static constexpr size_t ACTUAL_STRIDE = traits_type::number_of_columns;
    static constexpr size_t VIEW_STRIDE = traits_type::number_of_columns;
    return to_index_1(to(to_index_2(source, VIEW_STRIDE), ACTUAL_STRIDE));
  }

}; // struct delete_row_view

template<typename SOURCE, size_t ROW>
struct is_matrix<const_delete_row_view<SOURCE, ROW>, void>
{
  static constexpr bool value = true;
}; // struct is_matrix

/*SOURCE must be a matrix or a matrix view.*/
template<typename SOURCE, size_t ROW>
struct delete_row_view
{
  using traits_type = matrix_traits<element_type_t<SOURCE>,
                                    number_of_columns_v<SOURCE>,
                                    number_of_rows_v<SOURCE> - 1>;

  SOURCE& m_source;

  auto operator()(size_t i, size_t j) const
  {
    auto ij = to({ i, j });
    return m_source(ij.i(), ij.j());
  }

  auto operator()(size_t i) const
  {
    auto i_ = to(i);
    return m_source(i);
  }

  auto operator()(size_t i, size_t j)
  {
    auto ij = to({ i, j });
    return m_source(ij.i(), ij.j());
  }

  auto operator()(size_t i)
  {
    auto i_ = to(i);
    return m_source(i);
  }

  delete_row_view(SOURCE& source) noexcept
    : m_source(source)
  {}

private:
  constexpr index_2 to(index_2 source) const noexcept
  {
    /* Skip deleted row.*/
    if (source.i() >= ROW) {
      return { source.i() + 1, source.j() };
    } else {
      return source;
    }
  }

  constexpr index_1 to(index_1 source) const noexcept
  {
    static constexpr size_t ACTUAL_STRIDE = traits_type::number_of_columns;
    static constexpr size_t VIEW_STRIDE = traits_type::number_of_columns;
    return to_index_1(to(to_index_2(source, VIEW_STRIDE), ACTUAL_STRIDE));
  }

}; // struct delete_row_view

template<typename SOURCE, size_t ROW>
struct is_matrix<delete_row_view<SOURCE, ROW>, void>
{
  static constexpr bool value = true;
}; // struct is_matrix

} // namespace primordialmachine
