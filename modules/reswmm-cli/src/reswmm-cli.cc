#include "reswmm/reswmm.h"

#include <iostream>
// std::cout
#include <cstdlib>
// EXIT_SUCCESS

int main(int argc, char const *argv[])
{
  double result = reswmm::run();
  std::cout << "result = " << result << std::endl;
  return EXIT_SUCCESS;
}
