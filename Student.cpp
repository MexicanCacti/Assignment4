#include "Student.h"
  
Student::Student() {
  this->lastName = "Doe";
  this->firstName = "John";
  this->ID = 123;
  this->pGradeAvg = 100;
  this->tGradeAvg = 100;
  this->fGradeAvg = 100;
  this->overallGrade = 100;
}

Student::Student(std::string lName, std::string fName, int ID) {
  this->lastName = lName;
  this->firstName = fName;
  this->ID = ID;
  this->pGradeAvg = 100;
  this->tGradeAvg = 100;
  this->fGradeAvg = 100;
  this->overallGrade = 100;
}

void Student::changeP(int pNum, float pVal, std::ostream& out) {
    

}

void Student::changeT(int tNum, float tVal, std::ostream& out) {

}

void Student::changeF(int fNum, float fVal, std::ostream& out) {

}

void Student::calcOverall(float pPer, float tPer, float fPer, std::ostream& out) {
  // put formula for calculating overall with relative percent
  this->overallGrade = 0;
}
