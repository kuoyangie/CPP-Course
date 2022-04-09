// This is a redesigned version of Validatie day of the week program
// Validate day of the week (Function)
// Yenchi Kuo
// Last Modified 7/21/2021 04:00 AM UTC+8

#include <iostream>
using namespace std;

void printBanners();
void consoleConfig();
char getChar();
string displayDay(char dayCode);

const char
	MONDAY = 'M',
	TUESDAY = 'T',
	WEDNESDAY = 'W',
	THURSDAY = 'H',
	FRIDAY = 'F',
	WEEKEND = 'S';

int main()
{
	printBanners();
	consoleConfig();

	while (true)
	{
		char dayCode;
		
		// Prompt
		cout << "Please enter the code of the day of the week you want:";
		dayCode = getChar();

		cout << "****   Your day is: ";
		cout << displayDay(dayCode);
	}
	return 0;
}

	// ************************************************************
	// Function Definition for banners                            *
	// ************************************************************
	void printBanners(){
		cout << "\n"
			<< "\t\t   Find the day of the week using switch case   \n"
			<< "\t\t     validate input FIRST using while loop      \n"
			<< "\t\t               and function call                \n"
			<< "\t\t                by  Yenchi Kuo                  \n\n"
			<< "***************************************************************************\n"
			<< "* You should have ONLY ONE input validation loop to check if the day code *\n"
			<< "* Make sure you that loop test ALL possible UNACCEPTABLE situations       *\n"
			<< "* If unacceptable input is found                                          *\n"
			<< "* \tchange the console color to b1 and                                *    \n"
			<< "* \tbeep to attract the user's attention                              *    \n"
			<< "* use conditional operator to customize your feedback                     *\n"
			<< "* \t(i.e. digit vs special char) INSIDE that loop.                    *    \n"
			<< "* AFTER you validate that the input is valid                              *\n"
			<< "* \trestore the console color and                                     *    \n"
			<< "* \tcheck if it is NOT captial and convert if needed                  *    \n"
			<< "* You are NOT allowed to use                                              *\n"
			<< "* \tthe ASCII values of ANY character                                 *    \n"
			<< "* \tany library functions, like the                                   *    \n"
			<< "* \tisdigit, isupper, toupper, isalnum, isalpha, etc.                 *    \n"
			<< "***************************************************************************\n\n";
	}

	// ************************************************************
	// Function Definition for console configuration              *
	// ************************************************************
	void consoleConfig()
	{
		system("title, Validate Day of Week (Function)    by Yenchi Kuo");
		system("color 9E");
	}

	// ************************************************************
	// Function Definition for getting characters                 *
	// ************************************************************
	char getChar()
	{
		char choiceOfDay;
		
		cin >> choiceOfDay; cin.ignore(100, '\n');

		// Validate
		while (choiceOfDay < 'A' || (choiceOfDay < 'a' && choiceOfDay > 'Z') || choiceOfDay > 'z')
		{
			system("color b1");
			cout << "\a";  // Change the color of the console and BEEP!

			cout << "You can NOT have ";
			(choiceOfDay >= '0' && choiceOfDay <= '9' ? cout << "DIGITS " : cout << "SPECIAL CHARACTERS ");
			cout << "for days code in this program\n"
				<< "Please give a letter code: \n";

			cin >> choiceOfDay; cin.ignore(100, '\n');
		}
		// Change the console color back to the original after entering a correct code
		system("color 9E");

		// Capitalizing lower case alphabets
		if (choiceOfDay <= 'z' && choiceOfDay >= 'a')
		{
			choiceOfDay -= ('z' - 'Z');
			cout << "You should have typed '" << choiceOfDay << "'.\n\n";
		}
		return choiceOfDay;
	}

	// ************************************************************
	// Function Definition for displayDay                         *
	// It reads the validated input from choiceOfDay and          *
	// Display the day chosen of the week                         *
	// ************************************************************
	string displayDay(char choiceOfDay) {
		switch (choiceOfDay)
		{
		case 'M': return "Monday.\n\n";
		case 'T': return "Tuesday.\n\n";
		case 'W': return "Wednesday.\n\n";
		case 'H': return "Thursday.\n\n";
		case 'F': return "Friday.\n\n";
		case 'S': return "Weekend.\n\n";
		default: return "No such day.\n\n";
		}
	}