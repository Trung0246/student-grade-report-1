/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

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