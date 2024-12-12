#ifndef __INTEXAMPLE_HPP
#define __INTEXAMPLE_HPP

#include <stdexcept>

#include "externLib.hpp"

namespace case1
{
/**
 * @brief Class under test
 *
 * The case here is to be able to fully cover the code inside of this class
 * using tests.
 *
 * Assumption:  library::Storage can't be changed since it's an external
 * dependency
 *
 * This implementation can't be fully covered because @c m_storage.put(val)
 * will never return false thus on of the branches in the @c if statement will
 * not be covered.
 */
class Foo
{
public:
  Foo(int val);

private:
  externLib::Storage m_storage;
};
}  // namespace case1

#endif  // __INTEXAMPLE_HPP