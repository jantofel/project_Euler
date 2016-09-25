#include "PrimeNumbers.h"


bool PrimeNumbers::isPrime(int n) const
{
  if (n < 2)
    return false;
  if (m_cached_primes.find(n) != m_cached_primes.end())
    return true;
  for (auto p : m_cached_primes)
  {
    if (p*p > n)
      break;
    if (n % p == 0)
      return false;
  }
  m_cached_primes.insert(n);
  return true;
}


void PrimeNumbers::generatePrimesUpTo(int n)
{
  for (int i = 2; i <= n; ++i)
  {
    isPrime(i);
  }
}
