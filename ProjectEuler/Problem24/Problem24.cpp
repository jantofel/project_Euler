// Problem24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>

int factorial(int n);

int main()
{
  // The number of permutations of `n` digits is `factorial(n)`.
  if (factorial(10) < 1000000)
  {
    printf("Cannot finish the problem, there is less than million permutations!\r\n");
    return -1;
  }
  // There is `factorial(9)` permutations with `0` fixed in place as the first number,
  // `factorial(8)` with `01` etc.
  int distance_to_cover = 1000000;
  long long result = 0;
  std::set<int> used_digits;

  // Fix the left-most digit first, before continuing to the right-hand side.
  for (int digit_position = 9; digit_position >= 0; --digit_position)
  {
    // go to next digit
    result *= 10;

    int digit = 0;

    // If `0` has already been used, then the first sub-permutation starts with `1`,
    // if both have been used it starts with `2` etc.
    while (used_digits.find(digit) != used_digits.end())
    {
      ++digit;
    }
    // On the very first iteration, jump `factorial(9)` permutations ahead
    // by thinking of permutations starting with `1` instead of `0`,
    // then another `factorial(9)` permutations ahead for those starting with `2` etc.
    while (distance_to_cover > factorial(digit_position))
    {
      distance_to_cover -= factorial(digit_position);
      ++digit;
      // If the digit has already been used, increment further.
      while (used_digits.find(digit) != used_digits.end())
      {
        ++digit;
      }
    }
    // A digit is fixed, just need to remember it.
    used_digits.insert(digit);
    result += digit;
  }
  printf("The Millionth permutation is %lld\r\n", result);
  return 0;
}

int factorial(int n)
{
  if (n < 2)
    return 1;
  else
    return n * factorial(n - 1);
}

int exp(int n)
{
  if (n < 1)
    return 1;
  else
    return 10 * exp(n - 1);
}