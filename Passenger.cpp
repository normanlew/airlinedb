// Norman Lew
// CS 360
// Assignment 1
// Spring 2017

// This is the implementation file for the Passenger class.  It contains the name, address and phone number for a passenger, 
// as well as functions to set and get the passenger's paramaters.

#include "Passenger.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Passenger::Passenger()
{
	lastName = "";
	firstName = "";
	address = "";
	phoneNumber = "";
}

// Constructor that takes a name, address, and phone number as paramaters and stores them
Passenger::Passenger(string _firstName, string _lastName, string _address, string _phoneNumber)
{
	firstName = _firstName;
	lastName = _lastName;
	address = _address;
	phoneNumber = _phoneNumber;
}

// Sets the last name for the passenger
void Passenger::setLastName(string _lastName)
{
	lastName = _lastName;
}

// Sets the first name for the passenger
void Passenger::setFirstName(string _firstName)
{
	firstName = _firstName;
}

// Sets the address for the passenger
void Passenger::setAddress(string _address)
{
	address = _address;
}

// Sets the phone number for the passenger
void Passenger::setPhoneNumber(string _phoneNumber)
{
	phoneNumber = _phoneNumber;
}

// Returns the last name of the passenger
string Passenger::getLastName() 
{
	return lastName;
}

// Returns the first name of the passenger
string Passenger::getFirstName()
{
	return firstName;
}

// Returns the phone number of the passenger
string Passenger::getPhoneNumber()
{
	return phoneNumber;
}

// Returns the address of the passenger
string Passenger::getAddress()
{
	return address;
}

// Two passenger objects are the same if their first and last names are the same, regardless if the addresses or phone numbers
// are differrent
bool Passenger::operator==(Passenger c)
{
	if (lastName.compare(c.getLastName()) == 0 && firstName.compare(c.getFirstName()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Given two passengers, a and b, passenger a is less than passenger b if passenger a's last name comes alphabetically before
// passenger b's.  If both have the same last name, the first names will be compared.
bool Passenger::operator<(Passenger c)
{
	if (lastName.compare(c.getLastName()) <= 0)
	{
		if (lastName.compare(c.getLastName()) < 0)
		{
			return true;
		}
		else
		{
			if (firstName.compare(c.getFirstName()) < 0)
			{
				return true;
			}
		}
	}
	return false;
}

// Given two passengers, a and b, passenger a is greater than passenger b is a's last name comes alphabetically after passenger
// b's.  If both have the same last name, the first names will be compared as well.
bool Passenger::operator>(Passenger c)
{
	if (lastName.compare(c.getLastName()) >= 0)
	{
		if (lastName.compare(c.getLastName()) > 0)
		{
			return true;
		}
		else

			if (firstName.compare(c.getFirstName()) > 0)
			{
				return true;
			}
	}
	return false;
}

// Prints the passenger information
void printPassenger(Passenger &c)
{
	cout << c.firstName << " " << c.lastName << " " << "[" << c.address << "] " << "[" << c.phoneNumber << "]";
}

// Another way to print the passenger information
ostream& operator<< (ostream& os, Passenger &c) {
	
	cout << c.firstName << " " << c.lastName << " " << "[" << c.address << "] " << "[" << c.phoneNumber << "]";
	return os;
}