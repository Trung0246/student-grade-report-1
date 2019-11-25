/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

// CourseList
CourseList::CourseList () {
	capacity = CAP;
	totalCourses = 0;
	courseList = new Course[CAP];
}

// Overloaded constructor
CourseList::CourseList (int newCapacity) {
	capacity = newCapacity;
	totalCourses = 0;
	courseList = new Course[newCapacity];
}

void courseCopyHelper (CourseList* list, const CourseList& otherList) {
	list->capacity = otherList.capacity;
	list->totalCourses = otherList.totalCourses;
	for (int i = 0; i < list->totalCourses; ++ i)
		list->courseList[i] = otherList.courseList[i];
}

// Copy constructor
CourseList::CourseList (const CourseList& otherList) {
	capacity = 0;
	totalCourses = 0;
	courseList = new Course[otherList.capacity];
	courseCopyHelper(this, otherList);
}

// overloaded operator=
CourseList& CourseList::operator= (const CourseList& otherList) {
	if (this != &otherList) {
		if (otherList.capacity != capacity)
			resize2(otherList.capacity);
		courseCopyHelper(this, otherList);
	}
	else std::cerr << "Same Course?" << std::endl;
	return *this;
}

// addCourse
void CourseList::addCourse (Course& course) {
	if (totalCourses == capacity) resize();
	courseList[totalCourses ++] = course;
}

const Course* courseSearchHelper (const Course courseList[], int totalCourses, const std::string& coursePrefix, int courseNo) {
	return std::find_if(
		courseList,
		courseList + totalCourses,
		[&coursePrefix, &courseNo](const Course currCourse) {
			return currCourse.getCoursePrefix() == coursePrefix &&
				currCourse.getCourseNo() == courseNo;
		}
	);
}

// getCourseUnits
double CourseList::getCourseUnits (const std::string& coursePrefix, int courseNo) const {
	auto iter = courseSearchHelper(courseList, totalCourses, coursePrefix, courseNo);
	if (iter == courseList + totalCourses) return 0.0;
	return iter->getCourseUnits();
}

// searchCourse
bool CourseList::searchCourse (const std::string& coursePrefix, int courseNo) const {
	return courseSearchHelper(courseList, totalCourses, coursePrefix, courseNo) != (courseList + totalCourses);
}

// printCourses
void CourseList::printCourses () const {
	std::cout << "totalCourses: " << totalCourses << std::endl <<
		"capacity: " << capacity << std::endl;
	for (int i = 0; i < totalCourses; i ++)
		courseList[i].printCourseInfo();
}

// destructor
CourseList::~CourseList () {
	delete[] courseList;
	courseList = nullptr;
}

// resize
void CourseList::resize () {
	resize2(capacity * 2);
}

// resize2
void CourseList::resize2 (int cap) {
	capacity = cap;
	Course* newCourseList = new Course[cap];

	if (totalCourses > cap) totalCourses = cap;

	for (int i = 0; i < totalCourses; ++ i)
		newCourseList[i] = courseList[i];

	delete[] courseList;
	courseList = newCourseList;
}