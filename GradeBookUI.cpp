#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

<<<<<<< Updated upstream
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
=======
#include "StudentList.h"
#include "Student.h"
using namespace std;

// these are to set what the max # of programs/tests/finals to user can input when setting up... keep in mind ItemType.h will need MAXITEMS to be updated to whatever the largest number is from this list
>>>>>>> Stashed changes
const int MAX_PROGRAMS = 6;
const int MAX_TESTS = 4;
const int MAX_FINALS = 1;


// user choice menu
void Menu(char&);
<<<<<<< Updated upstream

void setUpSemester(GradeBook&, ostream&); // ostream to pass it outfile for Grades.trn
void addStudent(SortedType&, ostream&);
void recordProgramming(SortedType&, ostream&);
void recordTest(SortedType&, ostream&);
void recordFinal(SortedType&, ostream&);
void changeGrade(SortedType&, ostream&);
void calculateGrade(SortedType&, ostream&);
void retrieveData(SortedType&, GradeBook&, ifstream&); // retrieves data from dat file -> update GradeBook info, all Student info
void storeData(SortedType&, GradeBook&, ostream&);     // stores data to dat file -> GradeBook info, Stores all Student info
=======
void setUpSemester(StudentList&, GradeBook&, ostream&); // ostream to pass it outfile for Grades.trn
void addStudent(StudentList&, GradeBook&, ostream&);
void recordProgramming(StudentList&, GradeBook&, ostream&);
void recordTest(StudentList&, GradeBook&, ostream&);
void recordFinal(StudentList&, GradeBook&, ostream&);
void changeGrade(StudentList&, GradeBook&, ostream&);
void calculateGrade(StudentList&, GradeBook&, ostream&);
void outputGradeData(StudentList&, GradeBook&, ostream&);
void retrieveData(StudentList&, GradeBook&, ifstream&, ostream&); // retrieves data from dat file -> update GradeBook info, all Student info
void storeData(StudentList&, GradeBook&, ostream&);     // stores data to dat file -> GradeBook info, Stores all Student info
>>>>>>> Stashed changes

