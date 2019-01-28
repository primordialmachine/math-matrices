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

template<typename SOURCE, size_t COLUMN>
struct const_delete_column_view
{
  using traits_type = matrix_traits<element_type_t<SOURCE>,
                                    number_of_columns<SOURCE>() - 1,
                                    number_of_rows<SOURCE>()>;
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

  const_delete_column_view(const SOURCE& source) noexcept
    : m_source(source)
  {}

private:
  constexpr index_2 to(index_2 source) const noexcept
  {
    /*Skip deleted column.*/
    if (source.j() >= COLUMN) {
      return { source.i(), source.j() + 1 };
    } else {
      return source;
    }
  }

  constexpr index_1 to(index_1 source) const noexcept
  {
    static constexpr size_t ACTUAL_STRIDE = traits_type::number_of_columns + 1;
    static constexpr size_t VIEW_STRIDE = traits_type::number_of_columns;
    return to_index_1(to(to_index_2(source, VIEW_STRIDE), ACTUAL_STRIDE));
  }
}; // struct const_delete_column_view

template<typename SOURCE, size_t COLUMN>
struct is_matrix<const_delete_column_view<SOURCE, COLUMN>, void> : public true_type
{}; // struct is_matrix

// SOURCE a matrix or matrix view type
// COLUMN the column index
template<typename SOURCE, size_t COLUMN>
struct delete_column_view
{
  using traits_type = matrix_traits<element_type_t<SOURCE>,
                                    number_of_columns_v<SOURCE> - 1,
                                    number_of_rows_v<SOURCE>>;
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

  delete_column_view(SOURCE& source) noexcept
    : m_source(source)
  {}

private:
  constexpr index_2 to(index_2 source) const noexcept
  {
    /*Skip deleted column.*/
    if (source.j() >= COLUMN) {
      return { source.i(), source.j() + 1 };
    } else {
      return source;
    }
  }

  constexpr index_1 to(index_1 source) const noexcept
  {
    static constexpr size_t ACTUAL_STRIDE = traits_type::number_of_columns + 1;
    static constexpr size_t VIEW_STRIDE = traits_type::number_of_columns;
    return to_index_1(to(to_index_2(source, VIEW_STRIDE), ACTUAL_STRIDE));
  }
}; // struct delete_column_view

template<typename SOURCE, size_t COLUMN>
struct is_matrix<delete_column_view<SOURCE, COLUMN>, void>
{
  static constexpr bool value = true;
}; // struct is_matrix

} // namespace primordialmachine
