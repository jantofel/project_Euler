#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


int numberOfDigits (int number)
{
  int number_of_digits = 1;
  while (number >= 10)
    {
      number /= 10;
      ++number_of_digits;
    }
  return number_of_digits;
}


bool isPandigital (int number)
{
  for (int multiplicand = 2; multiplicand*multiplicand < number; ++multiplicand)
    {
      int multiplier = number / multiplicand;
      if ((multiplicand * multiplier == number) &&
          (numberOfDigits (multiplicand) + numberOfDigits (multiplier) + 
           numberOfDigits (number) == 9))
        {
          std::stringstream str_builder;
          str_builder << multiplier << multiplicand << number;
          std::string s = str_builder.str ();
          std::sort (s.begin (), s.end ());
          if (s == "123456789")
            {
              return true;
            }
        }
    }
  return false;
}


int main (int argc, char** argv)
{
  int sum_of_pandigital = 0;
  /* We don't need to go any higher than 5-digit numbers
   * since the multiplier, multiplicand and the product
   * would have to have more than 9 digits in total.
   */
  for (int i = 100; i < 99999; ++i)
    {
      if (isPandigital (i))
        {
          sum_of_pandigital += i;
        }
    }
  cout << "The sum is: " << sum_of_pandigital << endl;
}
