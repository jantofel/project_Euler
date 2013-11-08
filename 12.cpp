 #include <iostream>

int divisors(long x)
{
  int result = 0;
  long d = 1;
  while (d*d <= x)
    {
      if(d*d == x)
	++result;
      else
	if (x % d == 0)
	  result += 2;
      ++d;
    }
  return result;
}

int main(int argc, char** argv)
{
  long result = 0;
  int i = 0;
  while (divisors(result) <= 500)
    {
      ++i;
      result += i;
    }
  std::cout << result << std::endl;
  return 0;
}
