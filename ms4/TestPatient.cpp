/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.cpp
Version 1.0
Author   Jenny Zhang
Revision History
-----------------------------------------------------------
Date      2024/04/05
2024/04/05  Preliminary release
2024/04/05  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TestPatient.h"


namespace seneca {
	int nextTestTicket = 1;

	// The default constructor passes the nextTestTicket global variable to the constructor of the base class Patient and then it will increase the value of nextTestTicket global variable by one.
	TestPatient::TestPatient() : Patient(nextTestTicket++) {
	}

	// This function only returns the character 'C';
	char TestPatient::type() const {
		return 'C';
	}

	//if the ostream is cout it will insert "Contagion TEST" into the ostream object and goes to newline.
	// Then it will call the write() function of the base class Patient.
	// At end it will return the ostream reference.
	std::ostream& TestPatient::write(std::ostream& out) const {
		if (&out == &std::cout) out << "Contagion TEST\n";
		Patient::write(out);
		return out;
	}

	//It will call the read function of the base class Patient.
	// If the istream is not cin(reading from a file) then it should set the nextTestTicket to the ticket number of this patient + 1. This will make sure the ticket numbers are correctly restored with records are being read from a file.
	// Then it will return the istream reference
	std::istream& TestPatient::read(std::istream& in) {
		Patient::read(in);
		if (&in != &std::cin) nextTestTicket = Patient::number() + 1;
		return in;
	}
}
