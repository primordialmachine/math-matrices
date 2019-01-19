///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Relational Functors Library
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

/* Type denoting a relational lower than operation. */
struct lower_than_operation
{
	static constexpr size_t number_of_operands = 2;
}; // struct lower_than_operation

/* Type denoting a relational lower than or equal to operation. */
struct lower_than_or_equal_to_operation
{
	static constexpr size_t number_of_operands = 2;
}; // struct lower_than_or_equal_to_operation

/* Type denoting a relational equal to operation. */
struct equal_to_operation
{
	static constexpr size_t number_of_operands = 2;
}; // struct equal_to_operation

/* Type denoting a relational not equal to operation. */
struct not_equal_to_operation
{
	static constexpr size_t number_of_operands = 2;
}; // struct not_equal_to_operation

/* Type denoting a greater than to operation. */
struct greater_than_operation
{
	static constexpr size_t number_of_operands = 1;
}; // struct greater_than_operation

/* Type denoting a greater than or equal to operation. */
struct greater_than_or_equal_to_operation
{
	static constexpr size_t number_of_operands = 1;
}; // struct greater_than_or_equal_to_operation

} // namespace primordialmachine
