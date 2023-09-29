#pragma once
#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H
#include "UnsortedType.h"
#include "GradeBook.h"

class Student {
  private:
    std::string lastName;
    std::string firstName;
    int ID;
    float pGradeAvg;
    float tGradeAvg;
    float fGradeAvg;
    float overallGrade;
    UnsortedType Programs;
    UnsortedType Tests;
    UnsortedType Finals;
  
  public:
    Student();                                      
<<<<<<< Updated upstream
    Student(std::string lName, std::string fName, int ID);
    // create another consructor that ALSO takes in the Grade avgs & array for each assignment/test/final grades

    // the ostream are so whenever these are changed, can update in Grades.trn
    void changeP(int pNum, float pVal, std::ostream& out);                         // change programming # grade
    void changeT(int tNum, float tVal, std::ostream& out);                         // change test # grade
    void changeF(int fNum, float fVal, std::ostream& out);                          // change final exam grade
    void calcOverall(float pPer, float tPer, float fPer, std::ostream& out);
    inline float getOverall() {return overallGrade;}
=======
    Student(std::string lName, std::string fName, int ID, GradeBook& GradeBook );
    Student(std::string lName, std::string fName, int ID, float pGradeAvg, float tGradeAvg, float fGradeAvg, float overallGrade, GradeBook& GradeBook);
    
    int getID() const {return ID;}
    std::string getLastName() const {return lastName;}
    std::string getFirstName() const {return firstName;}
    void changeP(int pNum, float pVal);                         // change programming # grade
    void changeT(int tNum, float tVal);                         // change test # grade
    void changeF(int fNum, float fVal);                          // change final exam grade
    void calcOverall(GradeBook& GradeBook);
    float getOverall() {return overallGrade;}
    void outputInfo(std::ostream& out);                                                  // outputs all of the student information in a line
    void recordInfo(std::ostream& out);
    ItemType getProgramGrade(int pNum) {return Programs.GetItemIndex(pNum); }
    ItemType getTestGrade(int tNum) { return Tests.GetItemIndex(tNum); }
    ItemType getFinalGrade(int fNum) { return Finals.GetItemIndex(fNum); }
>>>>>>> Stashed changes
};
#endif