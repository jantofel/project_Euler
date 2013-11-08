
#include <iostream>

int main(int argc, char** argv) 
{
  long result = 0;
  long fib0 = 0;
  long fib1 = 1;
  long fib2 = 1;
  while (fib0 < 4000000)
    {
      result += fib0;
      fib0 = fib1 + fib2;
      fib1 = fib2 + fib0;
      fib2 = fib0 + fib1;
    } 
  std::cout << (result) << std::endl;
  return 0;
}
