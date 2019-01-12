#pragma once

#include "primordialmachine/matrices/matrix.hpp"

namespace primordialmachine {

/*SOURCE must be a matrix or a matrix view.*/
template<typename SOURCE>
struct identity_index_view
{
  using traits_type = typename SOURCE::traits;
  
  SOURCE& m_source;
  
  constexpr identity_index_view(SOURCE& source) noexcept
    : m_source(source)
  {}
  
  index_2 to(index_2 source) const noexcept
  { return source; }

  index_1 to(index_1 source) const noexcept
  { return source; }

}; // struct identity_index_view

} // namespace primordialmachine
