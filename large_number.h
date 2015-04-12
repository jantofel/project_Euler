#ifndef LARGE_NUMBER_H
#define LARGE_NUMBER_H

#include <list>

class LargeNumber
{
 public:
  std::list<long> underlying_list; 

  void init ();
  void init (long);
  void init (std::string);
  void add (LargeNumber*);
  void add (long);
  void multiply (LargeNumber*);
  void multiply (long);
  std::string toString ();
  std::string toString (std::string);
  int numberOfDigits ();
};

#endif
