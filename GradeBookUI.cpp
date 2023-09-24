#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "SortedType.h"
using namespace std;

struct GradeBook {
  int pNum;
  float pPer;
  int tNum;
  float tPer;
  int fNum;
  float fPer;
  GradeBook();
  void setUp(int, float, int, float, int, float);
  void clear();
};

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
  fNum = fPerc;
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

// these are to set what the max/min # of programs/tests/finals to user can input when setting up... keep in mind ItemType.h will need MAXITEMS to be updated to whatever the largest number is from this list
const int MAX_PROGRAMS = 6;
const int MIN_PROGRAMS = 0;
const int MAX_TESTS = 4;
const int MIN_TESTS = 0;
const int MAX_FINALS = 1;
const int MIN_FINALS = 0;


// user choice menu
void Menu(char&);

void setUpSemester(GradeBook&, ostream&); // ostream to pass it outfile for Grades.trn
void addStudent(SortedType&, ostream&);
void recordProgramming(SortedType&, ostream&);
void recordTest(SortedType&, ostream&);
void recordFinal(SortedType&, ostream&);
void changeGrade(SortedType&, ostream&);
void calculateGrade(SortedType&, ostream&);
void retrieveData(SortedType&, GradeBook&, ifstream&); // retrieves data from dat file -> update GradeBook info, all Student info
void storeData(SortedType&, GradeBook&, ostream&);     // stores data to dat file -> GradeBook info, Stores all Student info

int main() {
  char userChoice = ' '; // operation to be executed
  GradeBook GradeBook;   // stores Gradebook info, # of assignments... % of grade...
  SortedType Students;   // stores all of the student information, should be sorted by last name a->z ?
  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  
  inFile.open("Grades.dat");
  outFile.open("Grades.trn");
  
  /* CHECK IF DAT FILE EMPTY, FORCE USER TO SET UP NEW SEMESTER
  if ( ) {
    while (userChoice != 'Q' && userChoice != 'S') {
      cout << "First time running program, Press S to set up a new semester or Q to quit: ";
      cin >> userChoice;
      userChoice = toupper(userChoice);
    }
  }
  if (userChoice == 'Q') {
    inFile.close();
    return 0;
  }
  if (userChoice == 'S') {
    setUpSemester(GradeBook, outFile);
  }
  */
  
  //open grades.dat and store data, if empty make it so the user has to choose a new semester -> if first line is blank in other words.
  // then close grades.dat
  inFile.close();
  
  Menu(userChoice);
  // during while loop make sure to update to grade.trn
  while (userChoice != 'Q') {
    switch (userChoice) {
      case 'S':  
        setUpSemester(GradeBook, outFile);
        break;
      case 'A':
        addStudent(Students, outFile);
        break;
      case 'P':
        recordProgramming(Students, outFile);
        break;
      case 'T':
        recordTest(Students, outFile);
        break;
      case 'F':
        recordFinal(Students, outFile);
        break;
    }
    Menu(userChoice);
  }
  outFile.close();
  
  
  outFile.open("Grades.dat");
  
  // store all data into grades.dat

  outFile.close();
  
  
  return 0;
}

void Menu(char& Choice) {
  cout << right << setfill('-') << setw(100) << "\n";
  cout << "Please input a command:" << endl;
  cout << "S - Set up for a new semester\n" << endl;
  cout << "A - Add a student\n" << endl;
  cout << "P - Record programming assignment grade for all students\n" << endl;
  cout << "T - Record test grade for all students\n" << endl;
  cout << "F - Record Final exam grade for all students\n" << endl;
  cout << "C - Change a student's grade\n" << endl;
  cout << "G - Calculate final grades\n" << endl;
  cout << "O - Output grade data\n" << endl;
  cout << "Q - Quit\n" << endl;
  cout << right << setfill('-') << setw(100) << "\n";

  // ascii values for a -> z : 97 -> 122
  // ascii values for A -> Z : 65 -> 90
  // change while loop so that it also checks if it is one of the valid choices above!!!
  cin >> Choice;
  while (true) {
    Choice = toupper(Choice);
    switch (Choice) {
    case 'S': return;
    case 'A': return;
    case 'P': return;
    case 'T': return;
    case 'F': return;
    case 'C': return;
    case 'G': return;
    case 'O': return;
    case 'Q': return;
    }
    cout << "Not a valid input. Please look above for the valid characters." << endl;
    cin.ignore(10000, '\n');    // just so if user types in a string of letters/numbers/symbols, only checks the first letter/number/symbol... otherwise will use every input to check before prompting a new input
    cin >> Choice;
  }
  return;
}
void setUpSemester(GradeBook& GradeBook, ostream& out) {
  GradeBook.clear();
  
  int pAmount = 0;
  int tAmount = 0;
  int fAmount = 0;
  
  float pPerc = 0.0;
  float tPerc = 0.0;
  float fPerc = 0.0;
  
  cout << "# of Programming Assignments: ";
  cin >> pAmount;
  while (pAmount < MIN_PROGRAMS || pAmount > MAX_PROGRAMS) {
    cout << "\nInput in range " << MIN_PROGRAMS << " -> " << MAX_PROGRAMS << endl;
    cout << "# of Programming Assignments: ";
    cin >> pAmount;
  }
  
  cout << "# of Tests: ";
  cin >> tAmount;
  while (tAmount < MIN_TESTS || tAmount > MAX_TESTS) {
    cout << "\nInput in range " << MIN_TESTS << " -> " << MAX_TESTS << endl;
    cout << "# of Tests: ";
    cin >> tAmount;
  }
  
  cout << "# of Finals: ";
  cin >> fAmount;
  while (fAmount < MIN_FINALS || fAmount > MAX_FINALS) {
    cout << "\nInput in range " << MIN_FINALS << " -> " << MAX_FINALS << endl;
    cout << "# of Finals: ";
    cin >> fAmount;
  }
  
  cout << "\nRelative % of Programs: ";
  cin >> pPerc;
  cout << "\nRelative % of Tests: ";
  cin >> tPerc;
  cout << "\nRelative % of Finals: ";
  cin >> fPerc;
  
  while (pPerc + tPerc + fPerc != 100) {
    cout << "\nPlease check that the relative % add up to 100" << endl;
    cout << "\nRelative % of Programs: ";
    cin >> pPerc;
    cout << "\nRelative % of Tests: ";
    cin >> tPerc;
    cout << "\nRelative % of Finals: ";
    cin >> fPerc;
  }
    GradeBook.setUp(pAmount, pPerc, tAmount, tPerc, fAmount, fPerc);

    // FIX OUTPUTTING TO LOOK MORE OFFICIAL!!!!
    out << "GradeBook Updated" << endl;
    out << "\tProgramming Assignments: " << pAmount << "\tRelative Weight: " << pPerc << endl;
    out << "\tTests: " << tAmount << "\tRelative Weight: " << tPerc << endl;
    out << "\tFinal Exams: " << fAmount << "\tRelative Weight: " << fPerc << endl;
  
}
void addStudent(SortedType& Students, ostream& out) {

}
void recordProgramming(SortedType& Students, ostream& out) {

}
void recordTest(SortedType& Students, ostream& out) {

}
void recordFinal(SortedType& Students, ostream& out) {

}
void retrieveData(SortedType& Students, GradeBook& Gradebook, ifstream& in) {

}
void storeData(SortedType& Students, GradeBook& GradeBook, ostream& out) {

}