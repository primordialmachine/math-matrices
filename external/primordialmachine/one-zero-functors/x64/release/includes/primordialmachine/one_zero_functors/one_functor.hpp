///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's One Zero Library
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

template<typename TYPE>
struct one_functor;

template<>
struct one_functor<char>
{
  using result_type = char;
  constexpr char operator()() noexcept { return 1; }
}; // struct one_functor

template<>
struct one_functor<signed char>
{
  using result_type = signed char;
  constexpr signed char operator()() noexcept { return 1; }
}; // struct one_functor
template<>
struct one_functor<unsigned char>
{
  using result_type = unsigned char;
  constexpr unsigned char operator()() noexcept { return 1; }
}; // struct one_functor

template<>
struct one_functor<signed short int>
{
  using result_type = signed short int;
  constexpr signed short int operator()() noexcept { return 1; }
}; // struct one_functor
template<>
struct one_functor<unsigned short int>
{
  using result_type = unsigned short int;
  constexpr unsigned short int operator()() noexcept { return 1; }
}; // struct one_functor

template<>
struct one_functor<signed int>
{
  using result_type = signed int;
  constexpr signed int operator()() noexcept { return 1; }
}; // struct one_functor
template<>
struct one_functor<unsigned int>
{
  using result_type = unsigned int;
  constexpr unsigned int operator()() noexcept { return 1; }
}; // struct one_functor

template<>
struct one_functor<signed long int>
{
  using result_type = signed long int;
  constexpr signed long int operator()() noexcept { return 1L; }
}; // struct one_functor
template<>
struct one_functor<unsigned long int>
{
  using result_type = unsigned long int;
  constexpr unsigned long int operator()() noexcept { return 1UL; }
}; // struct one_functor

template<>
struct one_functor<signed long long int>
{
  using result_type = signed long long int;
  constexpr signed long long int operator()() noexcept { return 1LL; }
}; // struct one_functor
template<>
struct one_functor<unsigned long long int>
{
  using result_type = unsigned long long int;
  constexpr unsigned long long int operator()() noexcept { return 1ULL; }
}; // struct one_functor

template<>
struct one_functor<float>
{
  using result_type = float;
  constexpr float operator()() noexcept { return 1.F; };
}; // struct one_functor
template<>
struct one_functor<double>
{
  using result_type = double;
  constexpr double operator()() noexcept { return 1.; };
}; // struct one_functor
template<>
struct one_functor<long double>
{
  using result_type = long double;
  constexpr long double operator()() noexcept { return 1.L; }
}; // struct one_functor

} // namespace primordialmachine
