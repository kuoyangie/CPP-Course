// Implementation file for the IntList class
#include <iostream>
#include <string>
#include "IntList.h"
using namespace std;


/*	-------------------------------------------------------------------------
*	Destructor for the IntList                                              *
*	This function deletes every node in the list           					*
*	-------------------------------------------------------------------------
*/
IntList::~IntList()
{
	ListNode* nodePtr;
	ListNode* nextNode;

	// Initialize nodePtr and place it at the beginning of the list
	nodePtr = head;

	while (nodePtr != nullptr) {		// The loop continues if nodePtr is not at the end of the list
		nextNode = nodePtr->next;		// nextNode serves as a temp holder for nodePtr future update
		delete nodePtr;					// delete the data in which the current posistion holds
		nodePtr = nextNode;				// Update the nodePtr by assign it with nextNode ptr;
	}
}

/*	-------------------------------------------------------------------------
*	This function will append a node containing the value passed into num   *
*	to the end of the list regardless of the sorted order					*
*	-------------------------------------------------------------------------
*/
void IntList::appendNode(int num) {
	ListNode* newNode;					// Point to a new node
	ListNode* nodePtr;					// Pointer for traversing the linked list

	newNode = new ListNode;
	newNode->value = num;				// Point to the input number
	newNode->next = nullptr;			// Prepare connection for the next node

	// If it is the beginning of the list (null list)
	if (!head)
		head = newNode;
	else {								// Otherwise, insert newNode at the end of list
		nodePtr = head;					// Initialize nodePtr to the head of list 
										// for future traversal
		while (nodePtr->next) {			// Traverse through list to find the last node
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;	// Update newNode to the latest position of the node
	}
}

/*	-------------------------------------------------------------------------
*	This function will insert a node containing the value passed into num   *
*	to the list with respect to the list's sorted order					    *
*	-------------------------------------------------------------------------
*/
void IntList::insertNode(int num) {
	ListNode* newNode;					// Allocate memory for a new node
	ListNode* nodePtr;					// Pointer for traversing the linked list
	ListNode* previousNode = nullptr;	// Point to the previous node

	// Allocate a new node and store the input number
	newNode = new ListNode;
	newNode->value = num;

	if (!head) {
		head = newNode;					// Create a new node if the linked list is a null list 
		newNode->next = nullptr;
	}
	else {
		nodePtr = head;					// Position nodePtr at the head of list
		previousNode = nullptr;			// Initialize previousNode

		// Traverse the linked list and skip all nodes whose value is less than input number
		while (nodePtr != nullptr && nodePtr->value < num) {
			previousNode = nodePtr;		// Update previousNode
			nodePtr = nodePtr->next;	// Update nodePtr to the next value for next comparison
		}

		// If the new node is the first in the list (the smallest value)
		// Insert it before all other nodes (base case)
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;// Append newNode after previousNode
			newNode->next = nodePtr;	 // Update next node to current nodePtr position (presumably the original node right after previousNode)
		}
	}
}

/*	-------------------------------------------------------------------------
*	This function will delete a designated node containing the value        *
*	passed into num from the list                        				    *
*	-------------------------------------------------------------------------
*/
void IntList::deleteNode(int num) {
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	// If the list is empty, return to the main function (do nothing)
	if (!head) {
		return;
	}

	// Determine if the first node is the one
	if (head->value == num) {
		nodePtr = head->next;				// Use nodePtr as temp holder for the first node
		delete head;						// delete the first node from the list
		head = nodePtr;						// Assign the value at nodePtr to the first value
	}

	else {
		nodePtr = head;						// Initialize nodePtr at the beginning of the list

		// Skip all nodes != the input number
		while (nodePtr != nullptr && nodePtr->value != num) {
			previousNode = nodePtr;			// Update previousNode 
			nodePtr = nodePtr->next;		// Update nodePtr to the next value for next comparison
		}

		// If nodePtr is not at the end of the list,
		// link previousNode—as a temp holder, to the node after nodePtr
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;						// Delete nodePtr
		}
	}
}

