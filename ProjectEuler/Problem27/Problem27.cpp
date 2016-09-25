// Problem27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include "../Helpers/PrimeNumbers.h"

class PrimeNumbers;
int numConsecutivePrimes(int a, int b, const PrimeNumbers&);

int main()
{
  PrimeNumbers prime_checker;
  int coeff_product = 0;
  int most_primes = 0;
  for (int a = -999; a < 1000; ++a)
  {
    // any `b` < 0 produces a negative number for `n=0`
    for (int b = 0; b <= 1000; ++b)
    {
      int num_primes = numConsecutivePrimes(a, b, prime_checker);
      if (num_primes > most_primes)
      {
        coeff_product = a * b;
        most_primes = num_primes;
      }
    }
  }
  printf("The product of coefficients is %d, producing %d consecutive primes.\r\n", coeff_product, most_primes);
  return 0;
}

int numConsecutivePrimes(int a, int b, const PrimeNumbers& prime_checker)
{
  int n = 0;
  while (prime_checker.isPrime(n*n + a*n + b))
  {
    ++n;
  }
  return n;
}

