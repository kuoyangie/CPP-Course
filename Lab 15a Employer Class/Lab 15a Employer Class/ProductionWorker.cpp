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
void ProductionWorker::setShift(int num)
{	
	shift = num;
}

void ProductionWorker::setPayRate(double num)
{
	payRate = num;
}

// Accessors
int ProductionWorker::getShiftNumber() const
{
	return shift;
}

string ProductionWorker::getShiftName() const
{
	return (getShiftNumber() == 1 ? "Day" : "Night");
}

double ProductionWorker::getPayRate() const
{
	return payRate;
}

// Member Method
void ProductionWorker::printWorkerData() const
{
	cout << "\n"
		<< "\tName:\t\t\t" << getEmployeeName() << "\n"
		<< "\tEmployee number:\t" << "#" << getEmployeeNumber() - 1 << "\n"
		<< "\tHire date:\t\t" << getHireDate() << "\n"
		<< "\tShift:\t\t\t" << getShiftName() << "\n"
		<< "\tShift number:\t\t" << getShiftNumber() << "\n"
		<< "\tPay rate:\t\t" << getPayRate() << endl;
}
