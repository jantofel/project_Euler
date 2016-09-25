#pragma once

#include <memory>
class PrimeNumbers;

class Problem50 {
public:
  int findConsecutivePrimeSumThatAddsToAPrime(int maxPrime);
  Problem50();
  ~Problem50();
private:
  std::unique_ptr<PrimeNumbers> primeNumbers;
};