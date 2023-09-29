#include "StudentList.h"

StudentList::StudentList() {
  length = 0;
  head = NULL;
}

StudentList::~StudentList() {
  Node* temp = head;
  
  while (head != NULL) {
    head = head->next;
    delete temp;
    temp = head;
  }
}

void StudentList::PutStudent(Student& student) {
  try {
    length++;
    Node* newNode = new Node();
    newNode->student = student;
    
    // if strcmp > 0, then rightside student lastName comes before left side student's 
    if (head == NULL || strcmp(head->student.getLastName().c_str(), student.getLastName().c_str()) > 0) {
      newNode->next = head;
      head = newNode;
      return;
    }
    
    Node* loc = head->next;
    Node* prev = head;
    
    while (loc != NULL) {
      if (strcmp(head->student.getLastName().c_str(), student.getLastName().c_str()) > 0) {
        prev->next = newNode;
        newNode->next = head;
        return;
      }
      prev = loc;
      loc = loc->next;
    }
    prev->next = newNode;
  
  }
  catch (std::bad_alloc exception) {
    return;
  }
}

void StudentList::DeleteStudent(Student& student) {
  if (length == 0) {  // no items in list, no items to delete
    return;
  }
  length--;
  Node* location = head;

  if (head->student.getID() == student.getID()) {   // special rule if item to delete first in list
    head = head->next;
    delete location;
    return;
  }

  location = head->next;
  Node* prevLoc = head;

  while (location->next != NULL) {
    if (location->student.getID() == student.getID()) {
      prevLoc->next = location->next;
      delete location;
      return;
    }
    prevLoc = location;
    location = location->next;
  }

  if (location->student.getID() == student.getID()) {
    location = NULL;
  }
  return;
}

Student& StudentList::GetStudentByID(int ID, bool& found) {
  Node* temp = head;
  
  while (temp != NULL) {
    if (temp->student.getID() == ID) {
      found = true;
      return temp->student;
    }
    temp = temp->next;
  }
  found = false;
  return head->student;
}

void StudentList::ResetList() {
  currPos = NULL;
}

Student StudentList::GetNextStudent() {
  if (currPos == NULL) {
    currPos = head;
    return currPos->student;
  }
  if (currPos->next == NULL) {
    return currPos->student;
  }
  
  currPos = currPos->next;
  return currPos->student;
}

Student& StudentList::GetStudentByIndex(int index) {
  if (index > length) {
    return head->student;
  }
  
  Node* temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->student;
}

void StudentList::MakeEmpty() {
  Node* temp = head;
  
  while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
  length = 0;
}

