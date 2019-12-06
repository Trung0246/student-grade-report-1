/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
// #include <algorithm>
#include <string>
#include <list>

/*
class Node
{
public:
	Node ( ): student ( ), next (nullptr) {} 
    Node (const Student& newStudent, Node *newNext) 
		: student (newStudent), next (newNext){}
    Student getStudent ( ) const { return student; }
	Node* getNext ( ) const { return next; }	
    void setStudent (const Student& newStudent) { student = newStudent; }
	void setNext (Node *newNext) { next = newNext; }
private:
    Student student;	
    Node *next;     		
};
*/

class StudentList
{

/*
friend void studentListCopyHelper (StudentList*, const StudentList&);
/*/

//*/

private:
	// copy constructor
	StudentList (const StudentList&);

	// assignment operator
	StudentList& operator= (const StudentList&);

public:
	// default constructor
	StudentList ();

	// destructor
	~StudentList ();

	void addStudent (const Student&);

	int getNoOfStudents () const;
	
	void printStudentByID     	(int)                    	const;
	void printStudentsByCourse	(const std::string&, int)	const;
	void printStudentByName   	(const std::string&)     	const;
	void printStudentsOnHold  	()                       	const;
	void printAllStudents     	()                       	const;

	

	void destroyStudentList ();

private:
	/*
	Node *first;
	Node *last;
	int count;
	/*/
	std::list<Student> *studentList;
	//*/
};

#endif

