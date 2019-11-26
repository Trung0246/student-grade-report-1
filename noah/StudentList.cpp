#include "StudentList.h"

using namespace std;

// default constructor
StudentList::StudentList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	Node* temp = new Node(newStudent, nullptr);
	first = temp;
	count++;
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count;
}

// printStudentByID
void StudentList::printStudentByID(int newID) const
{
	if (count == 0)
		cerr << "List is empty." << endl;

	bool found = false;
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getStudent().getID() == newID)
		{
			found = true;
			current->getStudent().printStudentInfo();
		}
		
		current = current->getNext();
	}

	if (!found)
		cout << "No student with ID # foudn in the list." << endl;
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const std::string& newPref, int newID) const
{
	if (count == 0)
		cerr << "List is empty." << endl;

	bool found = false;
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getStudent().courseIsCompleted(newPref, newID))
		{
			found = true;
			current->getStudent().printStudentInfo();
		}

		current = current->getNext();
	}

	if (!found)
		cout << "No student completed " << newID << endl;
}

// printStudentByName
void StudentList::printStudentsByName(const std::string&) const
{

}

// printStudentsOnHold
void StudentList::printStudentsOnHold() const
{

}

// printAllStudents
void StudentList::printAllStudents() const
{

}

// destroyStudentList
void StudentList::destroyStudentList()
{

}

// destructor
StudentList::~StudentList()
{

}