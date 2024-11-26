/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/02

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Room.h"
#include "Guest.h"

namespace seneca {

	// sets the Room by allocating a dynamic array of guests and setting the room number 
	// (no validation is done for room number)
	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		strcpy(room.m_roomNumber, roomNumber);
		room.m_noOfGuests = numberOfGuests;
		room.m_guests = new Guest[numberOfGuests];
		for (int i = 0; i < numberOfGuests; i++) {
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
		}
		return;
	}

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room) {
		if (room.m_noOfGuests < 1 || room.m_guests == nullptr) {
			std::cout << "Empty Room!" << std::endl;
			return;
		}
		std::cout << "Room Number: " << room.m_roomNumber << std::endl;
		for (int i = 0; i < room.m_noOfGuests; i++) {
			std::cout << "    ";
			print(room.m_guests[i]);
		}
		return;
	}

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room) {
		char nRoom[7];
		int nGuest;
		std::cout << "Room number: ";
		std::cin >> nRoom;
		nRoom[6] = '\0';
		std::cout << "Number of guests: ";
		std::cin >> nGuest;
		set(room, nGuest, nRoom);
		for (int i = 0; i < room.m_noOfGuests; i++) {
			std::cout << i + 1 << ":" << std::endl;
			book(room.m_guests[i]);
		}
		return;
	}

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room) {
		if (room.m_guests == nullptr) {
			std::cout << "Empty Room!" << std::endl;
			return;
		}
		for (int i = 0; i < room.m_noOfGuests; i++) {
			vacate(room.m_guests[i]);
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;
		room.m_noOfGuests = 0;
		return;
	}
}