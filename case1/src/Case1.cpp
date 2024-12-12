#include "Case1.hpp"

namespace case1
{
Foo::Foo(int val)
{
  if (m_storage.put(val))
    return;

  throw std::out_of_range("Storage full");
}
}  // namespace case1
