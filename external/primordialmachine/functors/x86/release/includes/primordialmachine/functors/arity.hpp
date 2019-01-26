///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Functors Library
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

// Primary template handles types that have no nested ::arity member.
template<class, class = std::void_t<>>
struct has_arity : std::false_type
{};

// Specialization recognizes types that do have a nested ::arity member.
template<class T>
struct has_arity<T, std::void_t<decltype(T::arity)>> : std::true_type
{};

template<class T>
constexpr bool has_arity_v = has_arity<T>::value;

} // namespace primordialmachine

namespace primordialmachine {

template<class, class = std::void_t<>>
struct arity;

template<class T>
struct arity<T, enable_if_t<has_arity_v<T>>>
{
  static constexpr bool value = T::arity;
  
}; // struct result_type

template<class T>
constexpr bool arity_v = arity<T> : value;

} // namespace primordialmachine
