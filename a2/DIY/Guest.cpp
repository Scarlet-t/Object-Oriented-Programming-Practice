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
#include "Guest.h"
#define MAX_NAME 50


namespace seneca {
	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age) {
		if (first == nullptr || !strcmp(first, "") || last == nullptr || !strcmp(last, "")) {
			guest.m_firstName = nullptr;
			guest.m_lastName = nullptr;
			guest.m_adult = true;
			return;
		}
		guest.m_firstName = new char[strlen(first) + 1];
		strcpy(guest.m_firstName, first);
		guest.m_lastName = new char[strlen(last) + 1];
		strcpy(guest.m_lastName, last);
		guest.m_adult = age >= 18;
		return;
	}

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest) {
		if (guest.m_firstName == nullptr || guest.m_lastName == nullptr) {
			std::cout << "Vacated!" << std::endl;
			return;
		}
		std::cout << guest.m_firstName << " " << guest.m_lastName << (guest.m_adult ? "" : "(Child)") << std::endl;
		return;
	}

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest) {
		char first[MAX_NAME];
		char last[MAX_NAME];
		int age;

		// input
		std::cout << "Name: ";
		std::cin >> first;
		std::cout << "Lastname: ";
		std::cin >> last;
		std::cout << "Age: ";
		std::cin >> age;

		first[strcspn(first, "\n")] = '\0';
		last[strcspn(last, "\n")] = '\0';

		//setting infos
		set(guest, first, last, age);
		return;
	}

	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest) {
		if (guest.m_firstName != nullptr) {
			delete[] guest.m_firstName;
			guest.m_firstName = nullptr;
		}
		if (guest.m_lastName != nullptr) {
			delete[] guest.m_lastName;
			guest.m_lastName = nullptr;
		}
		return;
	}
}

