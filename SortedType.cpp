/***************************************************************************************
*    Title: C++ Plus Data Structures SIXTH EDITION
*    Author: Nell Dale, Chip Weems
*    Date: 09/14/2023
*    Code version: C++11
*    Availability: Chapter 4
*
***************************************************************************************/

#include "SortedType.h"

bool SortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int SortedType::GetLength() const
{
  return length;
}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
  int midPoint;
  int first = 0;
  int last = length - 1;

  bool moreToSearch = first <= last;
  found = false;
  while (moreToSearch && !found)
  {
    midPoint = (first + last) / 2;
    switch (item.ComparedTo(info[midPoint]))
    {
    case LESS: last = midPoint - 1;
      moreToSearch = first <= last;
      break;
    case GREATER: first = midPoint + 1;
      moreToSearch = first <= last;
      break;
    case EQUAL: found = true;
      item = info[midPoint];
      break;
    }
  }
  return item;
}

void SortedType::DeleteItem(ItemType item)
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;
  for (int index = location + 1; index < length; index++)
    info[index - 1] = info[index];
  length--;
}

void SortedType::PutItem(ItemType item)
{
  bool moreToSearch;
  int location = 0;

  moreToSearch = (location < length);
  while (moreToSearch)
  {
    switch (item.ComparedTo(info[location]))
    {
    case LESS: moreToSearch = false;
      break;
    case GREATER: location++;
      moreToSearch = (location < length);
      break;
    }
  }
  for (int index = length; index > location; index--)
    info[index] = info[index - 1];
  info[location] = item;
  length++;
}

void SortedType::ResetList()
// Post: currentPos has been initialized.
{
  currPos = -1;
}

ItemType SortedType::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
  currPos++;
  return info[currPos];
}