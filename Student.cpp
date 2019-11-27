/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Student.h"

// using namespace std;

// default constructor
Student::Student () :
	Person(),
	coursesCompleted()
{
	studentID = 0;
	tuitionWasPaid = false;
	totalCourses = static_cast<int>(coursesCompleted.size());
}

// setStudentInfo
void Student::setStudentInfo (
	const std::string& newFirstName,
	const std::string& newLastName,
	int newStudentID, bool newTuitionWasPaid,
	std::multimap<Course, char>& newCourseCompleted
) {
	setName(newFirstName, newLastName);
	studentID = newStudentID;
	tuitionWasPaid = newTuitionWasPaid;
	coursesCompleted = newCourseCompleted;
	totalCourses = static_cast<int>(coursesCompleted.size());
}

// getID
int Student::getID () const {
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses () const {
	return totalCourses;
}

// getUnitsCompleted
double Student::getUnitsCompleted () const {
	double sum = 0;

	for (const auto& currentCourse : coursesCompleted)
		sum += currentCourse.first.getCourseUnits();

	return sum;
}

// getGpa
double Student::getGpa () const {
	double total = 0.0;

	//*
	for (const auto& course : coursesCompleted) {
		switch (course.second) {
			case 'A': total += course.first.getCourseUnits() * 4.0; break;
			case 'B': total += course.first.getCourseUnits() * 3.0; break;
			case 'C': total += course.first.getCourseUnits() * 2.0; break;
			case 'D': total += course.first.getCourseUnits() * 1.0; break;
			case 'F': break;
			default: std::cerr << "Invalid Course Grade"; break;
		}
	}
	/*/
	for (const auto& course : coursesCompleted)
		if (course.second < 'A' && course.second > 'D') std::cerr << "Invalid Course Grade";
		else if (course.second != 'F')
			total += course.first.getCourseUnits() * (69.0 - static_cast<double>(course.second));
	//*/

	return static_cast<double>(total / getUnitsCompleted());
}

// isTuitionPaid
bool Student::isTuitionPaid () const {
	return tuitionWasPaid;
}

// courseIsCompleted
bool Student::courseIsCompleted (const std::string& coursePrefix, int courseNo) const {
	// Multiple same courses because of multimap

	return std::find_if (
		coursesCompleted.begin(),
		coursesCompleted.end(),
		[&coursePrefix, &courseNo] (const std::pair<Course, char>& currentCourse) {
			return currentCourse.first.getCoursePrefix() == coursePrefix &&
				currentCourse.first.getCourseNo() == courseNo;
		}
	) != coursesCompleted.end();
}

// printStudent
void Student::printStudent () const {
	std::cout << studentID << " - ";
	printName();
}

// printStudentInfo
void Student::printStudentInfo () const {
	std::cout << "Student Name: ";
	printName();
	std::cout << std::endl <<
		"Student ID: " << studentID << std::endl <<
		"Number of courses completed: " << totalCourses << std::endl <<
		std::endl <<
		"Course" << std::setw(9) << "Units" << std::setw(10) << "Grade" << std::endl;

	int padNum = 10 - static_cast<int>(tuitionWasPaid) * 2; // 10
	for (const auto& currentCourse : coursesCompleted) {
		currentCourse.first.printCoursePrefix();

		std::cout <<

			std::setw(7) << std::setprecision(2) << std::fixed << 
				currentCourse.first.getCourseUnits() <<

			std::setw(padNum) <<
				(tuitionWasPaid ? std::string(1, currentCourse.second) : "***") <<

		std::endl;
	}

	std::cout << std::endl <<
		"Total number of unit hours: " <<
			std::defaultfloat << std::noshowpoint
				<< getUnitsCompleted() <<
	std::endl;

	if (tuitionWasPaid) std::cout << "Current Term GPA: " << std::fixed << getGpa();
	else std::cout << "*** Grades are being held for not paying the tuition. ***";

	std::cout << std::endl << std::endl;
	std::fill_n(std::ostream_iterator<std::string>(std::cout), 24, "-*");
	std::cout << "-" << std::endl;
}

// destructor
Student::~Student () {}
