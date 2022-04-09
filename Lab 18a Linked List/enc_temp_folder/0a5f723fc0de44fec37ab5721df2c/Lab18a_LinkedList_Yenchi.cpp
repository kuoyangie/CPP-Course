// 				CSC237-S1 Lab 18a: Linked List
//	Student: 	Yenchi Kuo
//	Due Date:	Saturday, December 11, 2021
//	Description:
//				This program is a practice for the concept of linked list
//				which includes create, append, insert, delete, traverse throughout the list

#include <iostream>
#include <iterator>
#include <algorithm>
#include "IntList.h"
using namespace std;

void printCommandList();
void printBanners();
bool commandListValidation(char);
char getUserChoice();

int main() {
	system("color 9E");
	system("title Lab 18a Linked List   by Yenchi Kuo");

	bool continueLoop = true;
	char commandChoice;
	int inputNum = 0;
	IntList intList;

	printBanners();
	printCommandList();

	do {
		commandChoice = getUserChoice();

		switch (commandChoice) {
		case 'A':
			cout << "Enter number to append to the list: ";
			cin >> inputNum;
			cin.ignore(100, '\n');
			intList.appendNode(inputNum);
			cout << endl;
			break;
		case 'C': 
			cout << "Length of list = "
				<< intList.length() << (intList.length() > 1 ? " nodes.\n" : " node.\n") << endl;
			break;
		case 'D':
			cout << "Enter number to delete from the list: ";
			cin >> inputNum;
			cin.ignore(100, '\n');
			intList.deleteNode(inputNum);
			cout << endl; 
			break;
		case 'I':
			cout << "Enter number to insert into the list: ";
			cin >> inputNum;
			cin.ignore(100, '\n');
			intList.insertNode(inputNum);
			cout << endl; 
			break;
		case 'M': intList.displayMaxValue(); break;
		case 'P': intList.print(); break;
		case 'S': intList.~IntList(); break;		
		case 'H': printCommandList(); break;
		case 'Q': continueLoop = false;
		case 'T': 
			cout << "Total of all list values = " << intList.total() << "\n" << endl;
			break;
		}
	} while (continueLoop);
}

/*	-------------------------------------------------------------------------
*	This function will print out a nicely centered banner                   *
*	-------------------------------------------------------------------------
*/
void printBanners() {
	cout << "\n"
		<< "\t\t               This lab is a practice for the concept of linked list               \n"
		<< "\t\t     which includes create, append, insert, delete, traverse throughout the list   \n"
		<< "\t\t                      Lab 18a: Linked List  by  Yenchi Kuo                         \n\n";
}

/*	-------------------------------------------------------------------------
*	This function will print out supported commands on the program startup, *
*	invalid command input, and when called upon.                            *
*	-------------------------------------------------------------------------
*/
void printCommandList()
{
	cout << "Supported Commands:\n"
		<< "\ta\tAPPEND a value to the list.\n"
		<< "\tc\tCOUNT the nodes in the list (display LENGTH of the list).\n"
		<< "\td\tDELETE a value from the list.\n"
		<< "\ti\tINSERT a value into the list.\n"
		<< "\tm\tdisplay MAXIMUM (largest) value in the list.\n"
		<< "\tp\tPRINT the list contents.\n"
		<< "\ts\tHaving a rough day? DELETE the whole list!\n"
		<< "\th\tPRINT this Command List.\n"
		<< "\tq\tQuit (end the program).\n"
		<< "\tt\tdisplay TOTAL (sum) of all values in the list\n" << endl;
}

/*	-------------------------------------------------------------------------
*	This function will prompt the user to enter an alphet corresponds to the*
*	command list. It invokes member function commandListValidation() to     *
*	validate the user input.                                                *
*	return data type: char                                                  *
*	-------------------------------------------------------------------------
*/
char getUserChoice()
{
	char userChoiceChar;
	cout << "Please enter command: ";
	cin >> userChoiceChar;
	cin.ignore(100, '\n');

	while (!commandListValidation(userChoiceChar)) {
		cout << "Invalid Command entry " << userChoiceChar << ". Please refer to the command list.\n" << endl;
		printCommandList();
		cout << "Please try again: ";
		cin >> userChoiceChar;
		cin.ignore(100, '\n');
	}

	// Make entry upper case
	userChoiceChar = toupper(userChoiceChar);
	return userChoiceChar;
}

/*	-------------------------------------------------------------------------
*	This function is a member function of getUserChoice() function,         *
*	it has local variables commandList[] (holds the available commands)     *
*	and exist (which validates the input).                                  *
*	return data type: bool                                                  *
*	-------------------------------------------------------------------------
*/
bool commandListValidation(char choice) {
	char commandList[] = { 'a', 'c', 'd', 'i', 'm', 'p', 'h', 'q', 's', 't' };
	bool exist = false;

	for (int i = 0; i < sizeof(commandList); i++) {
		if (choice == commandList[i]) {
			exist = true;
			return exist;
		}
	}
	return exist;
}
