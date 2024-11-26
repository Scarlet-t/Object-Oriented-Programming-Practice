// Citation and Sources...
// Final Project Milestone 4
// Module: TriagePatient
// Filename: TriagePatient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "TriagePatient.h"
#define MAX_SYMPTOM 512


namespace seneca {

	int nextTriageTicket = 1;
	// The default constructor initializes the character pointer member variable to null, 
	// passes the nextTriageTicket global variable to the constructor of the base class Patient, 
	// and then increases the value of nextTriageTicket by one.
	TriagePatient::TriagePatient() : Patient(nextTriageTicket++) {
		m_symptoms = nullptr;
	}

	TriagePatient::~TriagePatient() {
		if (m_symptoms != nullptr) {
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}
	}

	// This function returns the character 'T';
	char TriagePatient::type() const {
		return 'T';
	}


	//refer to readme
	std::ostream& TriagePatient::write(std::ostream& out) const {
		if (&out == &std::cout)
			out << "TRIAGE\n";

		Patient::write(out);

		if (&out == &std::cout)
			out << "Symptoms: " << m_symptoms << '\n';
		else if (&out != &std::clog) 
			out << ',' << m_symptoms;
		return out;
	}

	std::istream& TriagePatient::read(std::istream& in) {
		char symptoms[MAX_SYMPTOM];

		Patient::read(in);

		if (m_symptoms != nullptr) {
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}

		if (&in != &std::cin) {
			clearBuffer(in, ',');
		}
		else {
			std::cout << "Symptoms: ";
		}

		in.getline(symptoms, MAX_SYMPTOM, '\n');

		if (!in.fail()) {
			m_symptoms = new char[strlen(symptoms) + 1];
			strcpy(m_symptoms, symptoms);
		}

		if (&in != &std::cin) nextTriageTicket = Patient::number() + 1;

		return in;
	}
}