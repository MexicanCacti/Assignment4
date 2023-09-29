#pragma once
#include <iostream>
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

class GradeBook {
  private:
    int pNum;
    float pPer;
    int tNum;
    float tPer;
    int fNum;
    float fPer;
  
  public:
    GradeBook();
    int pAssignments() { return pNum; }
    int tAssignments() { return tNum; }
    int fAssignments() { return fNum; }
    float pPerc() {return pPer;}
    float tPerc() {return tPer;}
    float fPerc() {return fPer;}
    void setUp(int, float, int, float, int, float);
    void clear();
    void outputValues(std::ostream&) const;
    void recordValues(std::ostream&) const;
};

#endif