int main() {
  char userChoice = ' '; // operation to be executed
  GradeBook GradeBook;   // stores Gradebook info, # of assignments... % of grade...
  StudentList Students;   // a list of every student, sorted by last name a->z 
  ifstream inFile;       // file containing input
  ofstream outFile;      // file containing output

  inFile.open("Grades.dat");
  outFile.open("Grades.trn");
<<<<<<< Updated upstream
  
  /* CHECK IF DAT FILE EMPTY, FORCE USER TO SET UP NEW SEMESTER
  if ( ) {
=======

  if (inFile.peek() == EOF) {
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
  if (userChoice == 'S') {
    setUpSemester(GradeBook, outFile);
  }
  */
  
  //open grades.dat and store data, if empty make it so the user has to choose a new semester -> if first line is blank in other words.
  // then close grades.dat
=======
>>>>>>> Stashed changes
  inFile.close();

  Menu(userChoice);
  // during while loop make sure to update to grade.trn
  while (userChoice != 'Q') {
    switch (userChoice) {
<<<<<<< Updated upstream
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
=======
    case 'S':
      setUpSemester(Students, GradeBook, outFile);
      break;
    case 'A':
      addStudent(Students, GradeBook, outFile);
      break;
    case 'P':
      recordProgramming(Students, GradeBook, outFile);
      break;
    case 'T':
      recordTest(Students, GradeBook, outFile);
      break;
    case 'F':
      recordFinal(Students, GradeBook, outFile);
      break;
    case 'C':
      changeGrade(Students, GradeBook, outFile);
      break;
    case 'G':
      calculateGrade(Students, GradeBook, outFile);
      break;
    case 'O':
      outFile.close();
      outFile.open("Grades.out");
      outputGradeData(Students, GradeBook, outFile);
      outFile.close();
      outFile.open("Grades.trn");
      outFile << "Grade data outputted to Grade.Out" << endl;
      break;
    }
    Menu(userChoice);
  }
  outFile << "Stored data to Grades.dat" << endl;
>>>>>>> Stashed changes
  outFile.close();
  
  
  outFile.open("Grades.dat");
<<<<<<< Updated upstream
  
  // store all data into grades.dat
=======

  // store data into Grades.dat
  storeData(Students, GradeBook, outFile);
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
void setUpSemester(GradeBook& GradeBook, ostream& out) {
  GradeBook.clear();
  
=======
void setUpSemester(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  GradeBook.clear();
  Students.MakeEmpty();

>>>>>>> Stashed changes
  int pAmount = 0;
  int tAmount = 0;
  int fAmount = 0;

  float pPerc = 0.0;
  float tPerc = 0.0;
  float fPerc = 0.0;

  cout << "# of Programming Assignments: ";
  cin >> pAmount;
<<<<<<< Updated upstream
  while (pAmount < MIN_PROGRAMS || pAmount > MAX_PROGRAMS) {
    cout << "\nInput in range " << MIN_PROGRAMS << " -> " << MAX_PROGRAMS << endl;
=======
  while (pAmount < 0 || pAmount > MAX_PROGRAMS || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << 0 << " -> " << MAX_PROGRAMS << endl;
>>>>>>> Stashed changes
    cout << "# of Programming Assignments: ";
    cin >> pAmount;
  }
  
  cout << "# of Tests: ";
  cin >> tAmount;
<<<<<<< Updated upstream
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
=======
  while (tAmount < 0 || tAmount > MAX_TESTS || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << 0 << " -> " << MAX_TESTS << endl;
    cout << "# of Tests: ";
    cin >> tAmount;
  }
  cin.ignore(1000, '\n');

  cout << "# of Finals: ";
  cin >> fAmount;
  while (fAmount < 0 || fAmount > MAX_FINALS || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << 0 << " -> " << MAX_FINALS << endl;
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
      cin >> pPerc;
    }
    cin.ignore(1000, '\n');

>>>>>>> Stashed changes
    cout << "\nRelative % of Tests: ";
    cin >> tPerc;
    cout << "\nRelative % of Finals: ";
    cin >> fPerc;
  }
  GradeBook.setUp(pAmount, pPerc, tAmount, tPerc, fAmount, fPerc);

  out << "GradeBook Updated" << endl;
  out << "\tProgramming Assignments: " << pAmount << "\tRelative Weight: " << pPerc << endl;
  out << "\tTests: " << tAmount << "\tRelative Weight: " << tPerc << endl;
  out << "\tFinal Exams: " << fAmount << "\tRelative Weight: " << fPerc << endl;

}
<<<<<<< Updated upstream
void addStudent(SortedType& Students, ostream& out) {

}
void recordProgramming(SortedType& Students, ostream& out) {

=======
void addStudent(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  string lastName;
  string firstName;
  int studentNumber = 0;
  ItemType item;
  cout << "Enter Student's last name: ";
  cin.ignore(1000, '\n');
  getline(cin, lastName);
  // resize so max string length is 20, if less -> fills with spaces then trims
  lastName.resize(20);
  remove_if(lastName.begin(), lastName.end(), isspace);
  cout << "\nEnter Student's first name: ";
  getline(cin, firstName);
  firstName.resize(20);
  remove_if(firstName.begin(), firstName.end(), isspace);

  cout << "\nEnter Student's ID number: ";
  cin >> studentNumber;
  while (studentNumber < 0 || studentNumber > 9999 || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nStudent number needs to be in range 0 -> 9999\nEnter Student's ID number: ";
    cin >> studentNumber;
  }
  cin.ignore(1000, '\n');

  Student newStudent(lastName, firstName, studentNumber, GradeBook); // create a new student object
  Students.PutStudent(newStudent);

  out << "Student Added" << endl;
  out << "\tLastName: " << lastName << "\tFirstName: " << firstName << "\tID Number: " << studentNumber << endl;
}
void recordProgramming(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  if (Students.GetLength() == 0 || GradeBook.pAssignments() == 0) {
    cout << "No Programming Assingments to Grade" << endl;
    return;
  }
  
  ItemType defaultScore;
  defaultScore.Initialize(-1);
  int pNum = 0;
  float pGrade = 0.0;
  cout << "Enter Programming Assignment # to grade: ";
  cin >> pNum;
  while (pNum < 0 || pNum > GradeBook.pAssignments() - 1 || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << 0 << " -> " << GradeBook.pAssignments() - 1 << endl;
    cout << "Enter Programming Assignment # to grade: ";
    cin >> pNum;
  }
  if (Students.GetStudentByIndex(0).getProgramGrade(pNum).ComparedTo(defaultScore) != EQUAL) {
    cout << "Program #" << pNum << " already recorded." << endl;
    return;
  }
  cin.ignore(1000, '\n');
  
  for (int i = 0; i < Students.GetLength(); i++) {
    cout << "Enter Grade for " << Students.GetStudentByIndex(i).getLastName() << " " << Students.GetStudentByIndex(i).getFirstName() << ": ";
    cin >> pGrade;
    while (cin.fail() || pGrade < 0) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid Grade, Input again: ";
      cin >> pGrade;
    }
    cin.ignore(1000, '\n');
    Students.GetStudentByIndex(i).changeP(pNum,pGrade);
  }
  out << "Students' Programming Assignment #" << pNum << " Updated." << endl;
}
void recordTest(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  if (Students.GetLength() == 0 || GradeBook.tAssignments() == 0) {
    cout << "No Tests to Grade" << endl;
    return;
  }
  
  ItemType defaultScore;
  defaultScore.Initialize(-1);
  int tNum = 0;
  float tGrade = 0.0;
  cout << "Enter Test # to grade: ";
  cin >> tNum;
  while (tNum < 0 || tNum > GradeBook.tAssignments() - 1 || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << 0 << " -> " << GradeBook.tAssignments() - 1 << endl;
    cout << "Enter Test # to grade: ";
    cin >> tNum;
  }
  if (Students.GetStudentByIndex(0).getTestGrade(tNum).ComparedTo(defaultScore) != EQUAL) {
    cout << "Test #" << tNum << " already recorded." << endl;
    return;
  }
  cin.ignore(1000, '\n');
  
  for (int i = 0; i < Students.GetLength(); i++) {
    cout << "Enter Grade for " << Students.GetStudentByIndex(i).getLastName() << " " << Students.GetStudentByIndex(i).getFirstName() << ": ";
    cin >> tGrade;
    while (cin.fail() || tGrade < 0) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid Grade, Input again: ";
      cin >> tGrade;
    }
    cin.ignore(1000, '\n');
    
    Students.GetStudentByIndex(i).changeT(tNum, tGrade);
  }
  out << "Students' Test #" << tNum << " Updated." << endl;
}
void recordFinal(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  if (Students.GetLength() == 0 || GradeBook.fAssignments() == 0) {
    cout << "No Finals to Grade" << endl;
    return;
  }
  
  ItemType defaultScore;
  defaultScore.Initialize(-1);
  int fNum = 0;
  float fGrade = 0.0;
  cout << "Enter Final # to grade: ";
  cin >> fNum;
  while (fNum < 0 || fNum > GradeBook.fAssignments() - 1 || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nInput in range " << 0 << " -> " << GradeBook.fAssignments() - 1 << endl;
    cout << "Enter Final # to grade: ";
    cin >> fNum;
  }
  if (Students.GetStudentByIndex(0).getFinalGrade(fNum).ComparedTo(defaultScore) != EQUAL) {
    cout << "Final #" << fNum << " already recorded." << endl;
    return;
  }
  cin.ignore(1000, '\n');
  
  for (int i = 0; i < Students.GetLength(); i++) {
    cout << "Enter Grade for " << Students.GetStudentByIndex(i).getLastName() << " " << Students.GetStudentByIndex(i).getFirstName() << ": ";
    cin >> fGrade;
    while (cin.fail() || fGrade < 0) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid Grade, Input again: ";
      cin >> fGrade;
    }
    cin.ignore(1000, '\n');
    Students.GetStudentByIndex(i).changeF(fNum, fGrade);
  }
  out << "Students' Final #" << fNum << " Updated." << endl; 
  
}
void changeGrade(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  if (Students.GetLength() == 0) {
    cout << "No Students in class" << endl;
    return;
  }
  Student student;
  int studentNumber = 0;
  bool Check = false;
  float Grade;
  char Choice;
  int Assignment;
  cout << "Enter Student's ID Number: ";
  cin >> studentNumber;
  while (studentNumber < 0 || studentNumber > 9999 || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nStudent number needs to be in range 0 -> 9999\nEnter Student's ID number: ";
    cin >> studentNumber;
  }
  cin.ignore(1000, '\n');
  
  student = Students.GetStudentByID(studentNumber,Check);
  
  if (!Check) {
    cout << "Student with ID: " << studentNumber << " not found." << endl;
    return;
  }
  
  cout << "Enter new grade: ";
  cin >> Grade;
  while (cin.fail() || Grade < 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Grade, Input again: ";
    cin >> Grade;
  }
  cin.ignore(1000, '\n');
  
  cout << "Enter which type of grade to change (P/T/F): ";
  cin >> Choice;
  Choice = toupper(Choice);
  while (true) {
    Choice = toupper(Choice);
    if (Choice == 'P') {
      if (GradeBook.pAssignments() == 0) {
        cout << "No Programming Assignments to Grade" << endl;
        return;
      }
      cout << "Enter Programming Assignment # to grade: ";
      cin >> Assignment;
      while (Assignment < 0 || Assignment > GradeBook.pAssignments() - 1 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInput in range " << 0 << " -> " << GradeBook.pAssignments() - 1 << endl;
        cout << "Enter Programming Assignment # to grade: ";
        cin >> Assignment;
      }
      student.changeP(Assignment,Grade);
      out << "Student: " << student.getID() << " Grade Change" << endl;
      out << "\tProgramming Assignment #" << Assignment << "-> " << Grade << endl;
      return;
    }
    if (Choice == 'T') {
      if (GradeBook.tAssignments() == 0) {
        cout << "No Tests to Grade" << endl;
        return;
      }
      cout << "Enter Test # to grade: ";
      cin >> Assignment;
      while (Assignment < 0 || Assignment > GradeBook.tAssignments() - 1 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInput in range " << 0 << " -> " << GradeBook.tAssignments() - 1 << endl;
        cout << "Enter Test # to grade: ";
        cin >> Assignment;
      }
      student.changeT(Assignment, Grade);
      out << "Student: " << student.getID() << " Grade Change" << endl;
      out << "\tTest #" << Assignment << "-> " << Grade << endl;
      return;
    }
    if (Choice == 'F') {
      if (GradeBook.fAssignments() == 0) {
        cout << "No Finals to Grade" << endl;
        return;
      }
      cout << "Enter Final # to grade: ";
      cin >> Assignment;
      while (Assignment < 0 || Assignment > GradeBook.fAssignments() - 1 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInput in range " << 0 << " -> " << GradeBook.fAssignments() - 1 << endl;
        cout << "Enter Programming Assignment # to grade: ";
        cin >> Assignment;
      }
      student.changeF(Assignment, Grade);
      out << "Student: " << student.getID() << " Grade Change" << endl;
      out << "\tFinal #" << Assignment << "-> " << Grade << endl;
      return;
    }
    cout << "Not a valid input. Please look above for the valid characters." << endl;
    cin.ignore(1000, '\n');    // just so if user types in a string of letters/numbers/symbols, only checks the first letter/number/symbol... otherwise will use every input to check before prompting a new input
    cin >> Choice;
  } 
  
}
void calculateGrade(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  for (int i = 0; i < Students.GetLength(); i++) {
    Students.GetStudentByIndex(i).calcOverall(GradeBook);
  }
  out << "Overall Grade Calculated." << endl;
>>>>>>> Stashed changes
}

