/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Vu, Timothy
	Nguyen, Johnny

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Student.h"
#include "Course.h"

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
	history.setCourseInfo("History", "HIS", 101, 3.0);

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

	cout << endl;
	system("Pause");
	return 0;
}
