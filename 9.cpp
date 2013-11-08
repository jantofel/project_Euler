#include <iostream>

int sqrt(int x)
{
  int root = 0;
  while(root*root <= x)
    {
      if (root*root == x)
	return root;
      ++root;
    }
  return 0;
}

int main(int argc, char** argv)
{
  for (int b = 0; b < 500; ++b)
    {
      for (int a = 0; a < b; ++a)
	{
	  int c = sqrt(a*a + b*b);
	  //	  std::cout << a << b << c << std::endl;
	  if (a+b+c == 1000)
	    std::cout << a*b*c << std::endl;
	}
    }
  return 0;
}
