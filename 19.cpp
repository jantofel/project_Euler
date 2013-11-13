#include <iostream>

using namespace std;

const int SUNDAY = 0;
const int* MONTHS = new int[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year)
{
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main(int argc, char** argv)
{
  int year = 1901;
  int month = 0;
  int sundaysOnFirst = 0;
  int day = 2; // TUESDAY was 1st of January 1901
  while (year <= 2000)
    {
      if (day == SUNDAY)
	++sundaysOnFirst;
      day += MONTHS[month];
     if (isLeap(year) && month == 1)
	++day;
      day %= 7;
      ++month;
      if (month == 12)
	{
	  ++year;
	  month = 0;
	}      
    }
  cout << sundaysOnFirst << endl;
}
