#include "Solution1.hpp"

namespace solution1
{
Foo::Foo(std::unique_ptr<extLibFacade::IStorage> storage, int val) : m_storage{ std::move(storage) }
{
  if (m_storage && m_storage->put(val))
    return;

  throw std::out_of_range("Storage full");
}
}  // namespace solution1
