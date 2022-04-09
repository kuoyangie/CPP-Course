// 				CSC237-S1 Lab 16a: Exceptions
//	Student: 	Yenchi Kuo
//	Due Date:	Saturday, December 4, 2021
//	Description:
//				This program is an enhanced version for Lab 15a
//				which includes exceptions and 
//				The lab is dedicated to practice the concept of exceptions

#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"
using namespace std;

void printBanners();
void printHelpText();
char getUserChoice();

int main() {
	// Console Configuration
	system("title CSC237-S1 Lab 16a Exceptions    by Yenchi Kuo");
	system("color 9E");

	// Basic information of the program
	printBanners();
	printHelpText();

	// Initialize Variables
	bool continueLoop = true;
	char userChoice;
	ProductionWorker* pw_ptr = NULL;

	while (continueLoop) {

		userChoice = getUserChoice();
		switch (userChoice) {
		case 'c': pw_ptr = ProductionWorker::createNewProductionWorker(); break;
		case 'h': printHelpText(); break;
		case 'p': pw_ptr->printWorkerData(); break;
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
void printBanners() {
	cout << "\n"
		<< "\t\t     This program will ask the user to create a new worker object     \n"
		<< "\t\t           and print the detailed information on the console          \n"
		<< "\t\t                   CSC237-S1 Lab 16a: Employee Class                  \n"
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
};
}