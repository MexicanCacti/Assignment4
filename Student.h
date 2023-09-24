#pragma once
#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H
#include "UnsortedType.h"

class Student {
  private:
    std::string lastName;
    std::string firstName;
    int ID;
    float pGradeAvg;
    float tGradeAvg;
    float fGradeAvg;
    float overallGrade;
    /* Have arrays to store the grades for each programming assignment/ Test/ Final... thinking of using UnsortedList*/
  
  public:
    Student();                                      
    Student(std::string lName, std::string fName, int ID);
    // create another consructor that ALSO takes in the Grade avgs & array for each assignment/test/final grades

    // the ostream are so whenever these are changed, can update in Grades.trn
    void changeP(int pNum, float pVal, std::ostream& out);                         // change programming # grade
    void changeT(int tNum, float tVal, std::ostream& out);                         // change test # grade
    void changeF(int fNum, float fVal, std::ostream& out);                          // change final exam grade
    void calcOverall(float pPer, float tPer, float fPer, std::ostream& out);
    inline float getOverall() {return overallGrade;}
};
#endif