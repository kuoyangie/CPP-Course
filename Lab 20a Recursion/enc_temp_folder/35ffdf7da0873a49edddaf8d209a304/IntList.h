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
	void internalPrintRecursion(ListNode*);
	void internalLengthRecursion(ListNode*, int);

public:
	IntList() {				// Default Constructor with null list
		head = nullptr;
	}

	~IntList();							// Destructor
	void appendNode(int);				// Append a new node at the end of the list
	void insertNode(int);				// Insert a new node into the list, maintaining a sorted order
	void deleteNode(int);				// Remove a node from the list
	void print() const;					// Output the contents of the list to the screen
	void printRecursion();				// Output the contents of the list recursively to the screen
	void displayMaxValue();				// Display the largest data value on the screen
	void lengthRecursion();				// Return the list length (number of nodes) to the caller using recursive call
	int length();						// Return the list length (number of nodes) to the caller
	int total();						// Return the total (sum) of all list values to the caller
};
#endif
