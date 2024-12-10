#include <gtest/gtest.h>

#include "Example.hpp"

/**
 * @brief This is an example of using google tests in the project
 *
 * useage:
 * - Run tests (verbose)
 *    ./build/ctest -VV
 * - Run Valgrind (memory leaks)
 *    ./build/ctest -T memcheck
 *
 */
class ExampleTests : public ::testing::Test
{
};

/**
 * @brief Passing test example
 *
 */
TEST_F(ExampleTests, simple)
{
  example::Example e = example::Example(10);

  EXPECT_EQ(e.getA(), 10);
}

/**
 * @brief Failing test example
 *
 */
TEST_F(ExampleTests, simple_fail)
{
  example::Example e = example::Example(10);

  EXPECT_EQ(e.getA(), 1);
}

/**
 * @brief Memory leak example
 *
 */
TEST_F(ExampleTests, memleak)
{
  double* leak = new double[10];
  leak = leak;

  EXPECT_EQ(1, 1);
}
