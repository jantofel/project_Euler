#include <iostream>

void multiply(long* number, int factor)
{
  for (int i = 0; i < 100; ++i)
    number[i] *= factor;
  for (int i = 0; i < 100; ++i)
    if ( number[i] > 1000000 )
      {
	number[i+1] += number[i] / 1000000;
	number[ i ] %= 1000000;
      }
}

int sum(long* number)
{
  int result = 0;
  for (int i = 0; i < 100; ++i)
    while (number[i] > 0)
      {
	result += number[i] % 10;
	number[i] /= 10;
      }
  return result;
}

int main(int argc, char** argv)
{
  long* number = new long[100];
  number[0] = 1;
  for (int factor = 1; factor <= 100; ++factor)
    multiply(number, factor);
  int result = sum(number);
  std::cout << result << std::endl;
}
