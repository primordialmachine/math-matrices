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

namespace primordialmachine {

struct index_1
{
private:
  size_t m_i;

public:
  constexpr index_1(size_t i) noexcept
    : m_i(i)
  {}
  constexpr const size_t& i() const noexcept { return m_i; }
  constexpr size_t& i() noexcept { return m_i; }
}; // struct index_1

struct index_2
{
private:
  size_t m_i;
  size_t m_j;

public:
  constexpr index_2(size_t i, size_t j) noexcept
    : m_i(i)
    , m_j(j)
  {}
  constexpr const size_t& i() const noexcept { return m_i; }
  constexpr size_t& i() noexcept { return m_i; }
  constexpr const size_t& j() const noexcept { return m_j; }
  constexpr size_t& j() noexcept { return m_j; }
}; // struct index_2

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
};

template<typename TYPE>
struct is_scalar
{
  static constexpr bool value = false;
};

template<>
struct is_scalar<float>
{
  static constexpr bool value = true;
};

template<>
struct is_scalar<double>
{
  static constexpr bool value = true;
};

template<>
struct is_scalar<long double>
{
  static constexpr bool value = true;
};

template<typename TYPE>
struct is_matrix
{
  static constexpr bool value = false;
};

template<typename TRAITS, typename ENABLED = void>
struct matrix;

} // namespace primordialmachine
