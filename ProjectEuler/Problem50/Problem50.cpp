// Problem50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Helpers/PrimeNumbers.h"
#include "Problem50.h"


int main()
{
  Problem50 p50;
  int bestSum = p50.findConsecutivePrimeSumThatAddsToAPrime(1000000);
  printf("The prime that can be written as the longest consecutive sum of primes is %d\r\n");
  return 0;
}

int Problem50::findConsecutivePrimeSumThatAddsToAPrime(int maxPrime)
{
  primeNumbers->generatePrimesUpTo(maxPrime);

  int bestSumSoFar = 0;
  int mostAddends = 0;
  // Generate enough cached primes.
  auto cachedPrimes = primeNumbers->getPrimes();
  for (auto it = cachedPrimes.begin(); it != cachedPrimes.end(); ++it)
  {
    int sum = 0;
    int addends = 0;
    for (auto it2 = it; it2 != cachedPrimes.end(); ++it2)
    {
      ++addends;
      sum += *it2;
      if (sum > maxPrime)
      {
        break;
      }
      if (primeNumbers->isPrime(sum) && addends > mostAddends)
      {
        bestSumSoFar = sum;
        mostAddends = addends;
      }
    }
  }
  return bestSumSoFar;
}

Problem50::Problem50()
  : primeNumbers(new PrimeNumbers())
{
}

Problem50::~Problem50()
{}