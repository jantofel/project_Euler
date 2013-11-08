#include <iostream>

long uncommonDivisor(long number, int divisor)
{
  long result = 1;
  int i = 2;
  while (i <= divisor)    
    if ( divisor % i == 0 )
      {
	divisor /= i;
	if ( number % i != 0 )
	  result *= i;
	else
	  number /= i;
      }
    else
      ++i;   
  return result;
} 

int main(int argc, char** argv)
{
  long result = 1;
  for (int i = 1; i <= 20; ++i)
    {
      result *= uncommonDivisor(result, i);
    }
  std::cout << result << std::endl;
}
