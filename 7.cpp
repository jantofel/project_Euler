#include <iostream>

int main(int argc, char** argv)
{
  long *primes = new long[10001];
  primes[0] = 2;
  for (int i = 0; i < 10000; ++i)
    {
      bool isPrime = false;
      long prime = primes[i]+1;
      while(!isPrime)
	{
	  bool found = false;
	  int j = 0;
	  while(!found)
	    {
	      if (primes[j] == 0)
		{
		  isPrime = true;
		  found = true;
		  primes[j] = prime;
		}
	      else
		if (prime%primes[j]==0)
		  {
		    found = true;
		  }
	      ++j;
	    }
	  ++prime;
	}
    }
  std::cout << "The 10001st prime number is: " << primes[10000] << std::endl;
  return 0;
}
