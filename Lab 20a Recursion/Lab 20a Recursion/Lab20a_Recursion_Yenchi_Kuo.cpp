// 				CSC237-S1 Lab 20a: Recursion
//	Student: 	Yenchi Kuo
//	Due Date:	Saturday, December 18, 2021
//	Description:
//				This program is a practice for the concept of recursion
//				and it is an extension lab of Lab 18a: Linked List

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
		case 'a':
			cout << "Enter number to append to the list: ";
			cin >> inputNum;
			cin.ignore(100, '\n');
			intList.appendNode(inputNum);
			cout << endl;
			break;
		case 'b': intList.printBackWards(); break;
		case 'c':
			cout << "Length of list = "
				<< intList.length() << (intList.length() > 1 ? " nodes.\n" : " node.\n") << endl;
			break;
		case 'C':
			cout << "Printing out Length of list using recursive method.\n";
			intList.lengthRecursion();
			break;
		case 'd':
			cout << "Enter number to delete from the list: ";
			cin >> inputNum;
			cin.ignore(100, '\n');
			intList.deleteNode(inputNum);
			cout << endl;
			break;
		case 'i':
			cout << "Enter number to insert into the list: ";
			cin >> inputNum;
			cin.ignore(100, '\n');
			intList.insertNode(inputNum);
			cout << endl;
			break;
		case 'm': intList.displayMaxValue(); break;
		case 'p': intList.print(); break;
		case 'h': printCommandList(); break;
		case 'q': continueLoop = false;
		case 'r': intList.printRecursion(); break;
		case 't': cout << "Total of all list values = " << intList.total() << "\n" << endl; break;
		case 'T': intList.totalRecursion(); break;
		}
	} while (continueLoop);
}

/*	-------------------------------------------------------------------------
*	This function will print out a nicely centered banner                   *
*	-------------------------------------------------------------------------
*/
void printBanners() {
	cout << "\n"
		<< "\t\t               This lab is a practice for the concept of recursion               \n"
		<< "\t\t                  which is an extension of lab 18a: Linked List  		 \n"
		<< "\t\t                       Lab 20a: Recursion  by  Yenchi Kuo                        \n\n";
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
		<< "\tb\tBACKWARDS RECURSIVE PRINT: use recursion to print the list backwards.\n"
		<< "\tc\tCOUNT the nodes in the list (display LENGTH of the list).\n"
		<< "\tC\t(upper-case C) Use Recursion to COUNT the number of nodes in the list.\n"
		<< "\td\tDELETE a value from the list.\n"
		<< "\ti\tINSERT a value into the list.\n"
		<< "\tm\tdisplay MAXIMUM (largest) value in the list.\n"
		<< "\tp\tPRINT the list contents.\n"
		<< "\tr\tRECURSIVELY print the contents of the list.\n"
		<< "\tt\tdisplay TOTAL (sum) of all values in the list\n"
		<< "\tT\t(upper-case T) use RECURSION to calculate TOTAL of all list values.\n"
		<< "\th\tPRINT this Command List.\n"
		<< "\tq\tQuit (end the program).\n" << endl;
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
	char commandList[] = { 'a', 'b', 'c', 'C', 'd', 'i', 'm', 'p', 'h', 'q', 'r', 't', 'T' };
	bool exist = false;

	for (int i = 0; i < sizeof(commandList); i++) {
		if (choice == commandList[i]) {
			exist = true;
			return exist;
		}
	}
	return exist;
}t[i]) {
			exist = true;
			return exist;
		}
	}
	return exist;
}