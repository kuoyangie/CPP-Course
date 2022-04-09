// 				CSC237-S1 Lab 15a: Employee Class
//	Student: 	Yenchi Kuo
//	Due Date:	Saturday, November 20, 2021
//	Description:
//				This program will ask the user to create a new worker object
//				and print the detailed information on the console
//				The lab is dedicated to practice the concept of inheritance and polymorphism

#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"
using namespace std;

void printBanners();
void printHelpText();
string getName();
string getDate();
int getOneOrTwo();
double getRate();
char getUserChoice();
ProductionWorker createProductionWorker();

int main() {
	// Console Configuration
	system("title CSC237-S1 Lab 15a Employee Class    by Yenchi Kuo");
	system("color 9E");

	// Basic information of the program
	printBanners();
	printHelpText();

	// Initialize Variables
	bool continueLoop = true;
	char userChoice;
	ProductionWorker newProductionWorker;

	while (continueLoop) {
		
		userChoice = getUserChoice();
		switch (userChoice) {
		case 'c': newProductionWorker = createProductionWorker(); break;
		case 'h': printHelpText(); break;
		case 'p': newProductionWorker.printWorkerData(); break;
		case 'q': continueLoop = false;
		}
	}

	// End of program
	system("pause>0");
	return 0;
}

/*	************************************************************************
*	This function will print out a nicely centered banners                 *
*   ************************************************************************
*/
void printBanners(){
	cout << "\n"
		<< "\t\t     This program will ask the user to create a new worker object     \n"
		<< "\t\t           and print the detailed information on the console          \n"
		<< "\t\t                   CSC237-S1 Lab 15a: Employee Class                  \n"
		<< "\t\t                             by  Yenchi Kuo                           \n\n";
}

/*	************************************************************************
*	This function will print out the help text with supported commands     *
*   ************************************************************************
*/
void printHelpText() {
	cout << "\n"
		<< "Supported Commands:\n"
		<< "\tc" << "\tCreate a new ProductionWorker object.\n"
		<< "\th" << "\tPrint help text.\n"
		<< "\tp" << "\tPrint ProductionWorker information.\n"
		<< "\tq" << "\tQuit (end the program).\n";
}

/*	************************************************************************
*	This function will get the name of the employee from the user          *
*   ************************************************************************
*/
string getName()
{
	string inputName;
	cout << "Enter name of new employee: ";
	getline(cin, inputName);

	return inputName;
}

/*	************************************************************************
*	This function will get the hire date of the employee from the user     *
*   ************************************************************************
*/
string getDate()
{
	string inputDate;
	cout << "Enter hire date of new employee: ";
	getline(cin, inputDate);

	return inputDate;
}

/*	************************************************************************
*	This function will get the shift code of the employee from the user    *
*   ************************************************************************
*/
int getOneOrTwo()
{
	int inputShiftCode;
	cout << "Enter shift for new employee (1 = day, 2 = night): ";
	cin >> inputShiftCode;

	while (inputShiftCode != 1 && inputShiftCode != 2) {
		cout << "You must enter either 1 or 2. Try again: ";
		cin >> inputShiftCode;
		cin.ignore(100, '\n');
	}

	return inputShiftCode;
}

/*	************************************************************************
*	This function will get the employee's hourly pay rate from the user    *
*   ************************************************************************
*/
double getRate()
{
	double inputRate;
	cout << "Enter hourly pay rate for new employee: ";
	cin >> inputRate;
	cin.ignore(100, '\n');

	while (inputRate <= 0) {
		cout << "The hourly rate must be larger than 0. Try again: ";
		cin >> inputRate;
		cin.ignore(100, '\n');
	}

	return inputRate;
}

/*	************************************************************************
*	This function will get the user's command character                    *
*   ************************************************************************
*/
char getUserChoice() {
	char userChoice;
	cout << "\nPlease enter your choice from the command list (or 'h' for help): ";
	cin >> userChoice;
	cin.ignore(100, '\n');

	while (userChoice != 'c' && userChoice != 'h' && userChoice != 'p' && userChoice != 'q') {
		printHelpText();
		cout << "Invalid input. Please refer to the help text and try again: ";
		cin >> userChoice;
		cin.ignore(100, '\n');
	}

	return userChoice;
}

/*	************************************************************************
*	This function will create a new ProductionWorker Object                *
*	Return type: Class Object                                              *
*   ************************************************************************
*/
ProductionWorker createProductionWorker() {
	cout << endl;
	string name = getName();
	string hireDate = getDate();
	int shiftCode = getOneOrTwo();
	double payRate = getRate();

	ProductionWorker employee = ProductionWorker(name, hireDate, shiftCode, payRate);
	return employee;
}