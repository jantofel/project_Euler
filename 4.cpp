#include <iostream>

bool isPalindrome(int x) 
{
  int fstDigit = x;
  while (fstDigit > 9)
    {
      fstDigit /= 10;
    }
  int sndDigit = x;
  while (sndDigit > 99)
    {
      sndDigit /= 10;
    }
  sndDigit %= 10;
  int trdDigit = x;
  while (trdDigit > 999)
    {
      trdDigit /= 10;
    }
  trdDigit %= 10;
  /*  std::cout << " " <<  fstDigit << std::endl << x%10 << std::endl;
  std::cout << " " <<  sndDigit << std::endl << (x%100)/10 << std::endl;
  std::cout << " " <<  trdDigit << std::endl << (x%1000)/100 << std::endl;*/
  return ((fstDigit == x%10) && (sndDigit == (x%100)/10) && (trdDigit == (x%1000)/100));
}

int main(int argc, char** argv)
{
  int x = 999;
  int y = 999;
  int result = 0;
  std::cout << isPalindrome(990099);
  for (int i = 0; i < 500; ++i)
    {
      for (int j = 0; j < 500; ++j)
	{
	  if (isPalindrome((x-i)*(y-j)) && ((x-i)*(y-j) > result))
	    {
	      result = (x-i)*(y-j);
	      std::cout << x-i << std::endl << y-j << std::endl << result << std::endl;
	    }
	}
    }
  return 0;
}
