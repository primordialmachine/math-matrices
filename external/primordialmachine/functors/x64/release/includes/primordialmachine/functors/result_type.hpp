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

// Primary template handles types that have no nested ::result_type member.
template<class, class = std::void_t<>>
struct has_result_type : std::false_type
{};

// Specialization recognizes types that do have a nested ::result_type member.
template<class T>
struct has_result_type<T, std::void_t<typename T::result_type>> : std::true_type
{};

template<class T>
constexpr bool has_result_type_v = has_result_type<T>::value;

} // namespace primordialmachine

namespace primordialmachine {

template<class, class = std::void_t<>>
struct result_type;

template<class T>
struct result_type<T, enable_if_t<has_result_type_v<T>>>
{
  using type = typename T::result_type;
}; // struct result_type

template<class T>
using result_type_t = typename result_type<T>::type;

} // namespace primordialmachine
