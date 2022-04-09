// 				CSC237-S1 Project 2: Automobile Speed/Distance Application Program
//	Student: 	Yenchi Kuo
//	Due Date:	Saturday, October 16, 2021
//	Description:
//		This program is a Finite State Machine simulator which involves
//		simulation of a car's speed and the distance traveled over a period of time

#include <iostream>
#include <iomanip>
using namespace std;

char userChoice();
void helpText();
void printBanners();
void outputStatusHeader();
void cruise(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval);
void accelerate(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval);
void brake(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval);
void setTimeInterval(int& timeInterval);
void setAcceleration(int& delta);
void demonstration(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval);
void resetData(double& currentSpeed, double& previousSpeed, double& totalFeetTraveled, int& delta, int& timeInterval);
void exitProgram();



int main() {
	system("color 9E");
	system("title Automobile Speed/Distance Application Program  by   Yenchi Kuo");

	printBanners();
	
	double currentSpeed = 0;	// Miles per Hour
	double averageSpeed = 0;	// Miles per Hour
	double previousSpeed = 0;	// Miles per Hour
	int delta = 5;				// Acceleration 
	int timeInterval = 1;
	double totalFeetTraveled = 0; // Default 0
	char userCommand;

	helpText();
	outputStatusHeader();
	do {
		cout << fixed << setprecision(2);
		userCommand = userChoice();
		switch (userCommand) {
		case 'a': accelerate(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval); break;
		case 'b': brake(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval); break;
		case 'c': cruise(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval); break;
		case 'd': demonstration(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval); break;
		case 'h': helpText(); break;
		case 'q': exitProgram(); break;
		case 'r': setAcceleration(delta); break;
		case 't': setTimeInterval(timeInterval); break;
		case 'x': resetData(currentSpeed, previousSpeed, totalFeetTraveled, delta, timeInterval); break;
		}
	} while (userCommand != 'q');


	return 0;
}

// This function will print out a nicely-centered banner
void printBanners() {
	cout << "\n"
		<< "\t\t              This program is a Finite State Machine simulator which involves         \n"
		<< "\t\t     the simulation of a car's speed and the distance traveled over a period of time  \n"
		<< "\t\t                      Automobile Speed/ Distance Application Program                  \n"
		<< "\t\t                                      by   Yenchi Kuo                                 \n\n";
}

// This function will print out the status header
void outputStatusHeader() {
	cout << "\tFunction"
		<< "\tCurrent State"
		<< "\tCurrent Speed"
		<< "\tInterval Distance"
		<< "\tTotal Feet (and miles) Traveled\n\n";
}

// -------------------------------------------------------------------------------------------
// This function takes in currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled       * 
// as pass-by-reference values, and receive delta, timeInterval as passy-by-value parameters *
// to calculate and update the pass-by-reference variables and print out the results.        *
// -------------------------------------------------------------------------------------------
void accelerate(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval) {
	double averageSpeed_FPS;
	double intervalFeetTraveled;

	previousSpeed = currentSpeed;
	currentSpeed = currentSpeed + delta;

	// Conversion from Miles to Feet
	averageSpeed = (previousSpeed + currentSpeed) / 2.0;
	averageSpeed_FPS = averageSpeed * 5280 / 3600;
	intervalFeetTraveled = averageSpeed_FPS * timeInterval;
	totalFeetTraveled += intervalFeetTraveled;

	cout << "\tAccelerate"
		<< "\tAccelerating..."
		<< "\t" << setw(12) << right << currentSpeed
		<< "\t" << setw(12) << right << intervalFeetTraveled
		<< "\t" << setw(12) << right << totalFeetTraveled << " (" << totalFeetTraveled / 5280 << ")\n";
}

// -------------------------------------------------------------------------------------------
// This function takes in currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled       *
// as pass-by-reference values, and receive delta, timeInterval as passy-by-value parameters *
// to calculate and update the pass-by-reference variables and print out the results.        *
// The brake function has two events. One when the current speed is greater than 0,          *
// and the other iss equal or smaller than 0.                                                *
// -------------------------------------------------------------------------------------------
void brake(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval) {
	double averageSpeed_FPS;
	double intervalFeetTraveled;
	previousSpeed = currentSpeed;
	currentSpeed = currentSpeed - delta;
	if (currentSpeed <= 0) {
		currentSpeed = 0;
	}

	// Conversion from Miles to Feet
	averageSpeed = (previousSpeed + currentSpeed) / 2.0;
	averageSpeed_FPS = averageSpeed * 5280 / 3600;
	intervalFeetTraveled = averageSpeed_FPS * timeInterval;
	totalFeetTraveled += intervalFeetTraveled;

	cout << "\tBrake" << (currentSpeed == 0 ? "\t\tStopped..." : "\t\tBraking...")
		<< "\t" << setw(12) << right << currentSpeed
		<< "\t" << setw(12) << right << intervalFeetTraveled
		<< "\t" << setw(12) << right << totalFeetTraveled << " (" << totalFeetTraveled / 5280 << ")\n";
}

