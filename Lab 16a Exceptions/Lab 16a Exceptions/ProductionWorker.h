#pragma once
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include <iostream>
#include "Employee.h"
using namespace std;

class ProductionWorker : public Employee {
private:
	int shift;
	double payRate;

public:
	// Default Constructor
	ProductionWorker();

	// Constructor
	ProductionWorker(string workerName, string hiredDate, int workerShift, double workerPayrate);

	// Mutators
	void setShift(int num);
	void setPayRate(double num);

	// Accessors
	int getShiftNumber() const;
	string getShiftName() const;
	double getPayRate() const;
	void printWorkerData() const;

	void testShift(int shift) const;
	void testPayRate(double payRate) const;
	static ProductionWorker* createNewProductionWorker();

	// InvalidPayRate Exception Class
	class InvalidPayRate {
	private:
		double payRate;
	public:
		InvalidPayRate(double inputPayRate)
		{
			payRate = inputPayRate;
		}

		double getInvalidPayRate() const
		{
			return payRate;
		}
	};

	// InvalidShift Exception Class
	class InvalidShift {
	private:
		int shiftNumber;
	public:
		InvalidShift(int inputShiftNumber) {
			shiftNumber = inputShiftNumber;
		}

		int getShiftNumber() const {
			return shiftNumber;
		}
	};
};
#endif
