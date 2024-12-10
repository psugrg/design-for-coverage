#include <iostream>

#include "Example.hpp"
#include "Version.h"

int main(void)
{
  std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;

  example::Example a(10);

  // Static analysis demo:
  char tmp[10] = "test";
  // uncomment to test
  // tm""p[11] = 's';
  std::cout << tmp << std::endl;
  return 0;
}
