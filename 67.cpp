#include <iostream>
#include <fstream>
using namespace std;

const int rows = 100;
int** triangle;

int tri(int x)
{
  // Return the 'triangle' of number x (i.e. x+(x-1)+...+1)
  return (x*(x+1))/2;
}

void fillTriangle()
{
  string line;
  ifstream file ("triangle.txt");
  if (file.is_open())
    {
      triangle = new int*[rows];
      for (int i = 0; i < rows; ++i)
	triangle[i] = new int[rows];
      for (int row = 0; row < rows; ++row)
	{
	  getline(file,line);
	  for (int col = 0; col <= row; ++col)
	    {
	      triangle[col][row] = 10*(line[3*col]-'0') + line[3*col+1]-'0'; 
	    }
	}
    }
  else cout << "Unable to open file" << endl;
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
  cout << triangle[0][0] << endl;
}
