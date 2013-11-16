#include <iostream>

using namespace std;

bool isAbundant(int n) 
{
  int divisors = 0;
  for (int i = 1; i < n; ++i) 
    if (n % i == 0)
      divisors += i;
  return divisors > n;
}

bool isSumOfTwoAbundant(int n, int* abundantNumbers)
{
  for (int i = 0; i <= n/2; ++i)
    if (abundantNumbers[i] && abundantNumbers[n-i])
      return true;
  return false;
}

int main(int argc, char** argv)
{
  int* abundantNumbers = new int[28124];
  for (int i = 1; i <= 28123; ++i)
    if (isAbundant(i))
      abundantNumbers[i] = 1;
  int result = 0;
  for (int n = 0; n <= 28123; ++n)
    if (!isSumOfTwoAbundant(n, abundantNumbers))
      result += n;
  /*
  cout << isSumOfTwoAbundant(23, abundantNumbers) << endl;
  cout << isSumOfTwoAbundant(24) << endl;
  */
  cout << result << endl;
}
