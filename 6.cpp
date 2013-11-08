#include <iostream>

int main(int argc, char** argv)
{
  long squareSum = (100*101)/2;
  squareSum *= squareSum;
  long sumSquare = 0;
  for (int i = 0; i < 101; ++i)
    sumSquare += i*i;
  long result = squareSum - sumSquare;
  std::cout << result << std::endl;
}
