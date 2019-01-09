///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Arithmetic Functors Library
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

#include <type_traits>

namespace primordialmachine {

template<typename SCALAR, typename ENABLED = void>
struct scalar_generator_functor;

template<typename SCALAR>
struct scalar_generator_functor<SCALAR,
                               std::enable_if_t<std::is_floating_point_v<SCALAR>>>
{
  using scalar_type = SCALAR;

  scalar_type m_scalar;

  using result_type = SCALAR;

  scalar_generator_functor()
    : m_scalar()
  {}

  scalar_generator_functor(scalar_type const& scalar)
    : m_scalar(scalar)
  {}

  const result_type& operator()(size_t index) const { return m_scalar; }
  result_type& operator()(size_t index) { return m_scalar; }

}; // struct scalar_generator_functor

} // namespace primordialmachine
