#include <gtest/gtest.h>

#include "Case1.hpp"

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
