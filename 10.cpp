#include <iostream>

int main(int argc, char** argv)
{
  long *primes = new long[1000000];
  for (int i = 0; i < 900000; ++i)
    {
      primes[i] = 0;
    }
  primes[0] = 2;
  bool endLoop = false;
  for (int i = 0; !endLoop; ++i)
    {
      bool isPrime = false;
      long prime = primes[i]+1;
      while(!isPrime)
	{
	  bool found = false;
	  int j = 0;
	  while(!found)
	    {
	      if (primes[j]*primes[j] > prime)
		{
		  isPrime = true;
		  found = true;
		  if (prime < 2000000)
		    primes[i+1] = prime;
		  else 
		    endLoop = true;
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
  long result = 0;
  for (int i = 0; primes[i] > 0; ++i)
    {
      result += primes[i];
    }
  std::cout << "The sum of prime numbers under two million is: " << result << std::endl;
  return 0;
}
