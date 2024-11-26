// Citation and Sources...
// Final Project Milestone 5
// Module: PreTriage
// Filename: PreTriage.h
// Version 1.0
// Author   Jenny Zhang
// Revision History
// -----------------------------------------------------------
// Date      2024/04/07
// 2024/04/05  Preliminary release
// 2024/04/05  Debugged DMA
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
#ifndef SENECA_PRE_TRIAGE_H_
#define SENECA_PRE_TRIAGE_H_
#define MAX_FILENAME 100

#include "Time.h"

namespace seneca {
	const int maxNumPatients = 100;

	//class Time;
	class Patient;

	class PreTriage {
		// Add two Time object attributes to the class to keep track of the average wait time for the Contaigen test and the Triage patients separately.
		Time m_avgWaitTimeCntg;
		Time m_avgWaitTimeTrg;

		// Create an array of pointers to Patient objects. The size of this array should be set to the maximum lineup value constant. These pointers should be nullptr when the PreTirage class is instantiated.
		// When Patients arrive, they will be dynamically instantiated and their addresses will be kept in the elements of this array. See register() method
		Patient* m_arrPatients[maxNumPatients];

		// A C-string to hold the path and name of the data file.
		char m_dataFilename[MAX_FILENAME];

		// Create an attribute to hold the actual number of patients in the lineup. 
		// This number can not exceed the maximum lineup value.
		int m_currentNumPatients;

		// METHODS:
		
		// Receives a constant Patient Reference and returns the total estimated wait time for that type of Patient (contagion or Triage) as follows:
		// Find the number of Patients in the lineup that match the type of the received Patient Reference.
		// Returns the product of estimated wait time(for that type of patient) to the number of patients found.
		// This method does not change the state of the class.
		int getWaitTime(const Patient& src) const;

		//Receives the reference of the admitting patient and adjusts the average wait time of that type of patient based on the admittance time of the patient.
		// Modify and set the value of the average wait time of the corresponding patient using the following formula :
		// CT: Current Time
		// PTT : Patient's Ticket Time
		// AWT : Average Wait Time(Contagion or Triage)
		// PTN : Patient's Ticket Number
		// AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
		void setAverageWaitTime(const Patient&);

		// Receives a character representing the type of patient (C for Contaigen, T for Triage).
		// Finds the index of the first patient in line that matches a specified type.
		// This function iterates over the lineup array of pointers from the beginning.
		// For each patient, it compares the patient's type with the specified type (using overloaded operator==). 
		// If a match is found, the function returns the found index. 
		// If the function iterates over the entire lineup without finding a match, it returns -1
		int indexOfFirstInLine(char type);

		// Loads the average wait times and the patient records from the data file and stores them in the lineup array of pointers.
		// pseudocode in readme
		void load();

		/*
		Opens the data file for output.
		Inserts "Saving lineup...", into cout and goes to newline
		Inserts the average Contaigen Test and Triage wait times, comma-separated into the data file and goes to newline.
		Iterates through the lineup array of Patient pointers
		Inserts them into the data file and goes to newline
		Inserts the number of records saved for each type of patient into cout and goes to newline
		*/
		void save();

		// Registers a new patient:
		// check readme (register)
		void registerPatient();

		// Calls the next patient in line to be admitted to the contagion test centre or Triage centre
		// check readme
		void admit();

		// Prints a report on patients currently in the lineup
		// check readme
		void lineup();

	public:
		// A PreTriage class is instantiated using the data file name. 
		// This data file name is stored in the data filename attribute for load and save purposes. 
		// The constructor also initializes the two Time attributes, Contagion test and Triage, to 15 and 5 respectively.
		// These Time values may be overwritten by the corresponding values in the data file, if present. 
		// The constructor then loads all the data from the data file, if possible.
		PreTriage(const char* dataFilename);

		// Saves the data.
		// Iterates through the patient lineup and deletes the elements one by one.
		// If there are any other dynamically allocated memory, it will delete them as well.
		~PreTriage();

		//Runs the PreTriage main application.
		/*
		General Healthcare Facility Pre-Triage Application
		1- Register
		2- Admit
		3- View Lineup
		0- Exit
		>
		*/
		// get the user's selection.
		/*
		display the menu and get the selection
		if the selection is 0, quit the method
		if the selection is 1 call the register method
		if the selection is 2 call the admit method
		if the selection is 3 call the lineup method
		go back to 1
		*/
		void run();
	};
}

#endif