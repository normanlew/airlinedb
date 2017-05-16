// Norman Lew
// CS 300
// Spring 2017

// Assignment 2

// This is the header file for the flight manager

#ifndef FLIGHTMANAGER_H_
#define FLIGHTMANAGER_H_
#include "Passenger.h"
#include "OrderedLinkList.h"
#include "LinkedList.h"
using namespace std;

// This is the FlightManager class.  It is invoked by the user to create a flight management class where they can add 
// passengers to individual flights.  They can also search, delete, and list the passenger manifesto details for individual flights.
class FlightManager
{
private:
	OrderedLinkList<Passenger> * flights;

public:
	FlightManager();

	// Add a passenger
	void addPassenger(int, Passenger);

	// Delete a passenger
	void deletePassenger(int, Passenger);

	// Search for a passenger
	Passenger * searchPassenger(int, Passenger);

	// List the passengers
	void listPassenger(int);
};


#endif

