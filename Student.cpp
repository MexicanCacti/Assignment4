#include "Student.h"

Student::Student() {
  this->lastName = "Doe";
  this->firstName = "John";
  this->ID = 123;
  this->pGradeAvg = -1;
  this->tGradeAvg = -1;
  this->fGradeAvg = -1;
  this->overallGrade = -1;
}

Student::Student(std::string lName, std::string fName, int ID, GradeBook& GradeBook) {
  ItemType defaultScore;
  defaultScore.Initialize(-1);    // default score -1, so when check if user has already recorded a grade for the program/test/final... value not being -1 indicates that already recorded
  this->lastName = lName;
  this->firstName = fName;
  this->ID = ID;
  this->pGradeAvg = -1;
  this->tGradeAvg = -1;
  this->fGradeAvg = -1;
  this->overallGrade = -1;
  
  Programs.setLength(GradeBook.pAssignments());
  for (int i = 0; i < Programs.GetLength(); i++) {
    Programs.SetItemIndex(i, defaultScore);
  }
  Tests.setLength(GradeBook.tAssignments());
  for (int i = 0; i < Tests.GetLength(); i++) {
    Tests.SetItemIndex(i, defaultScore);
  }
  Finals.setLength(GradeBook.fAssignments());
  for (int i = 0; i < Finals.GetLength(); i++) {
    Finals.SetItemIndex(i, defaultScore);
  }
}

Student::Student(std::string lName, std::string fName, int ID, float pGradeAvg, float tGradeAvg, float fGradeAvg, float overallGrade, GradeBook& GradeBook) {
  ItemType defaultScore;
  defaultScore.Initialize(-1);
  this->lastName = lName;
  this->firstName = fName;
  this->ID = ID;
  this->pGradeAvg = pGradeAvg;
  this->tGradeAvg = tGradeAvg;
  this->fGradeAvg = fGradeAvg;
  this->overallGrade = overallGrade;
  
  Programs.setLength(GradeBook.pAssignments());
  for (int i = 0; i < Programs.GetLength(); i++) {
    Programs.SetItemIndex(i, defaultScore);
  }
  Tests.setLength(GradeBook.tAssignments());
  for (int i = 0; i < Tests.GetLength(); i++) {
    Tests.SetItemIndex(i, defaultScore);
  }
  Finals.setLength(GradeBook.fAssignments());
  for (int i = 0; i < Finals.GetLength(); i++) {
    Finals.SetItemIndex(i, defaultScore);
  }
}

void Student::changeP(int pNum, float pVal) {
  ItemType item;
  item.Initialize(pVal);
  this->Programs.SetItemIndex(pNum, item);

}

void Student::changeT(int tNum, float tVal) {
  ItemType item;
  item.Initialize(tVal);
  this->Tests.SetItemIndex(tNum, item);
}

void Student::changeF(int fNum, float fVal) {
  ItemType item;
  item.Initialize(fVal);
  this->Finals.SetItemIndex(fNum, item);
}

void Student::calcOverall(GradeBook& GradeBook) {
  ItemType item;
  item.Initialize(0);
  float sum = 0;
  for (int i = 0; i < Programs.GetLength(); i++) {
    sum += Programs.GetItemIndex(i).getValue();
  }
  pGradeAvg = sum / Programs.GetLength();
  
  sum = 0;
  for (int i = 0; i < Tests.GetLength(); i++) {
    sum += Tests.GetItemIndex(i).getValue();
  }
  tGradeAvg = sum / Tests.GetLength();
  
  sum = 0;
  for (int i = 0; i < Finals.GetLength(); i++) {
    sum += Finals.GetItemIndex(i).getValue();
  }
  fGradeAvg = sum / Finals.GetLength();
  
  overallGrade = (pGradeAvg * (GradeBook.pPerc() / 100.0)) + (tGradeAvg * (GradeBook.tPerc()/ 100.0)) + (fGradeAvg * (GradeBook.fPerc() / 100.0));
}
<<<<<<< Updated upstream
=======

void Student::outputInfo(std::ostream& out) {
  ItemType temp;
  out << "Student Name: " << lastName << " " << firstName << " ID: " << ID << "\n";

  // output list of programming assignment grades
  out << "Programming Assignment Grades:";
  for (int i = 0; i < Programs.GetLength(); i++) {
    out << " ";
    temp = Programs.GetItemIndex(i);
    temp.Print(out);
  }
  out << "\nProgramming Grades Average: " << pGradeAvg << "\n";
  
  // output list of test grades
  out << "Test Grades:";
  for (int i = 0; i < Tests.GetLength(); i++) {
    out << " ";
    temp = Tests.GetItemIndex(i);
    temp.Print(out);
  }
  out << "\nTest Grades Average: " << tGradeAvg << "\n";
  
  // output list of finals scores
  out << "Final Exam Grades:";
  for (int i = 0; i < Finals.GetLength(); i++) {
    out << " ";
    temp = Finals.GetItemIndex(i);
    temp.Print(out);
  }
  out << "\nFinal Exam Grades Average: " << fGradeAvg << "\n";
  out << "Overall Grade Average: " << overallGrade;
  out << "\n\n";
}

void Student::recordInfo(std::ostream& out) {
  ItemType temp;
  out << lastName << " " << firstName << " " << ID << " " << pGradeAvg << " " << tGradeAvg << " " << fGradeAvg << " " << overallGrade << "\n";

  // output list of programming assignment grades
  for (int i = 0; i < Programs.GetLength(); i++) {
    temp = Programs.GetItemIndex(i);
    temp.Print(out);
    out << " ";
  }
  out << "\n";

  // output list of test grades
  for (int i = 0; i < Tests.GetLength(); i++) {
    temp = Tests.GetItemIndex(i);
    temp.Print(out);
    out << " ";
  }
  out << "\n";

  // output list of finals scores
  for (int i = 0; i < Finals.GetLength(); i++) {
    temp = Finals.GetItemIndex(i);
    temp.Print(out);
    out << " ";
  }
  out << "\n";
}
>>>>>>> Stashed changes
