#include <gtest/gtest.h>

#include <memory>

#include "Case1.hpp"
#include "Solution1.hpp"

class Case1Tests : public ::testing::Test
{
};

/**
 * @brief Case1, class that cannot be fully covered
 *
 */
TEST_F(Case1Tests, case1)
{
  ASSERT_THROW(case1::Foo(4), std::out_of_range);
}

class StorageMock : public extLibFacade::IStorage
{
public:
  bool put(int) final
  {
    return false;
  }

  std::optional<int> get() final
  {
    return false;
  }
};

TEST_F(Case1Tests, solution1_positive)
{
  auto storage = std::make_unique<extLibFacade::Storage>();

  ASSERT_NO_THROW(solution1::Foo(std::move(storage), 4));
}

TEST_F(Case1Tests, solution1_negative)
{
  auto storage = std::unique_ptr<StorageMock>();

  ASSERT_ANY_THROW(solution1::Foo(std::move(storage), 4));
}
