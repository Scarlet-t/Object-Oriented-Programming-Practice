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
#include "Car.h"

namespace seneca {

	//Member function to check if the object is in a safe recognizable empty state. A car is considered empty if the either "make and model" or "service description" is either null or an empty cstring.
	bool Car::isEmpty() const {
		return (m_makeModel == nullptr || m_makeModel[0] == '\0') || (m_serviceDesc == nullptr || m_serviceDesc[0] == '\0');
	}

	// Member function sets the object a safe recognizable empty state. setEmpty accomplishes this by setting the attributes to empty cstring, nullptr and 0.0.
	void Car::setEmpty() {
		m_licencePlate[0] = '\0';
		strcpy(m_licencePlate, "");
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
		m_cost = 0.0;
		return;
	}

	//Member function to deallocate dynamically allocated memory for "make and model" and "service description" member variables.
	void Car::deallocateMemory() {
		if (m_makeModel != nullptr) {
			delete[] m_makeModel;
		}
		if (m_serviceDesc != nullptr) {
			delete[] m_serviceDesc;
		}
		return;
	}
	//Member function to Set car information and service details as follows.

	//Deallocates existing memory and then sets it to a safe empty state.
	//If the incoming information is valid (license plate is not empty and "make and model" and "description" are not null and not empty. note: the cost is not validated)
	//	Copies the corresponding argument to the license plate attribute
	//	Allocates memory and copies the data for car make and model
	//	Allocates memory and copies the date for the service description
	//	Assigns the 'serviceCost' value to the corresponding argument value.
	void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
		deallocateMemory();
		setEmpty();
		if (plateNo != nullptr && plateNo[0] != '\0' && carMakeModel != nullptr && carMakeModel[0] != '\0' && serviceDesc != nullptr && serviceDesc[0] != '\0') {
			m_licencePlate[8] = '\0';
			strcpy(m_licencePlate, plateNo);
			m_makeModel = new char[strlen(carMakeModel) + 1];
			m_makeModel[strlen(carMakeModel)] = '\0';
			strcpy(m_makeModel, carMakeModel);
			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			m_serviceDesc[strlen(serviceDesc)] = '\0';
			strcpy(m_serviceDesc, serviceDesc);
			m_cost = serviceCost;
		}
		else {
			setEmpty();
		}
		return;
	}


	void Car::display() const {
		if (!isEmpty()) {
			std::cout << std::left << std::setw(15) << "License Plate:";
			std::cout << std::right << std::setw(20) << m_licencePlate << std::endl;
			std::cout << std::left << std::setw(15) << "Model:";
			std::cout << std::right << std::setw(20) << m_makeModel << std::endl;
			std::cout << std::left << std::setw(15) << "Service Name:";
			std::cout << std::right << std::setw(20) << m_serviceDesc << std::endl;
			std::cout << std::left << std::setw(15) << "Service Cost:";
			std::cout << std::right << std::setw(20) << std::fixed << std::setprecision(2) << m_cost << std::endl;
		}
		return;
	}

}