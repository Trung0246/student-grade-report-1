#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList
{
public:
	// CourseList
	// Overloaded constructor
	// Copy constructor
	CourseList();
	CourseList(int);
	CourseList(const CourseList&);


	// addCourse
	void addCourse(const Course&);

	// getCourseUnits
	int getCourseUnits(const std::string&, int) const;

	// searchCourse
	bool searchCourse(const std::string&, int) const;

	// overloaded operator=
	CourseList& operator=(const CourseList&);

	// destructor
	~CourseList();
private:
	Course* courseList;	
	int totalCourses;
	int capacity;
	static const int CAP;

	// resize
	void resize();

};

#endif
