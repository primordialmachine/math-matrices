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

#include "primordialmachine/errors/include.hpp"

namespace primordialmachine {

class underflow_error;
class underflow_exception;

class underflow_error : public error
{
public:
  using parent_type = error;
  using position_type = error_position;
  underflow_error(position_type position);
protected:
  underflow_error* clone_implementation() const override;
  void raise_implementation() const override;
}; // class underflow_error

class underflow_exception : public exception
{
public:
  using parent_type = exception;
  underflow_exception(const underflow_error& error);
}; // class underflow_exception

} // namespace primordialmachine
