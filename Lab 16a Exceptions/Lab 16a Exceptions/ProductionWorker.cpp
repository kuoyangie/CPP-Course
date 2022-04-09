#include "ProductionWorker.h"
#include <iostream>
using namespace std;

// Default constructor
ProductionWorker::ProductionWorker() : Employee() {
	shift = 0; payRate = 0.0;
}

// Constructor
ProductionWorker::ProductionWorker(string workerName, string hiredDate, int workerShift, double workerPayrate) : Employee(workerName, hiredDate) {
	setEmployeeName(workerName);
	setHireDate(hiredDate);
	setShift(workerShift);
	setPayRate(workerPayrate);
}

// Mutator
/* -----------------------------------------------------------------------
// This function will invoke testShift function to validate input        *
// it will throw an exception if the input is not 1 or 2                 *
// -----------------------------------------------------------------------
*/
void ProductionWorker::setShift(int num)
{	
	testShift(num);
	shift = num;
}

/* -----------------------------------------------------------------------
// This function will invoke testPayRate function to validate input      *
// it will throw an exception if the input is less than 0                *
// -----------------------------------------------------------------------
*/
void ProductionWorker::setPayRate(double num)
{
	testPayRate(num);
	payRate = num;
}

// Accessors
int ProductionWorker::getShiftNumber() const
{
	return shift;
}

string ProductionWorker::getShiftName() const
{	
	return (shift == 1 ? "Day" : "Night");
}

double ProductionWorker::getPayRate() const
{
	return payRate;
}

// Member Methods
/* -----------------------------------------------------------------------
// This function will print out the worker data in a neat format         *
// -----------------------------------------------------------------------
*/
void ProductionWorker::printWorkerData() const
{
	cout << "\n"
		<< "\tName:\t\t\t" << getEmployeeName() << "\n"
		<< "\tEmployee number:\t" << "#" << getEmployeeNumber() << "\n"
		<< "\tHire date:\t\t" << getHireDate() << "\n"
		<< "\tShift:\t\t\t" << getShiftName() << "\n"
		<< "\tShift number:\t\t" << getShiftNumber() << "\n"
		<< "\tPay rate:\t\t" << getPayRate() << endl;
}

/* -----------------------------------------------------------------------
// This function takes in the input shift and validates the number       *
// Invoke the InvalidShift exception class if the number is not 1 or 2   *
// -----------------------------------------------------------------------
*/
void ProductionWorker::testShift(int shift) const
{
	if (shift != 1 && shift != 2) {
		throw InvalidShift(shift);
	}
}

/* -----------------------------------------------------------------------
// This function takes in the input rate and validates the number        *
// Invoke the InvalidPayRate exception class if the number is less than 0*
// -----------------------------------------------------------------------
*/
void ProductionWorker::testPayRate(double payRate) const {
	if (payRate < 0)
		throw InvalidPayRate(payRate);
}

/* -----------------------------------------------------------------------
// This function prompts the user to enter employee basic information    *
// validates the data fields in the try-catch block                      *
// returns Production Worker pointer object                              *
// -----------------------------------------------------------------------
*/
ProductionWorker* ProductionWorker::createNewProductionWorker()
{	
	string inputDate;
	string inputName;
	double inputRate;
	int inputShiftCode;

	cout << "Enter name of new employee: ";
	getline(cin, inputName);

	cout << "Enter hire date of new employee: ";
	getline(cin, inputDate);

	cout << "Enter shift for new employee (1 = day, 2 = night): ";
	cin >> inputShiftCode;
	cin.ignore(100, '\n');

	cout << "Enter hourly pay rate for new employee: ";
	cin >> inputRate;
	cin.ignore(100, '\n');

	try {
		ProductionWorker* newPW = new ProductionWorker;
		newPW -> setEmployeeName(inputName);
		newPW -> setHireDate(inputDate);
		newPW -> setShift(inputShiftCode);
		newPW -> setPayRate(inputRate);
		return newPW;
	}
	catch (InvalidHireDate hd) {
		cout << "Error: Invalid date format: " << hd.getInvalidHireDate() << ".\n"
			<< "The correct format should be MM/DD/YYYY." << endl;
	}
	catch (InvalidShift s) {
		cout << "Error: Invalid shift code: " << s.getShiftNumber() << ".\n"
			<< "The correct code should be 1 (day) or 2 (night)." << endl;
	}
	catch (InvalidPayRate pr) {
		cout << "Error: Invalid pay rate: " << pr.getInvalidPayRate() << ".\n"
			<< "The correct pay rate should be greater than or equal to 0." << endl;
	}
}