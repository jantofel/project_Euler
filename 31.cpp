// flag '-std=c++0x' or flag 'std=gnu++0x' must be specified when compiling

#include <iostream>
#include <vector>

using namespace std;

vector<int> COINS_TO_USE {200,100,50,20,10,5,2,1};


int numberOfWays(int money_amount, vector<int> coins_to_use);


int numberOfWays(int money_amount)
{
  return numberOfWays(money_amount, COINS_TO_USE);
}


int numberOfWays(int money_amount, vector<int> coins_to_use)
{
  if (money_amount == 0)
    return 1;
  
  int ways = 0;
  for (vector<int>::iterator it = coins_to_use.begin();
       it != coins_to_use.end();
       ++it)
    {
      if (money_amount >= *it)
        {
          vector<int> new_coins_to_use (it, coins_to_use.end() );
          ways += numberOfWays(money_amount - *it, new_coins_to_use);
        }
    }
  return ways;
}


int main(int argc, char** argv)
{
  int money_amount = 200;

  int number_of_ways = numberOfWays(money_amount);

  cout << number_of_ways << endl;
}
