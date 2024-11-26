/* Citation and Sources...
Final Project Milestone 1
Module: Patient
Filename: Patient.h
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
#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace seneca {
	class Patient : public IOAble {
		char* m_name;
		int m_ohip;
		// represents the patient’s ticket for the lineup
		// encapsulates all relevant information about the patient’s position in the queue, such as their arrival time and priority level.
		Ticket m_ticket; 
	public:
		// Instantiate a Patient object by providing a ticket number (an integer). 
		// This ticket number will be utilized to initialize the Ticket member attribute.
		Patient(int ticketNum = 0);
		Patient(const Patient& source);
		~Patient();

		// COPY ASSIGNMENT OPERATOR
		Patient& operator=(Patient& source);

		// pure virtual function called type that returns a character and is incapable of modifying the current object.
		// In future derived objects, this function will return a single character that identifies the type of the patient(Contagion test patient or Triage patient)
		virtual char type() const = 0;

		// Overload the operator== to compare the current object with a single character (the right operand). 
		// Return true if the values returned by the type function of this patient and the provided single character are identical. 
		// Note that this operator should not modify the current object.
		bool operator==(const char rhs) const;

		// Overload the operator== to compare the current object to another patient. 
		// Return true if the type of the current patient is the same as the type of the other patient; otherwise, return false. 
		// This operator should not have the ability to modify either the current object or the right operand.
		bool operator==(const Patient& rhs) const;

		// Implement a modifier method named setArrivalTime within the Patient class. 
		// This method sets the time of the patient's ticket to the current time. 
		// It does not take any parameters and does not return any value.
		void setArrivalTime();

		//Create a query method named time to retrieve the time of the patient's ticket and return it.
		Time time()const;

		//Establish a query method named number that returns the number associated with the patient's ticket.
		int number()const;

	//Cast Overloads
		//When a patient is casted to a boolean, return true if the Patient is in a valid state; otherwise, return false.
		operator bool();

		// If a patient is casted to a constant character pointer, return the address of the patient's name.
		operator const char* () const;

		// refer to Writing Patient Information into ostream on readme
		std::ostream& write(std::ostream& out) const;

		// refer to Reading Patient Information from istream on readme
		std::istream& read(std::istream& in);

	};
}

#endif