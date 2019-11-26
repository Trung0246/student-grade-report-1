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

using namespace std;

// default constructor
Student::Student()
{
	studentID = 0;
	tuitionWasPaid = false;
	totalCourses = 0;
}

// setStudentInfo
void Student::setStudentInfo(const string& newFirstName, 
	const string& newLastName, int newStudentID, bool tuitionFlag, multimap<Course, char>& newCourses)
{
	setName(newFirstName, newLastName);
	studentID = newStudentID;
	tuitionWasPaid = tuitionFlag;
	coursesCompleted = newCourses;
	totalCourses = static_cast<int>(coursesCompleted.size());
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return totalCourses;
}


// getUnitsCompleted
int Student::getUnitsCompleted() const
{
	int sum = 0;

	for (const auto& course : coursesCompleted)
		sum += static_cast<int>(course.first.getCourseUnits());

	return sum;
}

// getGpa
double Student::getGpa() const
{
	// for every course, add (course units * grade) to the total,
	double total = 0.0;
	for (const auto& course : coursesCompleted)
	{
		switch (course.second)
		{
			case 'A': total += course.first.getCourseUnits() * 4.0; break;
			case 'B': total += course.first.getCourseUnits() * 3.0; break;
			case 'C': total += course.first.getCourseUnits() * 2.0; break;
			case 'D': total += course.first.getCourseUnits() * 1.0; break;
			case 'F': break;
			default: cerr << "Invalid Course Grade"; break;
		}
	}
	
	// return the total / all units
	return static_cast<double>(total / getUnitsCompleted());
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// courseIsCompleted
bool Student::courseIsCompleted(const string& coursePrefix, int courseNo) const
{
	for (const auto& course : coursesCompleted)
	{
		if (course.first.getCoursePrefix() == coursePrefix
			&& course.first.getCourseNo() == courseNo)
			return true;
	}

	return false;
}

// printStudent
void Student::printStudent() const
{
	cout << studentID << " - ";
	printName();
}

// printStudentInfo
void Student::printStudentInfo() const
{
	// Printing Name and ID
	cout << "Student Name: ";
	printName();
	cout << endl;
	cout << "Student ID: " << studentID << endl;
		
	// Printing courses
	cout << "Number of courses completed: " << totalCourses << endl;
	cout << endl;
	cout << "Course" << setw(9) << "Units" << setw(10) << "Grade" << endl;
	for (const auto& course : coursesCompleted)
	{
		course.first.printCourseInfo();
		if (tuitionWasPaid)
			cout << setw(11) << course.second << endl;
		else
			cout << setw(13) << "***" << endl;
	}
			
	// Printing GPA and Unit hours
	cout << endl;
	cout << "Total number of unit hours: " << getUnitsCompleted() << endl;

	if (tuitionWasPaid)
		cout << "Current Term GPA: " << fixed << setprecision(2) << getGpa() << endl;

	else
		cout << "*** Grades are being held for not paying the tuition. ***" << endl;

	cout << defaultfloat << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
}

// destructor
Student::~Student()
{

}