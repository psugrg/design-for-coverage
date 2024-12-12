#include <gtest/gtest.h>

#include "Case1.hpp"

class ExampleTests : public ::testing::Test
{
};

/**
 * @brief Case1, class that cannot be fully covered
 *
 */
TEST_F(ExampleTests, case1)
{
  ASSERT_THROW(case1::Foo(4), std::out_of_range);
}
