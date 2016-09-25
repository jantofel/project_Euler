#pragma once

#include <set>


class PrimeNumbers
{
private:
  mutable std::set<int> m_cached_primes;
public:
  bool isPrime(int n) const;
  void generatePrimesUpTo(int n);
  const std::set<int>& getPrimes() const
  {
    return m_cached_primes;
  }
};

