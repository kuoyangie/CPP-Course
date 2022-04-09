//                          CSC237-S1 Lab 13a: Mortgage
// Student:     Yenchi Kuo
// Due Date:    Saturday, November 6, 2021
// Description:
//              This program will calculate the monthly payment
//              and the total payment including interests
//              The extra credit portion will adapt the FSM concept
//              for printing out the whole payment process to a file

#include <iostream>
#include <fstream>
#include <string>
#include "Mortgage.h"
using namespace std;

void printBanners();
char getUserChoice();
string getFileName();

int main() {
    system("color 9E");
    system("title Lab 13a Mortgage  by Yenchi Kuo");

    ofstream loanFile;
    char userChoice = 'Y';

    printBanners();
    while (userChoice == 'Y') {
        Mortgage mortgage;
        string fileName;
        double loanAmount = 0.0;
        double interestRate = 0.0;
        int lengthOfRePay = 0;

        /* Data Input phase:
        *  File Name, Loan Amount, Annual Interest Rate, Length of loan in years
        */
        // #1 File Name
        fileName = getFileName();

        // #2 Loan Amount
        cout << "Please enter the amount of the loan: ";
        cin >> loanAmount;
        cin.ignore(100, '\n');
        mortgage.setLoanAmount(loanAmount);

        // #3 Annual Interest Rate
        cout << "Please enter the amount of interest rate in decimal form (example: 0.075): ";
        cin >> interestRate;
        cin.ignore(100, '\n');
        mortgage.setAnnualInterestRate(interestRate);

        // #4 Length of loan in years
        cout << "Please enter the length of loan in years: ";
        cin >> lengthOfRePay;
        cin.ignore(100, '\n');
        mortgage.setTotalYearsToRepay(lengthOfRePay);

        /* Process Data phase:
        *  Print out loan details on the console
        *  Output Process to the file
        */
        mortgage.printLoanDetails();
        mortgage.outputPaymentSchedule(fileName);
        // Close the output file as a good practice
        loanFile.close();

        userChoice = getUserChoice();
    }

    system("pause<0");
    return 0;
}

/* ------------------------------------------------------------------
*  This function will print out a nicely centered banner            *
*  Regarding the programs functions and programming concepts used   *
*  Also prints out the name of the programmer                       *
*  ------------------------------------------------------------------
*/
void printBanners() {
    cout << "\n"
        << "\t\t                   Lab 13a Mortgage and Classes                   \n"
        << "\t\t       This program will calculate the monthly payment and        \n"
        << "\t\t               the total payment including interests              \n"
        << "\t\t   This program can also print out the payment process to a file  \n"
        << "\t\t                          by    Yenchi Kuo                        \n\n";
}

/* ------------------------------------------------------------------
*  This function will get the file name from the user               *
*  and validate the file name by attempting to open the file with it*                                                                                                                                          *
*  Return type: string                                              *                                                                                                                                                  *
*  ------------------------------------------------------------------
*/
string getFileName() {
    string fileName;
    ofstream file;
    cout << "Enter output file name: ";
    cin >> ws;
    getline(cin, fileName);

    file.open(fileName);
    while (file.fail()) {
        system("color 7C");
        cout << "\aFailed to create file " << fileName
            << ". Please Enter the correct file name: ";
        cin >> ws;
        getline(cin, fileName);
        file.open(fileName);
    }
    system("color 9E");
    cout << "File created successfully.\n\n";
    file.close();
    return fileName;
}

/*  ------------------------------------------------------------------
*   This function will get the character from the user               *
*   regardless of the case, for this function will transform input   *
*   and validate input.                                              *                                                                                                              *
*   Return type: char                                                *                                                                                                               *
*   ------------------------------------------------------------------
*/
char getUserChoice() {
    char userChoice;
    cout << "Do you wish to process another loan? Enter (Y/N): ";
    cin >> userChoice;
    cin.ignore(100, '\n');
    userChoice = toupper(userChoice);

    while (userChoice != 'Y' && userChoice != 'N') {
        cout << "You must enter y to continue or n to quit the program.\n"
            << "Please try again. (Enter Y/N): ";
        cin >> userChoice;
        cin.ignore(100, '\n');
        userChoice = toupper(userChoice);
    }

    return userChoice;
}
