/************************
	Timpossible

	Cussatti, Noah
	Tran, Trung
	Nguyen, Johnny
	Vu, Timothy

	CS A250 - Fall 2019

	Project 1
*************************/

#include "ExceptionHandler.h"

using namespace std;

int ExceptionHandler::validateSelection(const string& input) const
{
	if (input.length() > 1)
		return 0;
	else
	{
		int id = input[0] - 48;
		if (id >= 1 && id <= 6)
			return id;
		else
			return 0;
	}
}

bool ExceptionHandler::lastNameValid(string& input) const
{
	for (auto it = input.begin(); it != input.end(); ++it) 
		if (isspace(*it)) 
			return false;

	input[0] = toupper(input[0]);
	for_each(input.begin() + 1, input.end(),
			[](char& c) { c = ::tolower(c); });
		return true;
}

bool ExceptionHandler::validateID
	(const string& input, int& id) const
{
	if (input.size() != 6) {
		cerr << "Invalid input. ID is 6 digits. Try again." << endl;
		return false;
	}
	id = 0;
	for (string::size_type i = 0; i < 6; ++ i) {
		if (isdigit(input.at(i))) {
			id += input.at(i) - '0';// static_cast<int>(9 - 57 + input.at(i));
			if (i < 5) id *= 10;
		} else {
			cerr << "Invalid input. ID must be a number. Try again." << endl;
			return false;
		}
		
	}
	return true;
}

bool ExceptionHandler::validateCoursePrefix(string& input) const
{
	if (input.length() != 3)
	{
		cout << "Invalid input. Course prefix is 3 letters. "
			<< "Try again." << endl;
		input = "";
		return false;
	}
	else
	{
		// bool flag = false;
		// TODO: validate prefix ?
		// flag = isalpha() && flag;
		for_each(input.begin(), input.end(), [](char& currChar) {
			currChar = toupper(currChar);
		});
		return true;
	}
}

bool ExceptionHandler::validateCourseNo
	(const string& input, int& courseNo) const
{
	if (input.length() != 3)
	{
		cout << "Invalid input. Course number is 3 digits. "
			<< "Try again." << endl;
		return false;
	}
	else
	{
		courseNo = stoi(input);
		return true;
	}
}


