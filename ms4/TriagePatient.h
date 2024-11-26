// Citation and Sources...
// Final Project Milestone 4
// Module: TriagePatient
// Filename: TriagePatient.h
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

#ifndef SENECA_TRIAGE_PATIENT_H_
#define SENECA_TRIAGE_PATIENT_H_
#include "IOAble.h"
#include "Patient.h"

namespace seneca {
	extern int nextTriageTicket;
	class TriagePatient : public Patient {
		// character pointer member variable to dynamically hold the symptoms of the arriving patient for the triage center.
		char* m_symptoms;
	public:
		// The default constructor initializes the character pointer member variable to null, 
		// passes the nextTriageTicket global variable to the constructor of the base class Patient, 
		// and then increases the value of nextTriageTicket by one.
		TriagePatient();

		~TriagePatient();

		// This function returns the character 'T';
		virtual char type() const;


		//refer to readme
		std::ostream& write(std::ostream& out) const;

		//refer to readme
		std::istream& read(std::istream& in);
	};

}

#endif