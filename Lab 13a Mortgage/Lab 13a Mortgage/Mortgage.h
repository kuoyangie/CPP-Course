#pragma once
#ifndef MORTGAGE_H
#define MORTGAGE_H
#include <string>
class Mortgage
{
private:
    double loanAmount;
    double annualInterestRate;
    int totalYearsToRepay;
public:
    // Constructors
    Mortgage();
    Mortgage(double loanAmount, double annualInterestRate, int totalYearsToRepay);

    // Mutator
    void setLoanAmount(double loan);
    void setAnnualInterestRate(double annualRate);
    void setTotalYearsToRepay(int yearsToPay);

    // Accessors
    double getLoanAmount() const;
    double getAnnualInterestRate() const;
    double getMonthlyInterestRate() const;
    double getMonthlyPayment() const;
    double powerFactor() const;
    int getNumberOfPayments() const;
    int getTotalYearsToRepay() const;
    void printLoanDetails() const;
    void outputPaymentSchedule(std::string fileName) const;
};
#endif
