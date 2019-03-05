#pragma once

#include "primordialmachine/math/non_scalars/index_1.hpp"
#include "primordialmachine/math/non_scalars/index_2.hpp"

namespace primordialmachine {

// Maps a 1D index to a 2D index.
constexpr index_2
to_index_2(index_1 source, size_t stride)
{
  return { source.i() / stride, source.i() % stride };
}

// Maps a 2D index to a 1D index.
constexpr index_2
to_index_2(index_2 source, size_t stride)
{
  return source;
}
  
} // namespace primordialmachine