#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "SortedType.h"
#include "Student.h"
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
  void outputValues(ostream&) const;
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

void GradeBook::outputValues(ostream& out) const {
  out << pNum << " " << pPer << " " << tNum << " " << tPer << " " << fNum << " " << fPer << endl;
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

void setUpSemester(SortedType&, GradeBook&, ostream&); // ostream to pass it outfile for Grades.trn
void addStudent(SortedType&, ostream&);
void recordProgramming(SortedType&, ostream&);
void recordTest(SortedType&, ostream&);
void recordFinal(SortedType&, ostream&);
void changeGrade(SortedType&, ostream&);
void calculateGrade(SortedType&, ostream&);
void retrieveData(SortedType&, GradeBook&, ifstream&, ostream& out); // retrieves data from dat file -> update GradeBook info, all Student info
void storeData(SortedType&, GradeBook&, ostream&);     // stores data to dat file -> GradeBook info, Stores all Student info

int main() {
  char userChoice = ' '; // operation to be executed
  GradeBook GradeBook;   // stores Gradebook info, # of assignments... % of grade...
  SortedType Students;   // stores all of the student information, should be sorted by last name a->z ?
  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  
  inFile.open("Grades.dat");
  outFile.open("Grades.trn");
  
  if (inFile.peek() == EOF) {
    while (userChoice != 'Q' && userChoice != 'S') {
      cout << "First time running program, Press S to set up a new semester or Q to quit: ";
      cin >> userChoice;
      userChoice = toupper(userChoice);
    }
    if (userChoice == 'Q') {
      inFile.close();
      return 0;
    }
    if (userChoice == 'S') {
      setUpSemester(Students, GradeBook, outFile);
    }
  }
  else {
    retrieveData(Students, GradeBook, inFile, outFile);
  }
  
  inFile.close();
  
  Menu(userChoice);
  while (userChoice != 'Q') {
    switch (userChoice) {
      case 'S':  
        setUpSemester(Students, GradeBook, outFile);
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
  
  outFile << "Stored data to Grades.dat" << endl;
  outFile.close();
  outFile.open("Grades.dat");
  
  // store data into Grades.dat
  storeData(Students, GradeBook, outFile);

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
    cin.ignore(1000, '\n');    // just so if user types in a string of letters/numbers/symbols, only checks the first letter/number/symbol... otherwise will use every input to check before prompting a new input
    cin >> Choice;
  }
  return;
}
void setUpSemester(SortedType& Students, GradeBook& GradeBook, ostream& out) {
  GradeBook.clear();
  Students.MakeEmpty();
  
  int pAmount = 0;
  int tAmount = 0;
  int fAmount = 0;
  
  float pPerc = 0.0;
  float tPerc = 0.0;
  float fPerc = 0.0;
  
  cout << "# of Programming Assignments: ";
  cin >> pAmount;
  while (pAmount < MIN_PROGRAMS || pAmount > MAX_PROGRAMS || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << MIN_PROGRAMS << " -> " << MAX_PROGRAMS << endl;
    cout << "# of Programming Assignments: ";
    cin >> pAmount;
  }
  cin.ignore(1000, '\n');

  cout << "# of Tests: ";
  cin >> tAmount;
  while (tAmount < MIN_TESTS || tAmount > MAX_TESTS || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << MIN_TESTS << " -> " << MAX_TESTS << endl;
    cout << "# of Tests: ";
    cin >> tAmount;
  }
  cin.ignore(1000, '\n');
  
  cout << "# of Finals: ";
  cin >> fAmount;
  while (fAmount < MIN_FINALS || fAmount > MAX_FINALS || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << MIN_FINALS << " -> " << MAX_FINALS << endl;
    cout << "# of Finals: ";
    cin >> fAmount;
  }
  cin.ignore(1000, '\n');
  
  while (pPerc + tPerc + fPerc != 100.0) {
    cout << "\nMake sure that the relative %s add up to 100" << endl;
    cout << "\nRelative % of Programs: ";
    cin >> pPerc;
    while (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nInput a number please: ";
      cin >>pPerc;
    }
    cin.ignore(1000, '\n');

    cout << "\nRelative % of Tests: ";
    cin >> tPerc;
    while (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nInput a number please: ";
      cin >> tPerc;
    }
    cin.ignore(1000, '\n');

    cout << "\nRelative % of Finals: ";
    cin >> fPerc;
    while (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nInput a number please: ";
      cin >> fPerc;
    }
    cin.ignore(1000, '\n');
  }
    GradeBook.setUp(pAmount, pPerc, tAmount, tPerc, fAmount, fPerc);

    // FIX OUTPUTTING TO LOOK MORE OFFICIAL!!!!
    out << "GradeBook Updated" << endl;
    out << "\tProgramming Assignments: " << pAmount << "\tRelative Weight: " << pPerc << endl;
    out << "\tTests: " << tAmount << "\tRelative Weight: " << tPerc << endl;
    out << "\tFinal Exams: " << fAmount << "\tRelative Weight: " << fPerc << endl;
  
}
void addStudent(SortedType& Students, ostream& out) {
  string lastName;
  string firstName;
  int studentNumber = 0;
  ItemType item;
  cout << "Enter Student's last name: ";
  cin.ignore(1000, '\n');
  getline(cin, lastName);
  // resize so max string length is 20, if less -> fills with spaces
  lastName.resize(20);
  cout << "\nEnter Student's first name: ";
  getline(cin,firstName);
  firstName.resize(20);
  
  cout << "\nEnter Student's ID number: ";
  cin >> studentNumber;
  while (studentNumber < 0 || studentNumber > 9999 || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nStudent number needs to be in range 0 -> 9999\nEnter Student's ID number: ";
    cin >> studentNumber;
  }
  cin.ignore(1000, '\n');

  Student newStudent(lastName, firstName, studentNumber); // create a new student object
  // add student to a list
  
  // FIX OUTPUTTING TO LOOK MORE OFFICIAL!!!!
  out << "Student Added" << endl;
  out << "\tLastName: " << lastName << "\tFirstName: " << firstName << "\tID Number: " << studentNumber << endl;
}
void recordProgramming(SortedType& Students, ostream& out) {
  // have a while loop to eval the program # is > 0 && < Students.Programs.getLength()
}
void recordTest(SortedType& Students, ostream& out) {

}
void recordFinal(SortedType& Students, ostream& out) {

}
void retrieveData(SortedType& Students, GradeBook& Gradebook, ifstream& in, ostream& out) {
  int pNum = 0;
  float pPer = 0.0;
  int tNum = 0;
  float tPer = 0.0;
  int fNum = 0;
  float fPer = 0.0;
  
  // sets up the gradebook to be what was last inputted
  in >> pNum;
  in.ignore();
  in >> pPer;
  in.ignore();
  in >> tNum;
  in.ignore();
  in >> tPer;
  in.ignore();
  in >> fNum;
  in.ignore();
  in >> fPer;
  Gradebook.setUp(pNum, pPer, tNum, tPer, fNum, fPer);
  
  // every line after this should contain all the info to create a student object
  
  out << "Previous Data Inputted" << endl;
  
}
void storeData(SortedType& Students, GradeBook& GradeBook, ostream& out) {
  // stores the gradebook values onto one line... # of each type of assignment, percentages
  GradeBook.outputValues(out);
  
  // stores all info of student object onto one line
  Students.ResetList();
  for (int i = 0; i < Students.GetLength(); i++) {
    Students.GetNextItem().Print(out);
  }
}