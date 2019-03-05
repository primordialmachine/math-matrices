#pragma once

#include "primordialmachine/math/non_scalars/index_1.hpp"
#include "primordialmachine/math/non_scalars/index_2.hpp"

namespace primordialmachine {

// Identity mapping, 1D index to 1D index.
constexpr index_1
to_index_1(index_1 source, size_t stride)
{
  return source;
}

// Identity mapping, 2D index to 2D index.
constexpr index_1
to_index_1(index_2 source, size_t stride)
{
  return { source.i() * stride + source.j() };
}
  
} // namespace primordialmachine