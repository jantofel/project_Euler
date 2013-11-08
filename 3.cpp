#include <iostream>

bool isPrime(long x)
{
  for (long i = 2; i*i <= x; ++i)
    {
      if ( x % i == 0 )
	return false;
    }
  return true;
}

int main(int argc, char** argv)
{
  long x = 600851475143;
  long result = 2;
  for (long i = 2; i*i <= x; ++i)
    {
      if ( x % i == 0 && isPrime(i) )
	result = i;
    }
  std::cout << result << std::endl;
}
