/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
Version 1.0
Author   Jenny Zhang
Revision History
-----------------------------------------------------------
Date      2024/03/30
2023/03/20  Preliminary release
2024/03/22  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Utils.h"
#include "Ticket.h"
#include "Patient.h"

namespace seneca {


	// Instantiate a Patient object by providing a ticket number (an integer). 
// This ticket number will be utilized to initialize the Ticket member attribute.
	Patient::Patient(int ticketNum) : m_ticket(ticketNum) {
		m_name = nullptr;
		m_ohip = 0;
	}

	Patient::Patient(const Patient& source) : m_ticket(source.m_ticket.number(), source.m_ticket.time()) {
		m_name = new char[std::strlen(source.m_name) + 1];
		std::strcpy(m_name, source.m_name);
		m_ohip = source.m_ohip;
	}

	Patient::~Patient() {
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
	}

	// COPY ASSIGNMENT OPERATOR
	Patient& Patient::operator=(Patient& source) {
		if (this != &source) {
			// deallocate name
			if (m_name != nullptr) {
				delete[] m_name;
				m_name = nullptr;
			}

			// copy name
			m_name = new char[strlen(source.m_name) + 1];
			strcpy(m_name, source.m_name);

			// copy ohip
			m_ohip = source.m_ohip;

			// copy time
			m_ticket = source.m_ticket;
		}

		return *this;
	}

	// Overload the operator== to compare the current object with a single character (the right operand). 
	// Return true if the values returned by the type function of this patient and the provided single character are identical. 
	// Note that this operator should not modify the current object.
	bool Patient::operator==(const char rhs) const {
		return this->type() == rhs;
	}


	// *******
	// IMPORTANT
	// *******
	// Overload the operator== to compare the current object to another patient. 
	// Return true if the type of the current patient is the same as the type of the other patient; otherwise, return false. 
	// This operator should not have the ability to modify either the current object or the right operand.
	bool Patient::operator==(const Patient& rhs) const {
		bool sameName = strcmp(m_name, rhs.m_name) == 0;
		bool sameOhip = m_ohip == rhs.m_ohip;
		bool sameTicket = m_ticket.number() == rhs.m_ticket.number();
		bool sameTime = m_ticket.time() == rhs.m_ticket.time();
		bool final = sameName == true && sameOhip == true && sameTicket == true && sameTime == true;
		// *******
		// IMPORTANT
		// *******
		return !final; // CHANGE BACK FOR NEXT MILESTONE
	}

	// Implement a modifier method named setArrivalTime within the Patient class. 
	// This method sets the time of the patient's ticket to the current time. 
	// It does not take any parameters and does not return any value.
	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	//Create a query method named time to retrieve the time of the patient's ticket and return it.
	Time Patient::time()const {
		return m_ticket.time();
	}

	//Establish a query method named number that returns the number associated with the patient's ticket.
	int Patient::number()const {
		return m_ticket.number();
	}

	//Cast Overloads
		//When a patient is casted to a boolean, return true if the Patient is in a valid state; otherwise, return false.
	Patient::operator bool() {
		bool validName = m_name != nullptr && m_name[0] != '\0';
		bool validOHIP = m_ohip >= 100000000 && m_ohip <= 999999999; // Example range check

		return validName && validOHIP;
	}

	// If a patient is casted to a constant character pointer, return the address of the patient's name.
	Patient::operator const char* () const {
		return m_name;
	}

	// refer to Writing Patient Information into ostream on readme
	std::ostream& Patient::write(std::ostream& out) const {
		if (&out == &std::clog) {
			if (!*this) out << "Invalid Patient Record\n";
			else {
				out << std::left << std::setw(53) << std::setfill('.') << m_name;
				out << m_ohip;
				out << std::right << std::setw(5) << std::setfill(' ') << m_ticket.number() << ' ';
				m_ticket.time().write(out);
			}
		}
		else if (&out == &std::cout) {
			if (!*this) out << "Invalid Patient Record\n";
			else {
				out <<
					m_ticket << '\n' <<
					m_name <<
					", OHIP: " << m_ohip << '\n';
				return out;
			}
		}
		else {
			out << type() << ',' << m_name << ',' << m_ohip << ',' << m_ticket;
		}
		return out;
	}

	// refer to Reading Patient Information from istream on readme

	std::istream& Patient::read(std::istream& in) {
		bool isCin = &in == &std::cin;
		char nameTemp[51];
		int ohipTemp = 0;

		if (isCin) {
			//name
			std::cout << "Name: ";
			in.get(nameTemp, 51, '\n');
			clearBuffer(in);
			if (m_name != nullptr) {
				delete[] m_name;
				m_name = nullptr;
			}
			m_name = new char[strlen(nameTemp) + 1];
			strcpy(m_name, nameTemp);
			m_name[strlen(nameTemp)] = '\0';

			// ohip
			std::cout << "OHIP: ";
			while (ohipTemp < 100000000 || ohipTemp > 999999999) {
				if (!(in >> ohipTemp)) {
					in.clear();
					clearBuffer(in);
					std::cout << "Bad integer value, try again: ";
				}
				else if (ohipTemp < 100000000 || ohipTemp > 999999999) {
					std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				}
			}
			m_ohip = ohipTemp;
			in.ignore();
		}
		else {
			char nameTemp[51];

			if (in.get(nameTemp, 51, ',')) {
				clearBuffer(in, ',');

				if (m_name != nullptr) {
					delete[] m_name;
					m_name = nullptr;
				}
				m_name = new char[strlen(nameTemp) + 1];
				strcpy(m_name, nameTemp);
			}
			else if (in.eof()) {
				return in;
			}

			// ohip
			if (in >> m_ohip) {
				clearBuffer(in, ',');
			}
			else if (in.eof()) {
				return in;
			}

			m_ticket.read(in);
		}

		return in;
	}

}