// -------------------------------------------------------------------------------------------
// This function takes in currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled       *
// as pass-by-reference values, and receive delta, timeInterval as passy-by-value parameters *
// to calculate and update the pass-by-reference variables and print out the results.        *
// The cruise function has two events. One when the current speed is greater than 0,         *
// and the other iss equal or smaller than 0.                                                *
// -------------------------------------------------------------------------------------------
void cruise(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval) {
	double averageSpeed_FPS;
	double intervalFeetTraveled;
	previousSpeed = currentSpeed;

	// Conversion from Miles to Feet
	averageSpeed = (previousSpeed + currentSpeed) / 2.0;
	averageSpeed_FPS = averageSpeed * 5280 / 3600;
	intervalFeetTraveled = averageSpeed_FPS * timeInterval;
	totalFeetTraveled += intervalFeetTraveled;

	cout << "\tCruise"
		<< (currentSpeed <= 0 ? "\t\tStopped..." : "\t\tCruising...")
		<< "\t" << setw(12) << right << currentSpeed
		<< "\t" << setw(12) << right << intervalFeetTraveled
		<< "\t" << setw(12) << right << totalFeetTraveled << " (" << totalFeetTraveled / 5280 << ")\n";
}

// ----------------------------------------------------------------------
// This function will get user's choice of a single-letter command      *
// and return the correspond command back to main function.             *
// If the entry is not on the command menu,                             *
// throws a warning and pull the menu for reference (see default).      *
// Return type: char                                                    *
// ----------------------------------------------------------------------
char userChoice() {
	char inputCharacter;
	cout << "Command: ";
	cin >> inputCharacter;
	cin.ignore(100, '\n');

	switch (inputCharacter) {
	case 'a': return 'a'; break;
	case 'b': return 'b'; break;
	case 'c': return 'c'; break;
	case 'd': return 'd'; break;
	case 'h': return 'h'; break;
	case 'r': return 'r'; break;
	case 't': return 't'; break;
	case 'q': return 'q'; break;
	case 'x': return 'x'; break;
	default: {
		cout << "Invalid input. Please refer to the command characters menu.";
		return 'h';
	}
	}
}

// This function will print out the help text in the console.
void helpText() {
	cout << "These are the single-letter commands:\n"
		<< "\ta" << "\tAccelerate.\n"
		<< "\tb" << "\tBrake.\n"
		<< "\tc" << "\tCruise.\n"
		<< "\td" << "\tDemo.\n"
		<< "\th" << "\tPrint the help text.\n"
		<< "\tq" << "\tQuit (end the program)\n"
		<< "\tr" << "\tChange the default acceleration.\n"
		<< "\tt" << "\tChange time interval.\n"
		<< "\tx" << "\tReset data to default values.\n\n";
}

// This function allows user to change the time interval.
void setTimeInterval(int& timeInterval) {
	int userInputInterval;
	cout << "Enter a wanted time interval: ";
	cin >> userInputInterval;
	cin.ignore(100, '\n');

	while (cin.fail()) {
		cout << "Invalid input. Please enter a WHOLE NUMBER: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> userInputInterval;
	}
	timeInterval = userInputInterval;
}

// This function allows user to change the delta variable (acceleration).
void setAcceleration(int& delta) {
	int userInputAcceleration;
	cout << "Enter a wanted acceleration: ";
	cin >> userInputAcceleration;
	cin.ignore(100, '\n');

	while (cin.fail()) {
		cout << "Invalid input. Please enter a WHOLE NUMBER: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> userInputAcceleration;
	}
	delta = userInputAcceleration;
}

// This function will print out a series of event for program demonstration.
void demonstration(double& currentSpeed, double& previousSpeed, double& averageSpeed, double& totalFeetTraveled, int delta, int timeInterval) {
	// Resetting the reference variables
	currentSpeed = 0;
	previousSpeed = 0;
	totalFeetTraveled = 0;
	delta = 5;
	timeInterval = 1;

	for (int i = 0; i < 3; i++)
		cruise(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval);

	for (int j = 0; j < 5; j++)
		accelerate(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval);

	for (int k = 0; k < 5; k++)
		cruise(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval);

	for (int l = 0; l < 8; l++)
		brake(currentSpeed, previousSpeed, averageSpeed, totalFeetTraveled, delta, timeInterval);
}

// -------------------------------------------------------------------------------------------------------------------
// This function will reset all reference data (currentSpeed, previousSpeed, totalFeetTraveled, delta, timeInterval) *
// Back to default values.                                                                                           *
// -------------------------------------------------------------------------------------------------------------------
void resetData(double& currentSpeed, double& previousSpeed, double& totalFeetTraveled, int& delta, int& timeInterval) {
	currentSpeed = 0;
	previousSpeed = 0;
	totalFeetTraveled = 0;
	delta = 5;
	timeInterval = 1;

	cout << "All data are reset to default values." << endl;
}
// This function will exit the program upon invokation.
void exitProgram() {
	exit(0);
}