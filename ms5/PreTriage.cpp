// Citation and Sources...
// Final Project Milestone 5
// Module: PreTriage
// Filename: PreTriage.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>


#include "PreTriage.h"
#include "Time.h"
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include "Utils.h"



namespace seneca {
	// A PreTriage class is instantiated using the data file name. 
	// This data file name is stored in the data filename attribute for load and save purposes. 
	// The constructor also initializes the two Time attributes, Contagion test and Triage, to 15 and 5 respectively.
	// These Time values may be overwritten by the corresponding values in the data file, if present. 
	// The constructor then loads all the data from the data file, if possible.
	PreTriage::PreTriage(const char* dataFilename) : m_avgWaitTimeCntg(15), m_avgWaitTimeTrg(5) {
		strcpy(m_dataFilename, dataFilename);
		m_currentNumPatients = 0;
		for (int i = 0; i < maxNumPatients; i++) {
			m_arrPatients[i] = nullptr;
		}
		load();
	}

	// Saves the data.
	// Iterates through the patient lineup and deletes the elements one by one.
	// If there are any other dynamically allocated memory, it will delete them as well.
	PreTriage::~PreTriage() {
		save();
		for (int i = 0; i < m_currentNumPatients; i++) {
			if (m_arrPatients[i] != nullptr) {
				delete m_arrPatients[i];
				m_arrPatients[i] = nullptr;
			}
		}
	}

	// Receives a constant Patient Reference and returns the total estimated wait time for that type of Patient (contagion or Triage) as follows:
	// Find the number of Patients in the lineup that match the type of the received Patient Reference.
	// Returns the product of estimated wait time(for that type of patient) to the number of patients found.
	// This method does not change the state of the class.
	int PreTriage::getWaitTime(const Patient& src) const {
		int numType = 0;
		char srcType = src.type();
		for (int i = 0; i < m_currentNumPatients; i++) {
			if (m_arrPatients[i]->type() == srcType) numType++;
		}
		int time = numType * (srcType == 'C' ? m_avgWaitTimeCntg.m_min : m_avgWaitTimeTrg.m_min);
		return time;
	}

	//Receives the reference of the admitting patient and adjusts the average wait time of that type of patient based on the admittance time of the patient.
	// Modify and set the value of the average wait time of the corresponding patient using the following formula :
	void PreTriage::setAverageWaitTime(const Patient& patient) {
		// CT: Current Time
		Time current;
		// PTT : Patient's Ticket Time
		double ptt = patient.time();
		// AWT : Average Wait Time(Contagion or Triage)
		int awt = patient.type() == 'C' ? m_avgWaitTimeCntg : m_avgWaitTimeTrg;
		// PTN : Patient's Ticket Number
		double ptn = patient.number();
		// AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
		current.reset();
		double temp = (((current.m_min - ptt) + (awt * (ptn - 1))) / ptn);
		awt = int(temp);
		
		if (patient.type() == 'C') m_avgWaitTimeCntg = awt;
		if (patient.type() == 'T') m_avgWaitTimeTrg = awt;
	}

	// Receives a character representing the type of patient (C for Contaigen, T for Triage).
	// Finds the index of the first patient in line that matches a specified type.
	// This function iterates over the lineup array of pointers from the beginning.
	// For each patient, it compares the patient's type with the specified type (using overloaded operator==). 
	// If a match is found, the function returns the found index. 
	// If the function iterates over the entire lineup without finding a match, it returns -1
	int PreTriage::indexOfFirstInLine(char type) {
		int index = -1;

		for (int i = 0; i < m_currentNumPatients && index == -1; i++) {
			if (m_arrPatients[i]->type() == type) index = i;
		}

		return index;
	}

