// This is a program of Club Admission Lab
// Club Admission Lab
// Yenchi Kuo
// 06/24/2021 04:27 UTC+8

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// System Configuration
	system("color 6");
	system("title,   Club Admission Lab     by Yenchi Kuo");

	// Declare the variables
	const double
		AGE_MIN = 21,
		AGE_MAX = 39.9999999999999;
	double age;
	string userName;

	// Banners
	cout << "\n"
		<< "\t\t                    The \"club admission\" lab                                             \n"
		<< "\t\t                    note that age is a double                                              \n"
		<< "\t\t                       needs an if ... else                                                \n"
		<< "\t\t                 loops for ever for easy testing                                           \n"
		<< "\t\t               uses named consts for easy updates                                          \n"
		<< "\t\t        ONLY customers with age in [" << AGE_MIN << ", " << AGE_MAX << ") are allowed in   \n"
		<< "\t\t    avoid entering more than 13 decimal places (rounding issues)                           \n"
		<< "\t\t                          by Yenchi Kuo                                                    \n\n";



	// Intentional forced loop for easy test
	while (true) {

		// Prompt for user's name and read with ws stream manipulator
		cout << "\nWhat is your full name?" << endl;
		cin >> ws;
		getline(cin, userName);

		// Prompt for user's age and display
		cout << "\nHow old are you," << "\"" << userName << "\"?" << endl;
		cin >> age;
		cin.ignore(10000, '\n');

		// Determine user's eligibility
		if ((AGE_MIN <= age) && (age < AGE_MAX))
		{
			cout << "\nWelcome to the club!\n";
		}
		else
		{
			cout << "\tSorry, you need to be between " << AGE_MIN << "(inclusive) and " << AGE_MAX << "(exclusive) \n"
				<< "\tto be eligible to enter this establishment and \n"
				<< "\tyou are " << (age < AGE_MIN ? "only " : "") << age << " years old.\n" << endl;
		}
		cout << "Next Customer, Please!\n";
		
		system("pause");
	}
	return 0;
}