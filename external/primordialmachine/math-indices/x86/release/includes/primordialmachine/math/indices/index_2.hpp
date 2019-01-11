///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Indices Library
// Copyright (C) 2019 Michael Heilmann
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

} // namespace primordialmachine
