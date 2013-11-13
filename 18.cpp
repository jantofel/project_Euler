#include <iostream>

const int rows = 15;
int** triangle;

const std::string contents = "75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

int tri(int x)
{
  // Return the 'triangle' of number x (i.e. x+(x-1)+...+1)
  return (x*(x+1))/2;
}

void fillTriangle()
{
  triangle = new int*[rows];
  for (int i = 0; i < rows; ++i)
    triangle[i] = new int[rows];
  for (int row = 0; row < rows; ++row)
    for (int col = 0; col <= row; ++col)
      {
        int pos = 3*(tri(row)+col);
        triangle[col][row] = 10*(contents[pos]-'0') + contents[pos+1]-'0';
      }
}

int max(int x, int y)
{
  if (x >= y)
    return x;
  else
    return y;
}

void setMaxSum(int col, int row)
{
  int submax1 = triangle[col][row+1];
  int submax2 = triangle[col+1][row+1];
  if (submax1 > submax2)
    triangle[col][row] += submax1;
  else
    triangle[col][row] += submax2;
}

int main(int argc, char** argv)
{
  fillTriangle();
  for (int row = rows-2; row >= 0; --row)
    for (int col = 0; col <= row; ++col)
      setMaxSum(col,row);
  std::cout << triangle[0][0] << std::endl;
}
