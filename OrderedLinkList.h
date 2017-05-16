// Norman Lew
// CS 300
// Spring 2016

// Assignment 2

// This is the header file for the OrderedLinkList class.  It is derived from the LinkedList class.  It adds the additional 
// functionality of maintaining the links in order.



#ifndef ORDEREDLINKLIST_H_
#define ORDEREDLINKLIST_H_
#include "LinkedList.h"
#include "Passenger.h"
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class OrderedLinkList:public LinkedList<T>
{
public:
	
	// Function to add a link to the ordered linked list
	void insert(T&);

	// Function to delete a link from the ordered linked list
	void delete_node(T&);

	// Function to search for a link in the ordered linked list
	T* search(T&);
};

// Function to add a link to the ordered linked list
template <class T>
void OrderedLinkList<T>::insert(T &item)
{
	// Create the new node
	node<T>* theNewNode = new node<T>;
	theNewNode->data = item;

	// If the list is not empty, put the new node in the right place
	if (head != NULL) {
		if (theNewNode->data < head->data)
		{
			theNewNode->next = head;
			head = theNewNode;
			
		}

		// Put the node in the appropriate position if its data value is greater than the one in head
		else
		{
			bool newNodeHasBeenInserted = false;
			node<T> *temp = head;
			while (temp->next != NULL && !newNodeHasBeenInserted)
			{
				if (theNewNode->data < temp->next->data)
				{
					theNewNode->next = temp->next;
					temp->next = theNewNode;
					newNodeHasBeenInserted = true;
				}
				else {
					temp = temp->next;
				}
			}
			if (!newNodeHasBeenInserted)
			{
				theNewNode->next = NULL;
				last->next = theNewNode;
				last = theNewNode;;
				newNodeHasBeenInserted = true;
			}
		}

	}

	// If the list is empty, put the new node as the first node
	else
	{
		theNewNode->next = NULL;
		head = theNewNode;
		last = theNewNode;
	}
	count++;
}



// This function overrides the delete function in LinkedList
// The difference between this delete function and the delete function in LinkedList is that this delete function will stop
// searching the list as soon as it is known that all further nodes to examine in the list are greater than the one being
// searched for
template <class T>
void OrderedLinkList<T>::delete_node(T& c)
{
	bool nodeIsFound = false;

	// Check to see if the list is empty
	if (head == NULL)
	{
		cout << "The list is empty\n";
	}

	// Find the node to delete, if it exists
	else
	{
		node<T> *p = head;
		node<T> *q = head->next;
		if (head->data == c)
		{
			nodeIsFound = true;
			head = head->next;
			delete p;
			count--;
		}
		else
		{
			while (q != NULL && !(nodeIsFound) && !(q->data > c))
			{
				if (q->data == c)
				{
					nodeIsFound = true;
					p->next = q->next;
					count--;
				}
				else {
					p = q;
					q = q->next;
				}
			}
		}
	}
	if (!nodeIsFound)
	{
		cout << "Could not find passenger\n";
	}
}

// This function overrides the search function for the Linked List.  Like the delete function, it differs from the Linked List
// search function in that it will stop searching for a match when it is clear that any matches will not be occuring with further searching
template <class T>
T* OrderedLinkList<T>::search(T& c)
{
	if (!is_empty())
	{
		node<T>* temp = head;
		while (temp != NULL)
		{
			if (temp->data > c)
			{
				return NULL;
			}
			else if (temp->data == c)
			{
				return &temp->data;
			}
			else {
				temp = temp->next;
			}
		}
	}
	
	return NULL;
}

#endif