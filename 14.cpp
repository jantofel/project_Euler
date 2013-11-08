#include <iostream>

int collatzTerms(long n)
{
  int terms = 0;
  while (n > 1)
    {
      if (n % 2 == 0)
	n /= 2;
      else
	n = 3*n + 1;
      ++terms;
    }
  return terms;
}

int main(int argc, char** argv)
{
  int terms = 0;
  long result = 0;
  for (long n = 0; n < 1000000; ++n)
    {
      int tempTerms = collatzTerms(n);
      if (terms < tempTerms)
	{
	  terms = tempTerms;
	  result = n;
	}
    }
  std::cout << result << std::endl;
}
