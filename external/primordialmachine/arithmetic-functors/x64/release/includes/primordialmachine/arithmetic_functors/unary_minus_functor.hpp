///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Arithmetic Functors Library
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

#include <type_traits>

namespace primordialmachine {

template<typename A, typename ENABLED = void>
struct unary_minus_functor;

template<typename A>
auto
unary_minus(const A& a) noexcept(noexcept(unary_minus_functor<A>()(a)))
  -> decltype(unary_minus_functor<A>()(a))
{
  return unary_minus_functor<A>()(a);
}

template<typename A>
auto
operator-(const A& a) noexcept(noexcept(unary_minus(a)))
  -> decltype(unary_minus(a))
{
  return unary_minus(a);
}

template<typename A, typename ENABLED = void>
struct has_unary_minus_functor : public false_type
{}; // struct has_unary_minus_functor

template<typename A>
constexpr bool has_unary_minus_functor_v =
  has_unary_minus_functor<unary_minus_functor<A>>::value;

template<typename A>
struct has_unary_minus_functor<unary_minus_functor<A>,
                               decltype(typeid(unary_minus_functor<A>), void())>
  : public true_type
{}; // struct has_unary_minus_functor

} // namespace primordialmachine
