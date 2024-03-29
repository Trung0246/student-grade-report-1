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
/*
CourseList::CourseList () {
	capacity = CAP;
	totalCourses = 0;
	courseList = new Course[CAP];
}
/*/
CourseList::CourseList () :
	courseList{}
{
	courseList.reserve(CAP);
}
//*/

// Overloaded constructor
/*
CourseList::CourseList (int newCapacity) {
	capacity = newCapacity;
	totalCourses = 0;
	courseList = new Course[newCapacity];
}
/*/
CourseList::CourseList (int newCapacity) :
	courseList{}
{
	courseList.reserve(newCapacity);
}
//*/

/*
void courseListCopyHelper (CourseList* list, const CourseList& otherList) {
	list->capacity = otherList.capacity;
	list->totalCourses = otherList.totalCourses;
	for (int i = 0; i < list->totalCourses; ++ i)
		list->courseList[i] = otherList.courseList[i];
}
/*/

//*/

// Copy constructor
/*
CourseList::CourseList (const CourseList& otherList) {
	capacity = 0;
	totalCourses = 0;
	courseList = new Course[otherList.capacity];
	courseListCopyHelper(this, otherList);
}
/*/
CourseList::CourseList (const CourseList& otherList) {
	courseList = otherList.courseList;
}
//*/

// overloaded operator=
/*
CourseList& CourseList::operator= (const CourseList& otherList) {
	if (this != &otherList) {
		if (otherList.capacity != capacity)
			resize2(otherList.capacity);
		courseListCopyHelper(this, otherList);
	}
	else std::cerr << "Same Course list?" << std::endl;
	return *this;
}
/*/
CourseList& CourseList::operator= (const CourseList& otherList) {
	if (this != &otherList)
		courseList = otherList.courseList;
	else
		std::cerr << "Same Course list?" << std::endl;
	return *this;
}
//*/

// addCourse
/*
void CourseList::addCourse (Course& course) {
	if (totalCourses == capacity) resize();
	courseList[totalCourses ++] = course;
}
/*/
void CourseList::addCourse (Course& course) {
	if (courseList.size() == courseList.capacity())
		courseList.reserve(courseList.capacity() * 2);
	courseList.push_back(course);
}
//*/

/*
const Course* courseSearchHelper (
	const Course courseList[], int totalCourses,
	const std::string& coursePrefix, int courseNo
) {
	return std::find_if(
		courseList,
		courseList + totalCourses,
		[&coursePrefix, &courseNo](const Course& currCourse) {
			return currCourse.getCoursePrefix() == coursePrefix &&
				currCourse.getCourseNo() == courseNo;
		}
	);
}
/*/
const std::vector<Course>::const_iterator courseSearchHelper (
	const std::vector<Course>& courseList,
	const std::string& coursePrefix, int courseNo
) {
	return std::find_if(
		courseList.begin(), courseList.end(),
		[&coursePrefix, &courseNo](const Course& currCourse) {
			return currCourse.getCoursePrefix() == coursePrefix &&
				currCourse.getCourseNo() == courseNo;
		}
	);
}
//*/

// getCourseUnits
/*
double CourseList::getCourseUnits (const std::string& coursePrefix, int courseNo) const {
	auto iter = courseSearchHelper(courseList, totalCourses, coursePrefix, courseNo);
	if (iter == courseList + totalCourses) return 0.0;
	return iter->getCourseUnits();
}
/*/
double CourseList::getCourseUnits (const std::string& coursePrefix, int courseNo) const {
	auto iter = courseSearchHelper(courseList, coursePrefix, courseNo);
	if (iter == courseList.end()) return 0.0;
	return iter->getCourseUnits();
}
//*/

// searchCourse
/*
bool CourseList::searchCourse (const std::string& coursePrefix, int courseNo) const {
	return courseSearchHelper(courseList, totalCourses, coursePrefix, courseNo) != (courseList + totalCourses);
}
/*/
bool CourseList::searchCourse (const std::string& coursePrefix, int courseNo) const {
	return courseSearchHelper(courseList, coursePrefix, courseNo) != courseList.end();
}
//*/

// printCourses
/*
void CourseList::printCourses () const {
	std::cout << "totalCourses: " << totalCourses << std::endl <<
		"capacity: " << capacity << std::endl;
	for (int i = 0; i < totalCourses; i ++)
		courseList[i].printCourseInfo();
}
/*/
void CourseList::printCourses () const {
	std::cout << "totalCourses: " << courseList.size() << std::endl <<
		"capacity: " << courseList.capacity() << std::endl;
	for (const auto& course : courseList)
		course.printCourseInfo();
}
//*/

// destructor
CourseList::~CourseList () {
	// delete[] courseList;
	// courseList = nullptr;
	courseList.clear();
}

/*
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
//*/