#ifndef COURSELIST_H
#define COURSELIST_H

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
#include <algorithm>
#include <vector>

class CourseList
{

/*
friend void courseListCopyHelper(CourseList*, const CourseList&);
/*/

//*/

public:
	// CourseList

	CourseList ();

	// Overloaded constructor
	CourseList (int);

	// Copy constructor
	CourseList (const CourseList&);

	// overloaded operator=
	CourseList& operator= (const CourseList&);

	// destructor
	~CourseList ();

	void addCourse (Course&);

	double getCourseUnits (const std::string&, int) const;

	bool searchCourse (const std::string&, int) const;

	// use for test cases
	void printCourses () const;

private:
	static const int CAP;
	/*
	Course* courseList;	
	int totalCourses;
	int capacity;

	// resize
	void resize ();

	void resize2 (int);
	/*/
	std::vector<Course> courseList;
	//*/
};

#endif
