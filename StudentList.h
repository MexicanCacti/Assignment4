#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"

struct Node {
  Student student;
  Node* next;
};

class StudentList {
  private:
    Node* head;
    Node* currPos;
    int length;
    
   public:
     StudentList();
    ~StudentList();
    int GetLength() {return length;}
    void PutStudent(Student& student);
    void DeleteStudent(Student& student);
    Student& GetStudentByID(int ID, bool& found);
    Student& GetStudentByIndex(int index);
    void ResetList();
    Student GetNextStudent();
    void MakeEmpty();
};



#endif