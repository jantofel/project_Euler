#include "large_number.h"
#include <sstream>
#include <stdlib.h>

void LargeNumber::init ()
{
  this -> underlying_list.clear ();
  this -> underlying_list.push_front (0);
}

void LargeNumber::init (long number)
{
  this -> underlying_list.clear ();
  while (number > 999)
    {
      this -> underlying_list.push_front (number % 1000);
      number /= 1000;
    }
  this -> underlying_list.push_front (number);
}

void LargeNumber::init (std::string number)
{
  this -> underlying_list.clear ();
  for (int i = (number.length () - 1); i >= 0; i -= 3)
    {
      std::string to_insert = "";
      if (i >= 2)
        to_insert += number[i-2];
      if (i >= 1)
        to_insert += number[i-1];
      to_insert += number[i];
      this -> underlying_list.push_front (atol (to_insert.c_str ()));
    }
}

void LargeNumber::add (LargeNumber *other)
{
  int this_length = this -> underlying_list.size ();
  int other_length = other -> underlying_list.size ();
  std::list<long>::reverse_iterator it = this -> underlying_list.rbegin ();
  std::list<long>::reverse_iterator other_it = other -> underlying_list.rbegin();

  int carry = 0;
  while ((it != this -> underlying_list.rend ()) &&
         (other_it != other -> underlying_list.rend ()))
    {
      int temp = (*it) + (*other_it) + carry;
      *it = temp % 1000;
      carry = temp / 1000;
      ++it;
      ++other_it;
    }

  if (it != this -> underlying_list.rend ())
    {
      while ((it != this -> underlying_list.rend ()) && carry != 0)
        {
          int temp = (*it) + carry;
          *it = temp % 1000;
          carry = temp / 1000;
          ++it;
        }
    }

  else
    {
      while ((other_it != other -> underlying_list.rend ()))
        {
          int temp = (*other_it) + carry;
          this -> underlying_list.push_front (temp % 1000);
          carry = temp / 1000;
          ++ other_it;
        } 
    }

  if (carry != 0)
    {
      this -> underlying_list.push_front (carry);
    }
}

void LargeNumber::add (long number)
{
  LargeNumber *other = new LargeNumber ();
  other -> init (number);
  this -> add (other);
  delete (other);
}

void LargeNumber::multiply (LargeNumber *other)
{
  // TODO: Implement multiplication
}

void LargeNumber::multiply (long number)
{
  LargeNumber *other = new LargeNumber ();
  other -> init (number);
  this -> multiply (other);
  delete (other);
}

std::string LargeNumber::toString ()
{
  return this -> toString ("");
}

std::string LargeNumber::toString (std::string separator)
{
  std::stringstream str_builder;
  for (std::list<long>::iterator iterator = this -> underlying_list.begin ();
       iterator != this -> underlying_list.end ();
       ++iterator)
    {
      if (*iterator < 100 && iterator != this -> underlying_list.begin ())
        {
          str_builder << "0";
        }
      if (*iterator < 10 && iterator != this -> underlying_list.begin ())
        {
          str_builder << "0";
        }
      str_builder << *iterator << separator;
    }
  return str_builder.str();
}

int LargeNumber::numberOfDigits ()
{
  int number_of_digits = this -> underlying_list.size ();
  number_of_digits *= 3;
  long front = this -> underlying_list.front ();
  if (front < 100)
    {
      --number_of_digits;
    }
  if (front < 10)
    {
      --number_of_digits;
    }
  return number_of_digits;
}