/*	-------------------------------------------------------------------------
*	This function will print out the nodes in the list                      *
*	If the list is empty, will print out list contents 0					*
*	Otherwise, print out the address, value, and the node's next address.	*
*	-------------------------------------------------------------------------
*/
void IntList::print() const {
	cout << "Head = " << head << endl;
	cout << "List contents: " << (!head ? "0.\n" : "\n");
	ListNode* nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr << ":\tvalue =\t"
			<< right << nodePtr->value << "\tnext =\t" << nodePtr->next << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

/*	-------------------------------------------------------------------------
*	This is the wrapper function of internalPrintRecursion() function   	*
*	so that the main function can call the wrapper function to call the     *
*	actual recursive function that requires private data fields in class    *
*	-------------------------------------------------------------------------
*/
void IntList::printRecursion() {
	cout << "Head = " << head << endl;
	cout << "List contents: " << (!head ? "0.\n" : "\n");
	internalPrintRecursion(head);
	cout << endl;
}

/*	-------------------------------------------------------------------------
*	This function will RECURSIVELY print out the nodes in the list          *
*	If the list is empty, will print out list contents 0		            *
*	Otherwise, print out the address, value, and the node's next address.	*
*	-------------------------------------------------------------------------
*/
void IntList::internalPrintRecursion(ListNode* node)
{
	if (node) {
		cout << node << ":\tvalue =\t" << right << node->value << "\tnext =\t" << node->next << endl;
		internalPrintRecursion(node->next);
	}
}

/*	-------------------------------------------------------------------------
*	This function will delete a designated node containing the value        *
*	passed into num from the list                        				    *
*	-------------------------------------------------------------------------
*/
void IntList::displayMaxValue() {
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;
	int largestSoFar;

	// If the list is empty, display warning message
	if (!head) {
		cout << "The list is empty.\n" << endl;
	}

	else {
		nodePtr = head;						// Place the nodePtr at the beginning of the list
		largestSoFar = nodePtr->value;		// Set the largestSoFar as the first element
		previousNode = nodePtr;
		// Traverse through the linked list
		// The loop continues until nodePtr hits the end of the list
		while (previousNode != nullptr) {
			// Update largestSoFar if the nodePtr value is larger than the current one
			if (nodePtr->value > largestSoFar) {
				largestSoFar = nodePtr->value;
			}
			// Update previousNode position
			nodePtr = nodePtr->next;		// Assign nodePtr with the next value in list
			previousNode = nodePtr;
		}
		cout << "The maximum value in list = " << largestSoFar << ".\n" << endl;
	}
}

/*	-------------------------------------------------------------------------
*	This function will traverse the linked list and add up                  *
*	element count during the process					        			*
*	Return data type: int							      					*
*	-------------------------------------------------------------------------
*/
int IntList::length()
{
	ListNode* nodePtr;
	int numberOfNodes = 0;

	if (!head) {
		return numberOfNodes;
	}

	nodePtr = head;
	while (nodePtr->next) {
		numberOfNodes++;
		nodePtr = nodePtr->next;
	}
	return numberOfNodes + 1;
}


/*	-------------------------------------------------------------------------
*	This function will traverse the linked list and add up                  *
*	element count during the process using recursive method					*
*	Return data type: int						      						*
*	-------------------------------------------------------------------------
*/
void IntList::lengthRecursion()
{
	int *numberOfNodes = 0;
	internalLengthRecursion(head, numberOfNodes);
}


void IntList::internalLengthRecursion(ListNode* node, int *numberOfNodes)
{
	ListNode* headHolder;
	headHolder = head;

	if (node) {
		(*numberOfNodes)++;
		node = node->next;
		internalLengthRecursion(node, numberOfNodes);
	}
	else {
		cout << "The number of " << (*numberOfNodes > 1? "nodes " : "node ")
			<< "in list, head = " << headHolder << " count = " << *numberOfNodes << ".\n" << endl;
	}
}

/*	-------------------------------------------------------------------------
*	This function will traverse the linked list and add up every number     *
*	of the node and return the sum											*
*	Return datat type: int													*
*	-------------------------------------------------------------------------
*/
int IntList::total()
{
	ListNode* nodePtr;
	int sumOfList = 0;

	if (!head) return sumOfList;
	else {
		nodePtr = head;

		while (nodePtr) {
			sumOfList += nodePtr->value;
			nodePtr = nodePtr->next;
		}
	}

	return sumOfList;
}
