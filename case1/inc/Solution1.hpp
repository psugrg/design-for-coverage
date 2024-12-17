#ifndef SOLUTION1_HPP
#define SOLUTION1_HPP

#include <memory>
#include <optional>
#include <stdexcept>

#include "externLib.hpp"

namespace extLibFacade
{
class IStorage
{
public:
  virtual bool put(int val) = 0;
  virtual std::optional<int> get() = 0;
  virtual ~IStorage() = default;
};

class Storage : public IStorage
{
public:
  bool put(int val) final
  {
    return m_storage.put(val);
  }

  std::optional<int> get() final
  {
    return m_storage.get();
  }

private:
  externLib::Storage m_storage;
};
}  // namespace extLibFacade

namespace solution1
{
class Foo
{
public:
  Foo(std::unique_ptr<extLibFacade::IStorage> storage, int val);

private:
  std::unique_ptr<extLibFacade::IStorage> m_storage;
};
}  // namespace solution1

#endif  // SOLUTION1_HPP