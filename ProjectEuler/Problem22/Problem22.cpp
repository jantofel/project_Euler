// Problem22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <string>
#include <set>

const char* FILENAME = "p022_names.txt";

int calcValue(const std::string& name);

int main()
{
  std::ifstream file(FILENAME);
  std::string line;
  std::set<std::string> ordered_names;

  while (std::getline(file, line, ','))
  {
    ordered_names.emplace(line.substr(1, line.length() - 2));
  }
  
  int i = 0;
  long long totalScores = 0;
  for (const auto& name : ordered_names)
  {
    ++i;
    int value = calcValue(name);
    int score = value * i;
    totalScores += score;
    // A sanity check
    //if (name == "COLIN")
    //{
    //  printf("%s is %dth, his value is %d and his score is %d\r\n", name.c_str(), i, value, score);
    //}
    // An overflow check
    if (totalScores < 0)
    {
      printf("Need to use larger variable\r\n");
    }
  }
  printf("The total is %lld\r\n", totalScores);
  return 0;
}

int calcValue(const std::string& name)
{
  int value = 0;
  for (char c : name)
  {
    value += c - 'A' + 1;
  }
  return value;
}
