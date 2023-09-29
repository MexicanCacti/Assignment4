#include "GradeBook.h"

GradeBook::GradeBook() {
  pNum = 0;
  pPer = 0.0;
  tNum = 0;
  tPer = 0.0;
  fNum = 0;
  fPer = 0.0;
}

void GradeBook::setUp(int pAmount, float pPerc, int tAmount, float tPerc, int fAmount, float fPerc) {
  pNum = pAmount;
  pPer = pPerc;
  tNum = tAmount;
  tPer = tPerc;
  fNum = fAmount;
  fPer = fPerc;
}
void GradeBook::clear() {
  pNum = 0;
  pPer = 0.0;
  tNum = 0;
  tPer = 0.0;
  fNum = 0;
  fPer = 0.0;
}
void GradeBook::outputValues(std::ostream& out) const {
  out << "Programming Assignments: " << pNum << "\t % of grade: " << pPer << std::endl;
  out << "Tests: " << tNum << "\t % of grade: " << tPer << std::endl;
  out << "Finals: " << fNum << "\t % of grade: " << fPer << std::endl;
}
void GradeBook::recordValues(std::ostream& out) const {
  out << pNum << " " << pPer << " " << tNum << " " << tPer << " " << fNum << " " << fPer << std::endl;
}