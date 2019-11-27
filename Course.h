/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Course
{
public:
	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const std::string&, const std::string&, int, double);

	// getCourseName
	std::string getCourseName() const;

	// getCoursePrefix
	std::string getCoursePrefix() const;

	// getCourseNo
	int getCourseNo() const;

	// getCourseUnits
	double getCourseUnits() const;

	void printCoursePrefix() const;

	// printCourseInfo
	void printCourseInfo() const;

	bool operator< (const Course&) const;

	// destructor;
	~Course();
private:
	std::string courseName;
	std::string coursePrefix;
	int courseNo;
	double courseUnits;
};

#endif
