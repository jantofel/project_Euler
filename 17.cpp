#include <iostream>

using namespace std;

// Enables easy adjustment for different languages and makes the code clearer, in my opinion.

const int THOUSAND = 8;
const int HUNDRED = 7;
const int AND = 3;

const int NINETY = 6;
const int EIGHTY = 6;
const int SEVENTY = 7;
const int SIXTY = 5;
const int FIFTY = 5;
const int FORTY = 5;
const int THIRTY = 6;
const int TWENTY = 6;

const int* TWENTYTONINETY = new int[10] {0, 0, TWENTY, THIRTY, FORTY, FIFTY, SIXTY, SEVENTY, EIGHTY, NINETY};

const int NINETEEN = 8;
const int EIGHTEEN = 8;
const int SEVENTEEN = 9;
const int SIXTEEN = 7;
const int FIFTEEN = 7;
const int FOURTEEN = 8;
const int THIRTEEN = 8;
const int TWELVE = 6;
const int ELEVEN = 6;
const int TEN = 3;
const int NINE = 4;
const int EIGHT = 5;
const int SEVEN = 5;
const int SIX = 3;
const int FIVE = 4;
const int FOUR = 4;
const int THREE = 5;
const int TWO = 3;
const int ONE = 3;

const int* LESSTHAN20 = new int [20] {0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN, SIXTEEN, SEVENTEEN, EIGHTEEN, NINETEEN};



int letterCount(int n)
{
  int letters = 0;
  if (n >= 1000000 || n < 1)
    return 0; // Did not implement such numbers
  if (n >= 1000)
    {
      letters += letterCount(n / 1000);
      letters += THOUSAND;
      letters += letterCount(n % 1000);
      return letters;
    }
  if (n >= 100)
    {
      letters += letterCount(n / 100);
      letters += HUNDRED;
      if (n % 100 != 0)
	{
	  letters += AND;
	  letters += letterCount(n % 100);
	}
      return letters;
    }
  if (n >= 20)
    {
      letters += TWENTYTONINETY[n / 10];
      letters += letterCount(n % 10);
      return letters;
    }
  letters = LESSTHAN20[n];
  return letters;
}

int main(int argc, char** argv)
{
  int totalLetters = 0;
  for (int n = 1; n <= 1000; ++n)
    totalLetters += letterCount(n);
  cout << totalLetters << endl;
}
