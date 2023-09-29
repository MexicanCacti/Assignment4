/***************************************************************************************
*    Title: C++ Plus Data Structures SIXTH EDITION
*    Author: Nell Dale, Chip Weems
*    Date: 09/14/2023
*    Code version: C++11
*    Availability: Chapter 3
*
***************************************************************************************/
#include <fstream>
#include <iostream>
#include "ItemType.h"

ItemType::ItemType()
{
  value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number)
{
  value = number;
}
void ItemType::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value;
}
