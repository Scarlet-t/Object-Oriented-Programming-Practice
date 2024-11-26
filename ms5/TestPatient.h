// Citation and Sources...
// Final Project Milestone 4
// Module: TestPatient
// Filename: TestPatient.h
// Version 1.0
// Author   Jenny Zhang
// Revision History
// -----------------------------------------------------------
// Date      2024/04/05
// 2024/04/05  Preliminary release
// 2024/04/05  Debugged DMA
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#ifndef SENECA_TEST_PATIENT_H_
#define SENECA_TEST_PATIENT_H_
#include "IOAble.h"
#include "Patient.h"

namespace seneca {
	//This global variable will be used to determine what is the ticket number of the next contagion test Patient. 
	// Each time a new TestPatient object is created the value of the nextTestTicket will be increased by one. 
	// The scope of the global nextTestTicket variable is only the TestPatient module.
	extern int nextTestTicket;

	class TestPatient : public Patient {

	public:
		// The default constructor passes the nextTestTicket global variable to the constructor of the base class Patient and then it will increase the value of nextTestTicket global variable by one.
		TestPatient();

		// destructor
		~TestPatient() {};

		// This function only returns the character 'C';
		virtual char type() const;

		//if the ostream is cout it will insert "Contagion TEST" into the ostream object and goes to newline.
		// Then it will call the write() function of the base class Patient.
		// At end it will return the ostream reference.
		std::ostream& write(std::ostream& out) const;

		//It will call the read function of the base class Patient.
		// If the istream is not cin(reading from a file) then it should set the nextTestTicket to the ticket number of this patient + 1. This will make sure the ticket numbers are correctly restored with records are being read from a file.
		// Then it will return the istream reference
		std::istream& read(std::istream& in);

	};

}


#endif