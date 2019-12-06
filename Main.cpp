/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung (Main.cpp, displayMenu(), processChoice())
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "InputHandler.h"
#include "CourseList.h"
#include "StudentList.h"
#include "ExceptionHandler.h"

#include <algorithm> 

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void displayMenu();
void processChoice(const StudentList& studentList,
	const CourseList& courseList);

int main()
{
	//system("Color 1A");
	CourseList courseList;
	StudentList studentList;

	readData(courseList, studentList);
	displayMenu();
	processChoice(studentList, courseList);

	//cout << endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Search student by last name" << endl;
	cout << "    2: Print all students" << endl;
	cout << "    3: Print students by course" << endl;
	cout << "    4: Print students on hold" << endl;
	cout << "    5: Print student information" << endl;

	cout << "    6: Print students with greater than 3.0 GPA" << endl;
	cout << "    7: Print students between 3.0 (inclusive) and 2.0 GPA" << endl;
	cout << "    8: Print students between 2.0 and 1.0 GPA" << endl;
	cout << "    9: Print students with less than 1.0 GPA" << endl;
	cout << "    10: Print students not on hold" << endl;
	cout << "    11: Exit" << endl;
}

void processChoice(const StudentList& studentList,
	const CourseList& courseList)
{
	int id = 0, courseNo = 0;
	bool valid = false;
	string inputID, inputCourseNo, input, coursePrefix, lastName;
	ExceptionHandler exception;

	cout << "\nEnter your selection: ";
	getline(cin, input);
	int selection = exception.validateSelection(input);
	cout << endl;

	cout << fixed << showpoint << setprecision(2); 

	while (selection != 11)
	{
		string fName, lName;

		switch (selection)
		{

			// Search student by last name
		case 1:
			cout << "  => Please enter the student's last name: ";
			getline(cin, lastName);
			exception.lastNameValid(lastName);
			cout << endl;
			if (exception.lastNameValid(lastName))
				studentList.printStudentByName(lastName);
			else
				cout << "Incorrect input. Try again.\n";
			cout << endl;
			
			break;

			// Print all students
		case 2:
			studentList.printAllStudents();
			cout << endl;

			break;

			// Print students by course 
		case 3:
			cout << "  => Please enter the course prefix (CSC, HIS, etc.): ";
			getline(cin, coursePrefix);
			cout << "  => Please enter the course number: ";
			getline(cin, inputCourseNo);
			cout << endl;
			valid = exception.validateCoursePrefix(coursePrefix);			
			if(exception.validateCourseNo(inputCourseNo, courseNo) && valid)
			{				
			 	if (!courseList.searchCourse(coursePrefix, courseNo))
			 		cout << "This course is not in the catalog." << endl;
			 	else
			 		studentList.printStudentsByCourse(coursePrefix, courseNo);
			}
			cout << endl;

			break;

			// Print students on hold
		case 4:
			studentList.printStudentsOnHold();
			cout << endl;

			break;

			// Print student information
		case 5:
			cout << "  => Please enter student's ID: ";
			getline(cin, input);
			cout << endl;
			if(exception.validateID(input, id))
				studentList.printStudentByID(id);
			cout << endl;

			break;

		case 6:
			studentList.printStudentsBetweenGPA(3.0, -1.0);
			cout << endl;
			break;

		case 7:
			studentList.printStudentsBetweenGPA(2.0, 3.0);
			cout << endl;
			break;

		case 8:
			studentList.printStudentsBetweenGPA(1.0, 2.0);
			cout << endl;
			break;

		case 9:
			studentList.printStudentsBetweenGPA(-1.0, 1.0);
			cout << endl;
			break;

		case 10:
			studentList.printStudentsNotOnHold();
			cout << endl;
			break;

			// Incorrect selection
		default:
			cout << "  => Invalid entry. Please try again.\n\n";

			break;
		}

		cout << "  => ";
		system("Pause");
		cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		displayMenu();

		cout << "\nEnter your selection: ";		
		getline(cin, input);
		selection = exception.validateSelection(input);
		cout << endl;
	}

	if (selection == 11)
		cout << "Thank you for using our software! Good-bye!\n";
	cout << endl;
}













































