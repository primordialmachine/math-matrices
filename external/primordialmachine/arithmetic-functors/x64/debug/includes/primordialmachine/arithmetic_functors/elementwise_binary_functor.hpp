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

template<typename LEFT_OPERAND,
         typename RIGHT_OPERAND,
         typename RESULT,
         size_t NUMBER_OF_ELEMENTS,
         typename OPERATOR,
         typename ENABLED = void>
struct elementwise_binary_functor
{
  using left_operand_type = LEFT_OPERAND;

  using right_operand_type = RIGHT_OPERAND;

  using result_type = RESULT;

  using operator_type = OPERATOR;

  constexpr result_type operator()(
    left_operand_type const& left_operand,
    right_operand_type const& right_operand) const
  {
    return impl(left_operand,
                right_operand,
                std::make_index_sequence<NUMBER_OF_ELEMENTS>());
  }

private:
  template<size_t... Is>
  auto impl(const left_operand_type& left_operand,
            const right_operand_type& right_operand,
            std::index_sequence<Is...>) const
  {
    static const auto op = OPERATOR();
    return result_type{ op(left_operand(Is), right_operand(Is))... };
  }
};

} // namespace primordialmachine
