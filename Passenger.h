// Norman Lew
// CS 360
// Assignment 1
// Spring 2017

// This is the header file for the Passenger class.  It contains the name, address and phone number for a passenger, 
// as well as functions to set and get the passenger's paramaters.



#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <string>
using namespace std;

class Passenger
{
private:
	
	// Variables to hold the passenger information
	string firstName, lastName, address, phoneNumber;

public:

	// Constructors for the passenger
	Passenger();
	Passenger(string , string , string , string);

	// Set the last name for the passenger
	void setLastName(string);

	// Set the first name for the passenger
	void setFirstName(string);

	// Set the phone number for the passenger
	void setPhoneNumber(string);

	// Set the address for the passenger
	void setAddress(string);

	// Get the last name of the passenger
	string getLastName();

	// Get the first name of the passenger
	string getFirstName();

	// Get the phone number of the passenger
	string getPhoneNumber();

	// Get the address of the passenger
	string getAddress();

	// Prints the passenger information
	friend void printPassenger(Passenger &c);

	// Another way to print the passenger information.
	friend ostream& operator<< (ostream& os, Passenger &);

	// Checks to see if one passenger is the same as another
	bool operator==(Passenger);

	// Given two passengers, a and b, passenger a is less than passenger b if passenger a's last name comes alphabetically before
	// passenger b's.  If both have the same last name, the first names will be compared as well.
	bool operator<(Passenger c);

	// Given two passengers, a and b, passenger a is greater than passenger b is a's last name comes alphabetically after passenger
	// b's.  If both have the same last name, the first names will be compared as well.
	bool operator>(Passenger c);
};

#endif