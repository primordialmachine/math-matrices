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

namespace primordialmachine {

/* Type denoting a binary star operation. */
struct binary_star_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct binary_star_operation

/* Type denoting a star assignment operation. */
struct star_assignment_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct star_assignment_operation

/* Type denoting a binary slash operation. */
struct binary_slash_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct binary_slash_operation

/* Type denoting a slash assignment operation. */
struct slash_assignment_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct slash_assignment_operation

/* Type denoting a binary plus operation. */
struct binary_plus_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct binary_plus_operation

/* Type denoting a plus assignment operation. */
struct plus_assignment_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct plus_assignment_operation

/* Type denoting a binary minus operation. */
struct binary_minus_operation
{
  static constexpr size_t number_of_operands = 2;
}; // struct binary_minus_operation

/* Type denoting a minus assignment operation. */
struct minus_assignment_operation
{
  static constexpr size_t number_of_operands = 2;
};

/* Type denoting an unary plus operation. */
struct unary_plus_operation
{
  static constexpr size_t number_of_operands = 1;
}; // struct unary_plus_operation

/* Type denoting an unary minus operation. */
struct unary_minus_operation
{
  static constexpr size_t number_of_operands = 1;
}; // struct unary_minus_operation

} // namespace primordialmachine
