#pragma once
#ifndef INTLIST
#define INTLIST

class IntList {
private:
	struct ListNode {
		int value;
		struct ListNode* next;
	};
	ListNode* head;
	void internalPrintRecursion(ListNode*); // Output the contents of the list recursively to the screen
	void internalBackwardPrint(ListNode*);	// Backwards recursive function that print the node list
	int internalLengthRecursion(ListNode*);	// Return the list length (number of nodes) to the caller using recursive call
	int internalTotalRecursion(ListNode*);	// Return the sum of the linked list elements

public:
	IntList() {				// Default Constructor with null list
		head = nullptr;
	}

	~IntList();								// Destructor
	void appendNode(int);					// Append a new node at the end of the list
	void insertNode(int);					// Insert a new node into the list, maintaining a sorted order
	void deleteNode(int);					// Remove a node from the list
	void print() const;						// Output the contents of the list to the screen
	void printRecursion();					// Wrapper function of internalPrintRecusion function
	void displayMaxValue();					// Display the largest data value on the screen
	void lengthRecursion();					// Wrapper function of internalLengthRecursion
	void printBackWards();					// Wrapper function of internalBackwardPrint
	void totalRecursion();					// Wrapper function of internalTotalRecursion
	int length();							// Return the list length (number of nodes) to the caller
	int total();							// Return the total (sum) of all list values to the caller
};
#endif
