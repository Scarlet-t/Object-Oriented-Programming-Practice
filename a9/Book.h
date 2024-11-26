// Name: Jenny Zhang
// Email: jzhang503@myseneca.ca
// ID: 142467232
// Date of Completion: 2024/04/04

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "LibraryItem.h"

namespace seneca {
	class Book : public LibraryItem {
		char* m_author; // A pointer to store the name of the author of the book.

	public:
		// This constructor should take three parameters: title, year, and author. 
		// It should allocate memory for the title and author strings on the heap and make the respective pointers point to the appropriate heap memory. 
		// Also, set the year to the provided year value.
		Book(const char title[], int year, const char author[]);

		// The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning Book objects.
		//copy constructor
		Book(const Book& source);

		// copy assignment operator
		Book& operator=(const Book& rhs);

		// destructor
		~Book();

		// This method should display the title, year, and author of the book as follows:
		/*
		Title: The book Title (the year)<new line>
		Author: The Author Name<no new line>

		For example:

		Title: The Great Gatsby (1925)<new line>
		Author: F. Scott Fitzgerald<no new line>
		*/
		std::ostream& display(std::ostream& ostr = std::cout) const;

		//checks for non - null author names and checks to see if the object's author name is lexicographically greater than the other object's author name, it returns true; 
		// otherwise, it returns false.
		bool operator>(const Book& other)const;

	};
}

#endif