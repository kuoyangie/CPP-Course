// Implementation file for the Employee class
#include "Employee.h"
#include <string>
#include <cctype>
using namespace std;

int Employee::lastEmployeeNumberIssued = 0;   // Sequential employee number
	// Default constructor
Employee::Employee()
{
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = "";
	hireDate = "";
}

// Constructor
Employee::Employee(string aName, string aDate)
{
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = aName;
	hireDate = aDate;
}

// Mutators
void Employee::setEmployeeName(string n)
{
	employeeName = n;
}

void Employee::setHireDate(string date)
{
	bool correctNumField = false;
	bool correctDelimField = false;
	if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[3]) && isdigit(date[4]) && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9])) {
		correctNumField = true;
	}	// Check for month, day, year

	if (date[2] == '/' && date[5] == '/') {
		correctDelimField = true;
	} // Check for the correct forward slash

	if (date.length() != 10 && !correctNumField && !correctDelimField) {
		hireDate = date;
	}
	else throw InvalidHireDate(date);
}

// Accessors
string Employee::getEmployeeName() const
{
	return employeeName;
}

int Employee::getEmployeeNumber() const
{
	return employeeNumber;
}

string Employee::getHireDate() const
{
	return hireDate;
}

int Employee::getLastEmployeeNumberIssued()
{
	return lastEmployeeNumberIssued;
}



