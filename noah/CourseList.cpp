#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

CourseList::CourseList()
{
	capacity = CAP;
	totalCourses = 0;
	courseList = new Course[capacity];
}

CourseList::CourseList(int newCapacity)
{
	capacity = newCapacity;
	totalCourses = 0;
	courseList = new Course[capacity];
}

CourseList::CourseList(const CourseList& otherList)
{
	capacity = otherList.capacity;
	totalCourses = otherList.capacity;
	for (int i = 0; i < totalCourses; i++)
		courseList[i] = otherList.courseList[i];
}

// addCourse
void CourseList::addCourse(const Course& newCourse)
{
	if (totalCourses < capacity)
		courseList[totalCourses] = newCourse;

	else
	{
		resize();
		courseList[totalCourses] = newCourse;
	}

	totalCourses++;
}

// getCourseUnits
int CourseList::getCourseUnits(const std::string& newPrefix, int newNum) const
{
	int i = 0;
	while (i < totalCourses)
	{
		if (courseList[i].getCoursePrefix() == newPrefix
			&& courseList[i].getCourseNo() == newNum)
			return courseList[i].getCourseUnits();

		i++;
	}

	return 0;
}

// searchCourse
bool CourseList::searchCourse(const std::string& newPrefix, int newNum) const
{
	int i = 0;
	while (i < totalCourses)
	{
		if (courseList[i].getCoursePrefix() == newPrefix
			&& courseList[i].getCourseNo() == newNum)
			return true;

		i++;
	}

	return false;
}

// overloaded operator=
CourseList& CourseList::operator=(const CourseList& otherList)
{
	if (this != &otherList)
	{
		capacity = otherList.capacity;
		totalCourses = otherList.capacity;
		for (int i = 0; i < totalCourses; i++)
			courseList[i] = otherList.courseList[i];
	}

	else
		cerr << "Same Course?" << endl;

	return *this;
}

// destructor
CourseList::~CourseList()
{
	delete[] courseList;
	courseList = nullptr;
}

void CourseList::resize()
{
	Course* temp;
	temp = new Course[capacity * 2];

	for (int i = 0; i < totalCourses; i++)
		temp[i] = courseList[i];

	delete[] courseList;
	courseList = temp;
}