void outputGradeData(StudentList& Students,GradeBook& GradeBook, ostream& out) {
  GradeBook.outputValues(out);

  Student temp;
  for (int i = 0; i < Students.GetLength(); i++) {
    temp = Students.GetStudentByIndex(i);
    temp.outputInfo(out);
  }
}
<<<<<<< Updated upstream
void retrieveData(SortedType& Students, GradeBook& Gradebook, ifstream& in) {

}
void storeData(SortedType& Students, GradeBook& GradeBook, ostream& out) {

=======

void retrieveData(StudentList& Students, GradeBook& GradeBook, ifstream& in, ostream& out) {
  string line;
  string lName;
  string fName;
  int ID = 0;
  float Grade;
  float pGradeAvg = 0.0;
  float tGradeAvg = 0.0;
  float fGradeAvg = 0.0;
  float overallGrade = 0.0;
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
  in.ignore();
  GradeBook.setUp(pNum, pPer, tNum, tPer, fNum, fPer);
  
  in >>lName;
  while (true) {
    in.ignore();
    in >> fName;
    in.ignore();
    in >> ID;
    in.ignore();
    in >> pGradeAvg;
    in.ignore();
    in >> tGradeAvg;
    in.ignore();
    in >> fGradeAvg;
    in.ignore();
    in >> overallGrade;
    in.ignore();
    Student student(lName,fName,ID,pGradeAvg,tGradeAvg,fGradeAvg, overallGrade, GradeBook);
    
    for (int i = 0; i < GradeBook.pAssignments(); i++) {
      in >> Grade;
      student.changeP(i,Grade);
      in.ignore();
    }
    
    for (int i = 0; i < GradeBook.tAssignments(); i++) {
      in >> Grade;
      student.changeT(i, Grade);
      in.ignore();
    }
    
    for (int i = 0; i < GradeBook.fAssignments(); i++) {
      in >> Grade;
      student.changeF(i, Grade);
      in.ignore();
    }
    
    Students.PutStudent(student);
    
    in >> lName;
    if (in.eof()) {
      break;
    }
  }

  out << "Previous Data Inputted" << endl;

}
void storeData(StudentList& Students, GradeBook& GradeBook, ostream& out) {
  // stores the gradebook values onto one line... # of each type of assignment, percentages
  GradeBook.recordValues(out);

  // for loop to go over every student in the list and call recordInfo
  Student temp;
  for (int i = 0; i < Students.GetLength(); i++) {
    temp = Students.GetStudentByIndex(i);
    temp.recordInfo(out);
  }
>>>>>>> Stashed changes
}