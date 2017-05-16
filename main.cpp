// Norman Lew
// CS 300
// Spring 2017

// Assignment 2

// This is the main program for the Delta Airlines database.

#include "LinkedList.h"
#include "OrderedLinkList.h"
#include "Passenger.h"
#include "FlightManager.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	FlightManager theFlights;  // This variable contains information on the entire manifesto for our flights
	char menuSelection;
	string lastName, firstName, address, phoneNumber;
	int flightNumber;
	Passenger *p = NULL;

	// Ask the user which action they want to do with the phonebook and perform the task
	do {
		cout << "(A)dd | (S)earch | (D)elete | (L)ist | (Q)uit: ";
		cin >> menuSelection;

		// Prompt user for flight #, name, address, and phone number to enter into database
		if (menuSelection == 'A' || menuSelection == 'a')
		{
			cout << "Enter flight number: ";
			cin.ignore();
			cin >> flightNumber;
			cout << "Enter a last name: ";
			cin >> lastName;
			cout << "Enter a first name: ";
			cin >> firstName;
			cin.ignore();
			cout << "Enter an address: ";
			getline(cin, address);
			cout << "Enter a phone number: ";
			cin >> phoneNumber;

			Passenger c(firstName, lastName, address, phoneNumber);
			theFlights.addPassenger(flightNumber, c);

			cout << endl;
		}

		// Prompt user for flight number and passenger name to search for
		if (menuSelection == 'S' || menuSelection == 's')
		{
			cout << "Enter flight number: ";
			cin.ignore();
			cin >> flightNumber;
			cout << "Enter a last name: ";
			cin >> lastName;
			cout << "Enter a first name: ";
			cin >> firstName;

			Passenger c(firstName, lastName, "XXX", "XXX");

			p = theFlights.searchPassenger(flightNumber, c);

			if (p != NULL)
			{
				cout << "Address: " << p->getAddress() << endl;
				cout << "Phone number: " << p->getPhoneNumber();
			}

			cout << endl;
		}

		// Prompt user for flight number and passenger name to delete 
		if (menuSelection == 'D' || menuSelection == 'd')
		{
			cout << "Enter flight number: ";
			cin.ignore();
			cin >> flightNumber;
			cout << "Enter a last name: ";
			cin >> lastName;
			cout << "Enter a first name: ";
			cin >> firstName;

			Passenger c(firstName, lastName, "XXX", "XXX");
			theFlights.deletePassenger(flightNumber, c);
			cout << endl;
		}
		
		// Prompt the user for which flight number he or she would like to print the passenger list for
		if (menuSelection == 'L' || menuSelection == 'l')
		{
			cout << "Enter flight number: ";
			cin.ignore();
			cin >> flightNumber;
			theFlights.listPassenger(flightNumber);

			cout << endl;
		}

	} while (menuSelection != 'Q' && menuSelection != 'q');

	
	
	cin.get();
	cin.get();
	if (p != NULL)
		delete p;
	return 0;
}