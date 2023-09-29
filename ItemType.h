#pragma once
/***************************************************************************************
*    Title: C++ Plus Data Structures SIXTH EDITION
*    Author: Nell Dale, Chip Weems
*    Date: 09/14/2023
*    Code version: C++11
*    Availability: Chapter 3
*
***************************************************************************************/

#include <fstream>
const int MAX_ITEMS = 6;
enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
  int getValue() {return value;}
private:
  int value;
};


