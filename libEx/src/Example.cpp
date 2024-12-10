#include "Example.hpp"

namespace example
{
Example::Example(const int& a)
{
  m_a = a;
}

int Example::getA()
{
  return m_a;
}
}  // namespace example
