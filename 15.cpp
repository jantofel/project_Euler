#include <iostream>

const int X = 20;
const int Y = 20;
long** result;

long pathsFrom(int x, int y)
{
  if (x < X && y < Y)
    return result[x+1][y] + result[x][y+1];
  return 1;
}

int main(int argc, char** argv)
{
  result = new long*[Y+1];
  for (int i = 0; i < Y+1; ++i)
    {
      result[i] = new long[X+1];
    }
  for (int x = X; x >= 0; --x)
    for (int y = Y; y >= 0; --y)
      {
	result[x][y] = pathsFrom(x,y);
      }
  std::cout << result[0][0] << std::endl;
}