/*
void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Search student by last name" << endl;
	cout << "    2: Print student information" << endl;
	cout << "    3: Print all students" << endl;
	cout << "    4: Print students by course" << endl;
	cout << "    5: Print students on hold" << endl;
	cout << "    6: Exit" << endl;
}

void processChoice(const StudentList& studentList,
	const CourseList& courseList)
{
	int id = 0, courseNo = 0;
	bool valid = false;
	string inputID, inputCourseNo, input, coursePrefix, lastName;
	ExceptionHandler exception;

	cout << "\nEnter your selection: ";
	getline(cin, input);
	int selection = exception.validateSelection(input);
	cout << endl;

	cout << fixed << showpoint << setprecision(2); 

	while (selection != 6)
	{
		string fName, lName;

		switch (selection)
		{

			// Search student by last name
		case 1:
			cout << "  => Please enter the student's last name: ";
			getline(cin, lastName);
			exception.lastNameValid(lastName);
			cout << endl;
			if (exception.lastNameValid(lastName))
				studentList.printStudentByName(lastName);
			else
				cout << "Incorrect input. Try again.\n";
			cout << endl;
			
			break;

			// Print student information
		case 2:
			cout << "  => Please enter student's ID: ";
			getline(cin, input);
			cout << endl;
			if(exception.validateID(input, id))
				studentList.printStudentByID(id);
			cout << endl;

			break;

			// Print all students
		case 3:
			studentList.printAllStudents();
			cout << endl;

			break;

			// Print students by course 
		case 4:
			cout << "  => Please enter the course prefix (CSC, HIS, etc.): ";
			getline(cin, coursePrefix);
			cout << "  => Please enter the course number: ";
			getline(cin, inputCourseNo);
			cout << endl;
			valid = exception.validateCoursePrefix(coursePrefix);			
			if(exception.validateCourseNo(inputCourseNo, courseNo) && valid)
			{				
				if (!courseList.searchCourse(coursePrefix, courseNo))
					cout << "This course is not in the catalog." << endl;
				else
					studentList.printStudentsByCourse(coursePrefix, courseNo);
			}
			cout << endl;

			break;

			// Print students on hold
		case 5:
			studentList.printStudentsOnHold();
			cout << endl;

			break;

			// Incorrect selection
		default:
			cout << "  => Invalid entry. Please try again.\n\n";

			break;
		}

		cout << "  => ";
		system("Pause");
		cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		displayMenu();

		cout << "\nEnter your selection: ";		
		getline(cin, input);
		selection = exception.validateSelection(input);
		cout << endl;
	}

	if (selection == 6)
		cout << "Thank you for using our software! Good-bye!\n";
	cout << endl;
}

*/


















































/*
#include "Student.h"
#include "Course.h"

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	Student s1;

	multimap<Course, char> cc1;

	Course c1, c2, c3, c4;

	c1.setCourseInfo(string("Chemistry"), string("CHM"), 123, 4.0);
	c2.setCourseInfo(string("Chemistry"), string("CHM"), 123, 4.0);
	c3.setCourseInfo(string("CompSci"), string("CSC"), 234, 4.0);
	c4.setCourseInfo(string("Math"), string("MTH"), 345, 3.0);

	cc1.insert({c1, 'A'});
	cc1.insert({c1, 'B'});
	cc1.insert({c3, 'A'});
	cc1.insert({c4, 'A'});

	s1.setStudentInfo("Jjjj", "Kkkkkk", 98, false, cc1);

	s1.printStudentInfo();


	cout << endl;
	system("Pause");
	return 0;
}
*/

