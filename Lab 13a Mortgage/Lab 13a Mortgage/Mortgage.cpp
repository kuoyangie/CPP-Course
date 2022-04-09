#include "Mortgage.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Default Constructor
Mortgage::Mortgage()
{
    loanAmount = 0.0;
    annualInterestRate = 0.0;
    totalYearsToRepay = 0;
}

// Constructor
Mortgage::Mortgage(double loanAmount, double annualInterestRate, int totalYearsToRepay)
{
    setLoanAmount(loanAmount);
    setAnnualInterestRate(annualInterestRate);
    setTotalYearsToRepay(totalYearsToRepay);
}

// Mutators
void Mortgage::setLoanAmount(double loan) { loanAmount = loan; }
void Mortgage::setAnnualInterestRate(double annualRate) { annualInterestRate = annualRate; }
void Mortgage::setTotalYearsToRepay(int yearsToPay) { totalYearsToRepay = yearsToPay; }

// Accessors
double Mortgage::getLoanAmount() const { return loanAmount; }
double Mortgage::getAnnualInterestRate() const { return annualInterestRate; }
double Mortgage::getMonthlyInterestRate() const { return annualInterestRate / 12; }
int Mortgage::getNumberOfPayments() const { return totalYearsToRepay * 12; }
int Mortgage::getTotalYearsToRepay() const { return totalYearsToRepay; }
double Mortgage::powerFactor() const { return pow((1 + getMonthlyInterestRate()), getNumberOfPayments()); }
double Mortgage::getMonthlyPayment() const { 
    return (loanAmount * getMonthlyInterestRate() * powerFactor()) / (powerFactor() - 1); 
}

/* ---------------------------------------------------------------------
*  This function will print out the basic loan information             *
*  on the console in a nicely formatted fashion                        *
*  ---------------------------------------------------------------------
*/
void Mortgage::printLoanDetails() const {
    cout << setprecision(4) << fixed << showpoint;
    cout << "\n\tLoan amount:\t\t" << "$" << loanAmount << endl;
    cout << "\tAnnual Interest Rate:\t" << annualInterestRate << endl;
    cout << "\tYears to repay:\t\t" << totalYearsToRepay << endl;
    cout << "\tMonthly Payment:\t" << "$" << getMonthlyPayment() << endl;
    cout << "\tTotal Pay back:\t\t" << "$" << setprecision(2) << fixed << getMonthlyPayment() * getNumberOfPayments() << "\n" << endl;
}

/* ---------------------------------------------------------------------
*  This function will write the detailed loan information              *
*  to the designated file for each monthly pay                         *
*  Parameter: string fileName                                          *                                                                                                   *
*  ---------------------------------------------------------------------
*/
void Mortgage::outputPaymentSchedule(string fileName) const {
    ofstream os;
    os.open(fileName);

    int numberOfPayments = getNumberOfPayments();
    double balance = getLoanAmount();

    // Writing basic loan information to the file
    os << setprecision(4) << fixed << showpoint;
    os << "\tLoan amount:\t\t" << "$" << loanAmount << endl;
    os << "\tAnnual Interest Rate:\t" << annualInterestRate << endl;
    os << "\tYears to repay:\t\t" << totalYearsToRepay << endl;
    os << "\tMonthly Payment:\t" << "$" << numberOfPayments << endl;
    os << "\tTotal Pay back:\t\t" << "$" << setprecision(2) << fixed << getMonthlyPayment() * numberOfPayments << "\n" << endl;

    // Writing detailed loan schedule by month to the file
    os << "\tPmt#\t" << "Payment Amount\t\t" << "Interest\t" << "Contrib to principle\t" << "Remaining Balance" << endl;
    os << setprecision(2) << fixed << right;
    for (int i = 1; i <= numberOfPayments; i++) {
        double interest = balance * getMonthlyInterestRate(); 
        double contribPrinciple = getMonthlyPayment() - interest;
        balance -= (getMonthlyPayment() - interest);

        os << "\t" << "   " << i << "\t\t" << getMonthlyPayment()
            << "\t\t" << interest
            << "\t\t\t" << contribPrinciple
            << "\t\t\t" << balance;
        os << endl;
    }
    // Close the file
    os.close();
    cout << "Output file " << fileName << " closed.\n";
}