	// Loads the average wait times and the patient records from the data file and stores them in the lineup array of pointers.
	// pseudocode in readme
	void PreTriage::load() {
		std::cout << "Loading data...\n";
		std::ifstream fin(m_dataFilename); //load file

		//read the contagion test average wait time from the data file
		if (!m_avgWaitTimeCntg.read(fin)) {
			std::cout << "No data or bad data file!" << "\n\n";
			return;
		}
		//ignore the comma
		fin.ignore(1, ',');
		//read the triage average wait time from the data file
		if (!m_avgWaitTimeTrg.read(fin)) {
			std::cout << "No data or bad data file!" << "\n\n";
			return;
		}
		//ignore the newline
		fin.ignore(1, '\n');

		char type = ' ';
		//In a loop from 0 to the maximum number of patients (or up to when reading fails)
		for (int i = 0; i < maxNumPatients && fin; i++) {
			if (fin >> type) {
				fin.ignore(1, ',');

				//Create a local patient-pointer
				Patient* patient = nullptr;
				//    if the character is 'C'
				if (type == 'C') patient = new TestPatient(); // instantiate
				//    otherwise, if the character is 'T'
				else if (type == 'T') patient = new TriagePatient(); // instantiate

				//    If Instantiation successful
				if (patient && patient->read(fin)) {
					//       Read the patient information from the file
					//       Add the local pointer value to the patient lineup array
					m_arrPatients[m_currentNumPatients++] = patient;
				}
				else {
					delete patient;
				}
			}

		//end loop
		}

		if (!fin.eof() && m_currentNumPatients == maxNumPatients) {
			std::cout << "Warning: number of records exceeded " << maxNumPatients << '\n';
		}
		if (m_currentNumPatients == 0 ) {
			std::cout << "No data or bad data file!" << '\n';
		}
		else {
			std::cout << m_currentNumPatients << " Records imported...\n";
		}
		std::cout << '\n';
	}

	//Opens the data file for output.
	//Inserts "Saving lineup...", into cout and goes to newline
	//Inserts the average Contaigen Test and Triage wait times, comma-separated into the data file and goes to newline.
	//Iterates through the lineup array of Patient pointers
	//Inserts them into the data file and goes to newline
	//Inserts the number of records saved for each type of patient into cout and goes to newline
	void PreTriage::save() {
		int numCtgn = 0, numTrg = 0;

		std::ofstream fout;
		fout.open(m_dataFilename);

		std::cout << "Saving lineup...\n";

		fout << m_avgWaitTimeCntg << ',';
		fout << m_avgWaitTimeTrg << '\n';

		for (int i = 0; i < m_currentNumPatients; i++) {
			if (m_arrPatients[i]->type() == 'C') numCtgn++;
			else if (m_arrPatients[i]->type() == 'T') numTrg++;
			fout << *m_arrPatients[i] << '\n';
		}

		std::cout << numCtgn << " Contagion Tests and " << numTrg << " Triage records were saved!\n";
	}

