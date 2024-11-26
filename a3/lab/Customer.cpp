/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/06

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Customer.h"
#include "Car.h"

//		int m_id;
//		char* m_name;
//		const Car* m_car;

namespace seneca {
	// This query method checks if the object is in a safe empty state. A customer is considered empty if the name pointer is null or empty cString or the car pointer is null.
	bool Customer::isEmpty() const {
		return (m_name == nullptr || m_name[0] == '\0') || m_car == nullptr;
	}
	// This method sets the customer to a safe empty state by setting the pointers to null and the id to 0.
	void Customer::setEmpty() {
		m_id = 0;
		m_name = nullptr;
		m_car = nullptr;
		return;
	}
	// This Member function deallocates the dynamically allocated memory for the m_name member variable.
	void Customer::deallocateMemory() {
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
		return;
	}
	// Deallocates existing memory and then sets it to a safe empty state.
	// If the incoming information is valid(i.e.the name is not null and not empty and the Car pointer is not null.The ID is not validated)
		// Copies the corresponding argument to the ID attribute
		// Allocates memory and copies the data for the name of the customer
		// Assigns the Car pointer attribute to the corresponding argument
	void Customer::set(int customerId, const char* name, const Car* car) {
		deallocateMemory();
		setEmpty();
		if (name != nullptr && name[0] != '\0' && car != nullptr) {
			m_id = customerId;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_car = car;
		}
		return;
	}

	// This function displays the Customer in the following format:
		//The labels of the data are left justified in 15 spaces.
		//The data of the attributes are right justified in 20 spaces.After the customer information is printed, the Car will be displayed.
	void Customer::display() const {
		std::cout << std::left << std::setw(15) << "Customer ID:";
		std::cout << std::right << std::setw(20) << m_id << std::endl;
		std::cout << std::left << std::setw(15) << "First Name:";
		std::cout << std::right << std::setw(20) << m_name << std::endl;
		(*m_car).display();
		return;
	}

	const Car& Customer::car()const {
		return *m_car;
	}
}