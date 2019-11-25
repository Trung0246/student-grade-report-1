/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Person.h"

using namespace std;

// default constructor
Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
}

// overloaded constructor
Person::Person(const string& newFirstName, const string& newLastName)
{
	firstName = newFirstName;
	lastName = newLastName;
}

// setName
void Person::setName(const string& newFirstName, const string& newLastName)
{
	firstName = newFirstName;
	lastName = newLastName;
}

// getLastName
const string& Person::getLastName() const
{
	return lastName;
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

// destructor
Person::~Person()
{

}