#include <iostream>

int sumDivisors(int n)
{
  int result = 1;
  for (int i = 2; i*i <= n; ++i)
    if ( n % i == 0 )
      {
        result += n / i;
	if ( i*i != n)
	  result +=  i;
      }
  return result;
}

bool isAmicable(int n)
{
  int sumD = sumDivisors(n);
  return (n != sumD && n == sumDivisors(sumD));
}

int main(int argc, char** argv)
{
  long result = 0;
  for (int i = 0; i < 10000; ++i)
    if (isAmicable(i))
      result += i;
  std::cout << result << std::endl;
}
