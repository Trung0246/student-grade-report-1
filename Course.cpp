/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Course.h"

using namespace std;

// default constructor
Course::Course()
{
	courseNo = 0;
	courseUnits = 0.0;
}

// setCourseInfo
void Course::setCourseInfo(
	const string& newCourseName,
	const string& newCoursePrefix,
	int newCourseNo,
	double newCourseUnits
) {
	courseName = newCourseName;
	coursePrefix = newCoursePrefix;
	courseNo = newCourseNo;
	courseUnits = newCourseUnits;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCoursePrefix
string Course::getCoursePrefix() const
{
	return coursePrefix;
}

// getCourseNo
int Course::getCourseNo() const
{
	return courseNo;
}

// getCourseUnits
double Course::getCourseUnits() const
{
	return courseUnits;
}

// printCoursePrefix
void Course::printCoursePrefix () const
{
	// https://stackoverflow.com/questions/22425489/
	cout << setw(3) << coursePrefix << ' ' << left << setw(3) << courseNo << ' ' << right;
}

// printCourseInfo
void Course::printCourseInfo() const
{
	printCoursePrefix();
	// Counted the space, should be 4
	std::cout << setw(4) << defaultfloat << courseUnits << endl;
}

// destructor
Course::~Course()
{}

bool Course::operator< (const Course& c2) const {
	if (coursePrefix == c2.coursePrefix)
		return courseNo < c2.courseNo;
	return coursePrefix < c2.coursePrefix;
}