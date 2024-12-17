#ifndef CASE1_HPP
#define CASE1_HPP

#include <stdexcept>

#include "externLib.hpp"

namespace case1
{
class Foo
{
public:
  Foo(int val);

private:
  externLib::Storage m_storage;
};
}  // namespace case1

#endif  // CASE1_HPP