/*
#include "Student.h"
#include "Course.h"
#include "StudentList.h"
#include "CourseList.h"

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// Creating courses
	Course biology;
	Course chemistry;
	Course cplusplus;
	Course english;
	Course history;

	biology.setCourseInfo("Biology", "BIO", 234, 4.0);
	chemistry.setCourseInfo("Chemistry", "CHM", 348, 4.0);
	cplusplus.setCourseInfo("C++", "CSC", 150, 4.0);
	english.setCourseInfo("English 101", "ENG", 101, 3.0);
	history.setCourseInfo("History", "HIS", 101, 3.0); // 101

	// Creating multimap for Peter Parker
	multimap<Course, char> classes;

	classes.insert(pair<Course, char>(english, 'A'));
	classes.insert(pair<Course, char>(cplusplus, 'A'));
	classes.insert(pair<Course, char>(chemistry, 'B'));
	classes.insert(pair<Course, char>(biology, 'A'));

	// Creating and printing Peter Parker
	Student peteParker;

	peteParker.setStudentInfo("Pete", "Parker", 654321, true, classes);
	peteParker.printStudentInfo();
	cout << endl;

	// Creating multimap for Lex Luthor
	multimap<Course, char> classes2;

	classes2.insert(pair<Course, char>(biology, 'A'));
	classes2.insert(pair<Course, char>(cplusplus, 'A'));
	classes2.insert(pair<Course, char>(history, 'A'));

	// Creating and printing Lex Luthor
	Student lexLuthor;

	lexLuthor.setStudentInfo("Lex", "Luthor", 345678, false, classes2);
	lexLuthor.printStudentInfo();
	cout << endl;

	Course compsci1;

	compsci1.setCourseInfo("CompSci", "CSC", 20, 4);

	multimap<Course, char> classes3;

	classes3.insert(pair<Course, char>(chemistry, 'A'));
	classes3.insert(pair<Course, char>(compsci1, 'B'));
	classes3.insert(pair<Course, char>(history, 'A'));

	chemistry.printCourseInfo();
	compsci1.printCourseInfo();
	cout << endl << "----------------" << endl << endl;

	Student bruceWayne;

	bruceWayne.setStudentInfo("Bruce", "Wayne", 123456, true, classes3);
	bruceWayne.printStudentInfo();
	cout << endl;

	// Test cases to test StudentList and CourseList

	cout << "---BEGIN CourseList---" << endl;

	CourseList cl1 {4};

	cl1.addCourse(biology);
	cl1.addCourse(chemistry);
	cl1.addCourse(cplusplus);
	cl1.addCourse(english);
	cl1.addCourse(history);
	cl1.addCourse(compsci1);

	CourseList cl2 {cl1}, cl3;

	cl3 = cl1;
	// Same courses? 
	cl2 = cl2;

	CourseList *cl4 = new CourseList();
	cl4->operator=(cl1);
	cout << "---cl4 destructor---" << endl;
	cl4->printCourses();
	cout << "---e cl4---" << endl;
	cl4->~CourseList();

	cout << "----cl1----" << endl;
	cl1.printCourses();
	cout << "---e cl1---" << endl;
	cout << "---cl2 copy---" << endl;
	cl2.printCourses();
	cout << "---e cl2---" << endl;
	cout << "---cl3 operator=---" << endl;
	cl3.printCourses();
	cout << "---e cl3---" << endl;
	cout << endl;

	// 4.00
	cout << "getCourseUnits (CSC, 20): " << fixed << cl2.getCourseUnits("CSC", 20) << endl <<
	// 3.00
		"getCourseUnits (ENG, 101): " << fixed << cl3.getCourseUnits("ENG", 101) << endl <<
	// 0.00 (not found)
		"getCourseUnits (WTF, 000): " << fixed << cl3.getCourseUnits("WTF", 000) << endl;

	cout << endl;

	// true
	cout << "searchCourse (CSC, 20): " << boolalpha << cl2.searchCourse("CSC", 20) << endl <<
	// true
		"searchCourse (ENG, 101): " << boolalpha << cl3.searchCourse("ENG", 101) << endl <<
	// false (not found)
		"searchCourse (WTF, 000): " << boolalpha << cl3.searchCourse("WTF", 000) << endl;

	cout << endl << "---END CourseList---" << endl;
	cout << endl << "---BEGIN StudentList---" << endl << endl;

	StudentList sl1;

	sl1.addStudent(peteParker);
	sl1.addStudent(lexLuthor);
	sl1.addStudent(bruceWayne);

	cout << "getNoOfStudents: "           	<< defaultfloat << sl1.getNoOfStudents() << endl;
	cout << "------printAllStudents------"	<< endl;
	sl1.printAllStudents();
	cout << "------end printAllStudents------"                        	<< endl;
	cout << "------printStudentsByCourse (chemistry, not found)------"	<< endl;
	sl1.printStudentsByCourse("CHM", 348);
	sl1.printStudentsByCourse("WTF", 000);
	cout << "------end printStudentsByCourse------"	<< endl;
	cout << "------printStudentsOnHold------"      	<< endl;
	sl1.printStudentsOnHold();
	cout << "------end printStudentsOnHold------"	<< endl;
	cout << "------printStudentByID------"       	<< endl;
	sl1.printStudentByID(123456);
	sl1.printStudentByID(135793);
	cout << "------printStudentByName------"	<< endl;
	sl1.printStudentByName("Luthor");
	sl1.printStudentByName("Lucy");

	cout << "------destroy StudentList------" << endl;
	sl1.destroyStudentList();
	sl1.printAllStudents();
	cout << "------end destroy StudentList------" << endl;

	system("Pause");
	return 0;
}
*/

/*
Student Name: Wayne, Bruce

Student ID: 123456
Number of courses completed: 3

Course    Units     Grade
CHM 348    4          A
CSC 20     4          B
HIS 101    3          A

Total number of unit hours: 11
Current Term GPA: 3.64

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


Press any key to continue . . .

*/