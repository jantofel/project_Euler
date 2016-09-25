// Problem45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <set>

class Checker
{
public:
  Checker(long long (checkerFunction)(long long));
  bool check(long long);
private:
  std::set<long long> m_cache;
  long long(*m_checkerFunction)(long long);
};

int main()
{
  Checker pentagonal([](long long n) { return n*(3 * n - 1) / 2; });
  Checker  hexagonal([](long long n) { return n*(2 * n - 1); });
  if (!(pentagonal.check(40755) && hexagonal.check(40755)))
  {
    printf("The code isn't working properly!");
    return -1;
  }
  long long n = 285;
  while (true)
  {
    ++n;
    long long triagonal = n * (n + 1) / 2;
    if (pentagonal.check(triagonal) && hexagonal.check(triagonal))
    {
      printf("Found the next one! %lld\r\n", triagonal);
      return 0;
    }
  }
  return 0;
}

//// finds whether x fits into formula `x = n(3n-1)/2`
//bool Pentagonal::isPentagonal(long x)
//{
//  long n = ((long) sqrt(2 * x / 3)) + 1;
//  //double oldX = x;
//  //int root = round(sqrt(24 * oldX + 1));
//  //int n = (root + 1) / 6;
//  long newX = n * (3 * n - 1) / 2;
//  return x == newX;
//}
//
//// finds whether x fits into formula `x = n(2n-1)`
//bool Hexagonal::isHexagonal(long x)
//{
//  long n = ((long)sqrt(x / 2)) + 1;
//  //double oldX = x;
//  //int root = round(sqrt(8 * oldX + 1));
//  //int n = (root + 1) / 4;
//  long newX = n * (2 * n - 1);
//  return x == newX;
//}

Checker::Checker(long long(checkerFunction)(long long))
  : m_checkerFunction(checkerFunction)
{
  m_cache.insert(1);
}

bool Checker::check(long long n)
{
  while (n > *(m_cache.rbegin()))
  {
    m_cache.insert(m_checkerFunction(m_cache.size() + 1));
  }
  return (m_cache.find(n) != m_cache.end());
}