#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>

class Node
{
public:
	Node( ): student( ), next(nullptr) {} 
    Node(const Student& newStudent, Node *newNext) 
		: student(newStudent), next(newNext){}
    Student getStudent( ) const { return student; }
	Node* getNext( ) const { return next; }	
    void setStudent(const Student& newStudent) { student = newStudent; }
	void setNext(Node *newNext) { next = newNext; }
private:
    Student student;	
    Node *next;		
};

class StudentList
{
public:
	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student&);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	// printStudentsByCourse
	// printStudentByName
	// printStudentsOnHold
	// printAllStudents
	void printStudentByID(int) const;
	void printStudentsByCourse(const std::string&, int) const;
	void printStudentsByName(const std::string&) const;
	void printStudentsOnHold() const;
	void printAllStudents() const;

	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

private:
	Node *first;
	Node *last;
	int count;
};

#endif

