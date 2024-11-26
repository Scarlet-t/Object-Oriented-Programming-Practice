// Name: Jenny Zhang
// Email: jzhang503@myseneca.ca
// ID: 142467232
// Date of Completion: 2024/04/04

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "Book.h"

namespace seneca {
	// This constructor should take three parameters: title, year, and author. 
// It should allocate memory for the title and author strings on the heap and make the respective pointers point to the appropriate heap memory. 
// Also, set the year to the provided year value.
	Book::Book(const char title[], int year, const char author[]) : LibraryItem(title, year) {
		m_author = new char[strlen(author) + 1];
		strcpy(m_author, author);
	}

	// The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning Book objects.
	//copy constructor
	Book::Book(const Book& source) {
		m_author = nullptr;
		*this = source;
	}

	// copy assignment operator
	Book& Book::operator=(const Book& rhs) {
		if (this != &rhs && rhs.m_author != nullptr) {
			LibraryItem::operator=(rhs);

			if (m_author != nullptr) {
				delete[] m_author;
				m_author = nullptr;
			}

			m_author = new char[strlen(rhs.m_author) + 1];
			strcpy(m_author, rhs.m_author);
		}
		return *this;
	}

	// destructor
	Book::~Book() {
		if (m_author != nullptr) {
			delete[] m_author;
			m_author = nullptr;
		}
	}

	// This method should display the title, year, and author of the book as follows:
	// 
	//Title: The book Title (the year)<new line>
	//Author: The Author Name<no new line>

	//For example:

	//Title: The Great Gatsby (1925)<new line>
	//Author: F. Scott Fitzgerald<no new line>
	std::ostream& Book::display(std::ostream& ostr) const {
		LibraryItem::display(ostr);
		ostr << '\n' << "Author: " << m_author;
		return ostr;
	}

	//checks for non - null author names and checks to see if the object's author name is lexicographically greater than the other object's author name, it returns true; 
	// otherwise, it returns false.
	bool Book::operator>(const Book& other)const {
		return strcmp(m_author, other.m_author) > 0;
	}
}