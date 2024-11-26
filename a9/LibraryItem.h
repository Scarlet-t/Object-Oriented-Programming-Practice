// Name: Jenny Zhang
// Email: jzhang503@myseneca.ca
// ID: 142467232
// Date of Completion: 2024/04/04

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_LIBRARY_ITEM_H
#define SENECA_LIBRARY_ITEM_H

namespace seneca {
	class LibraryItem {
		char* m_title; // A pointer to store the title of the item.
		int m_year; // An integer to store the publication year of the item.

	public:
		//constructor should set the title pointer to null and year to 0.
		LibraryItem();

		//constructor should take two parameters: title and year. 
		// It should allocate memory for the title string on the heap and make the title pointer point to the appropriate heap memory. 
		// Also, set the year to the provided year value.
		LibraryItem(const char* title, int year);

		// The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning LibraryItem objects.
		// copy constructor
		LibraryItem(const LibraryItem& source);

		// copy assignment operator
		LibraryItem& operator=(const LibraryItem& rhs);

		// destructor
		virtual ~LibraryItem();

		// This method should display the title and year of the library item as follows:
		// 
		// Title: The book Title (the year)<no new line>

		// For example :

		// Title: The Great Gatsby(1925) < no new line >
		virtual std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}

#endif