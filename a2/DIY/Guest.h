/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/02

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_GUEST_H 
#define SENECA_GUEST_H
namespace seneca {
	struct Guest {
	char* m_firstName;
	char* m_lastName;
	bool m_adult;
	};

	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age);
	
	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest);
	
	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest);
	
	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest);
}

#endif