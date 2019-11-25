/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "StudentList.h"

// using namespace std;

#define EMPTY_ERR(MSG) if (last == nullptr) std::cout << MSG << std::endl; else
#define NODE_LOOP Node* currNode = first; while (currNode != nullptr) {
#define END_NODE_LOOP currNode = currNode->getNext(); }
#define CURR_STUDENT currNode->getStudent()

// default constructor
StudentList::StudentList () {
	first = nullptr;
	last = nullptr;
	count = 0;
}

// addStudent
void StudentList::addStudent (Student& student) {
	Node* node = new Node(student, nullptr);

	if (first == nullptr)
		first = node;

	if (last != nullptr)
		last->setNext(node);

	last = node;
	++ count;
}

// getNoOfStudents
int StudentList::getNoOfStudents () const {
	return count;
}

// printStudentByID
void StudentList::printStudentByID (int studentID) const {
	EMPTY_ERR("List is empty.") {
		NODE_LOOP
			if (CURR_STUDENT.getID() == studentID) {
				CURR_STUDENT.printStudentInfo();
				break;
			}
		END_NODE_LOOP

		if (currNode == nullptr)
			std::cout << "No student with ID " << studentID << " found in the list." << std::endl;
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse (const std::string& coursePrefix, int courseNo) const {
	bool flag = true;
	EMPTY_ERR("List is empty.") {
		NODE_LOOP
			if (CURR_STUDENT.courseIsCompleted(coursePrefix, courseNo)) {
				CURR_STUDENT.printStudent();
				flag = false;
			}
		END_NODE_LOOP

		if (flag) std::cout << "No student completed " << coursePrefix << " " << courseNo << std::endl;
	}
}

// printStudentByName
void StudentList::printStudentByName (const std::string& name) const {
	EMPTY_ERR("List is empty.") {
		NODE_LOOP
			if (CURR_STUDENT.getLastName() == name) {
				CURR_STUDENT.printStudentInfo();
				break;
			}
		END_NODE_LOOP

		if (currNode == nullptr)
			std::cout << "No student with last name \"" << name << "\" found in the list." << std::endl;
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold () const {
	bool flag = true;
	EMPTY_ERR("No students in the list.") {
		NODE_LOOP
			if (!CURR_STUDENT.isTuitionPaid()) {
				CURR_STUDENT.printStudentInfo();
				flag = false;
			}
		END_NODE_LOOP

		if (flag) std::cout << "There are no students on hold." << std::endl;
	}
}

// printAllStudents
void StudentList::printAllStudents () const {
	NODE_LOOP
		CURR_STUDENT.printStudentInfo();
	END_NODE_LOOP
}

// destroyStudentList
void StudentList::destroyStudentList () {
	Node* tempNode;
	while (first != nullptr) {
		tempNode = first->getNext();
		delete first;
		first = tempNode;
	}
	last = nullptr;
	count = 0;
}

// destructor
StudentList::~StudentList () {
	destroyStudentList();
}