	// Registers a new patient:
	// check readme (register)
	void PreTriage::registerPatient() {
		Menu reg("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);

		//If the lineup size has reached the maximum number of patients, print "Line up full!", go to a new line and terminate the function
		if (m_currentNumPatients == maxNumPatients) {
			std::cout << "Line up full!\n";
			return;
		}

		//display the sub-menu and receive the selection
		int selection;
		reg >> selection;

		//if the selection is 1, in the next available lineup pointer instantiate a Contagion Test Patient
		if (selection == 1) m_arrPatients[m_currentNumPatients] = new TestPatient();
		//if the selection is 2, in the next available lineup pointer instantiate a Triage Patient
		if (selection == 2) m_arrPatients[m_currentNumPatients] = new TriagePatient();
		//if the selection is 0, terminate the function
		if (selection == 0) return;

		//set the patient's arrival time
		m_arrPatients[m_currentNumPatients]->setArrivalTime();

		//print: "Please enter patient information: "
		std::cout << "Please enter patient information: \n";

		//extract the patient from cin
		std::cin >> *m_arrPatients[m_currentNumPatients];

		//go to newline
		std::cout << '\n';
		
		//Print the ticket
		//	print: "******************************************"
		//	go to newline
		std::cout << "******************************************\n";
		//	insert the patient into cout
		std::cout << *m_arrPatients[m_currentNumPatients];
		//	print: "Estimated Wait Time: "
		std::cout << "Estimated Wait Time: ";
		//	print the return value of getWaitTime for the patient.
		//	go to newline
		int time = getWaitTime(*m_arrPatients[m_currentNumPatients]);
		Time waitTime(time);
		std::cout << waitTime << '\n';
		//	print: "******************************************"
		//	go to newline twice
		std::cout << "******************************************\n\n";
		//increase the lineup size.
		m_currentNumPatients++;

	}

	// Calls the next patient in line to be admitted to the contagion test centre or Triage centre
	// check readme
	void PreTriage::admit() {
		Menu adm("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);

		//display the sub-menu and receive the selection to determine the type of patient to admit.
		int selection;
		adm >> selection;

		char type;
		//if the selection is 1, the type is 'C'
		if (selection == 1) type = 'C';
		//if the selection is 2, the type is 'T'
		if (selection == 2) type = 'T';
		//if the selection is 0, terminate the function
		if (selection == 0) return;

		//find the index of the next patient in the line for the type (use indexOfFirstInLine method)
		int index = indexOfFirstInLine(type);

		//if no patient is found, print "Lineup is empty!\n" and terminate the function
		if (index == -1) {
			std::cout << "Lineup is empty!\n";
			return;
		}

		//go to newline
		//print: "******************************************"
		//go to newline
		std::cout << "\n******************************************\n";

		//print: "Call time [H:M]"
		//go to newline
		Time callTime;
		std::cout << "Call time: [" << callTime.reset() << "]\n";

			//print: "Calling for "
		std::cout << "Calling at for ";
		//insert the patient into cout
		std::cout << *m_arrPatients[index];
		//print: "******************************************"
		//go to newline twice
		std::cout << "******************************************\n\n";
		//set the average wait time for the patient (using setAverageWaitTime method)
		setAverageWaitTime(*m_arrPatients[index]);
		//remove the patient from the lineup using the removeDynamicElement function template.
		removeDynamicElement(m_arrPatients, index, m_currentNumPatients);
	}

	// Prints a report on patients currently in the lineup
	// check readme
	void PreTriage::lineup() {
		Menu line("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		int selection;
		line >> selection;

		if (selection == 0) return;
		char type = selection == 1 ? 'C' : 'T';

		std::cout << "Row - Patient name                                          OHIP     Tk #  Time\n"
				  << "-------------------------------------------------------------------------------\n";
		if (m_currentNumPatients == 0) std::cout << "Line up is empty!\n";
		else {
			int count = 1;
			for (int i = 0; i < m_currentNumPatients; i++) {
				if (m_arrPatients[i]->type() == type) {
					std::clog << std::setw(4) << std::setfill(' ') << std::left << count++ << "- " << *m_arrPatients[i] << '\n';
				}
			}
		}
		std::cout << "-------------------------------------------------------------------------------\n";
		
	}

	//Runs the PreTriage main application.
	//General Healthcare Facility Pre-Triage Application
	//1- Register
	//2- Admit
	//3- View Lineup
	//0- Exit
	//>
	// get the user's selection.
	//display the menu and get the selection
	//if the selection is 0, quit the method
	//if the selection is 1 call the register method
	//if the selection is 2 call the admit method
	//if the selection is 3 call the lineup method
	//go back to 1
	void PreTriage::run() {
		int selection;
		do {
			Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
			mainMenu >> selection;
			if (selection == 0) return;
			if (selection == 1) registerPatient();
			if (selection == 2) admit();
			if (selection == 3) lineup();
		} while (selection != 0);
	}
}