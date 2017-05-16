// Norman Lew
// CS 300
// Spring 2017

// Assignment 2

// This is the implementation file for the flight manager

#include "FlightManager.h"

FlightManager::FlightManager()
{
	flights = new OrderedLinkList<Passenger>[4];
}

// Add a passenger
void FlightManager::addPassenger(int flightNumber, Passenger c)
{
	switch (flightNumber)
	{
	case 100:
		flights[0].insert(c);
		break;

	case 200:
		flights[1].insert(c);
		break;
		
	case 300:
		flights[2].insert(c);
		break;

	case 400:
		flights[3].insert(c);
		break;
	}
}

// Delete a passenger
void FlightManager::deletePassenger(int flightNumber, Passenger c)
{
	switch (flightNumber)
	{
	case 100:
		flights[0].delete_node(c);
		break;

	case 200:
		flights[1].delete_node(c);
		break;

	case 300:
		flights[2].delete_node(c);
		break;

	case 400:
		flights[3].delete_node(c);
		break;
	}
}

// Search for a passenger
Passenger*  FlightManager::searchPassenger(int flightNumber, Passenger c)
{
	switch (flightNumber)
	{
	case 100:
		return flights[0].search(c);
		break;

	case 200:
		return flights[1].search(c);
		break;

	case 300:
		return flights[2].search(c);
		break;

	case 400:
		return flights[3].search(c);
		break;

	default:
		return NULL;
	}
}

// List passengers
void FlightManager::listPassenger(int flightNumber)
{
	switch (flightNumber)
	{
	case 100:
		return flights[0].print();
		break;

	case 200:
		return flights[1].print();
		break;

	case 300:
		return flights[2].print();
		break;

	case 400:
		return flights[3].print();
		break;
	}
}