#include <iostream>
#include "large_number.cpp"

using namespace std;

int main(int argc, char** argv)
{ 
  int counter = 2;
  LargeNumber *ln1 = new LargeNumber();
  LargeNumber *ln2 = new LargeNumber();

  ln1 -> init (1L);
  ln2 -> init (1L);
  
  while (ln1 -> underlying_list.size () < 334 &&
         ln2 -> underlying_list.size () < 334)
    {
      ln1 -> add (ln2);
      ln2 -> add (ln1);
      counter += 2;
    }
  if (ln1 -> underlying_list.size () == 334)
    {
      // cout << ln1 -> toString () << endl;
      --counter;
    }
  else 
    {
      // cout << ln2 -> toString () << endl;
    }
  cout << "The first 1000 digit fibonacci's number is " << counter
       << "th in the sequence." << endl;
  delete (ln1);
  delete (ln2);
}
