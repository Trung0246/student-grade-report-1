/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
	// default constructor
	// overloaded constructor
	Person();
	Person(const std::string&, const std::string&);

	// setName
	void setName(const std::string&, const std::string&);

	// getLastName
	const std::string& getLastName() const;

	// printName
	void printName() const;

	// destructor
	~Person();

private:
	std::string firstName;
	std::string lastName;
};

#endif 