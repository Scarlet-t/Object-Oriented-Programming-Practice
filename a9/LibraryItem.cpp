// Name: Jenny Zhang
// Email: jzhang503@myseneca.ca
// ID: 142467232
// Date of Completion: 2024/04/04

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "LibraryItem.h"

namespace seneca {
	//constructor should set the title pointer to null and year to 0.
	LibraryItem::LibraryItem() {
		m_title = nullptr;
		m_year = 0;
	}

	//constructor should take two parameters: title and year. 
	// It should allocate memory for the title string on the heap and make the title pointer point to the appropriate heap memory. 
	// Also, set the year to the provided year value.
	LibraryItem::LibraryItem(const char* title, int year) {
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		m_year = year;
	}

	// The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning LibraryItem objects.
	// copy constructor
	LibraryItem::LibraryItem(const LibraryItem& source) {
		m_title = nullptr;
		*this = source;
	}

	// copy assignment operator
	LibraryItem& LibraryItem::operator=(const LibraryItem& rhs) {
		if (this != &rhs && rhs.m_title != nullptr) {
			if (m_title != nullptr) {
				delete[] m_title;
				m_title = nullptr;
			}
			m_title = new char[strlen(rhs.m_title) + 1];
			strcpy(m_title, rhs.m_title);
			m_year = rhs.m_year;
		}
		return *this;
	}

	// destructor
	LibraryItem::~LibraryItem() {
		if (m_title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
		}
	}

	// This method should display the title and year of the library item as follows:
	// 
	// Title: The book Title (the year)<no new line>

	// For example :

	// Title: The Great Gatsby(1925) < no new line >
	std::ostream& LibraryItem::display(std::ostream& ostr) const {
		ostr << "Title: " << m_title << " (" << m_year << ')';
		return ostr;
	}
}