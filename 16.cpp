#include <iostream>

void multiplyBy2(long* number)
{
  for (int i = 0; number[i] > 0; ++i)
    number[i] *= 2;
  for (int i = 0; number[i] > 0; ++i)
    if ( number[i] > 10000000000 )
      {
	number[i] -= 10000000000;
	++number[i+1];
      }
}

int sum(long* number)
{
  int result = 0;
  for (int i = 0; number[i] > 0; ++i)
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
  for (int i = 0; i < 1000; ++i)
    multiplyBy2(number);
  int result = sum(number);
  std::cout << result << std::endl;
}
