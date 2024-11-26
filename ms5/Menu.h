/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author   Jenny Zhang
Revision History
-----------------------------------------------------------
Date      2024/03/22
2023/03/20  Preliminary release
2024/03/22  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

namespace seneca {
	class Menu {
		const char* m_menuCont;
		int m_numOptions;
		int m_numTabs;
	public:
		Menu();

		//This constructor is designed to initialize a Menu object. It takes two parameters: a pointer to a character string menuContent, and an optional integer numberOfTabs with a default value of 0.

		//The constructor dynamically allocates memory to store the content pointed to by menuContent in the member variable m_text.It then scans m_text to count the number of newline characters(\n), which is used to determine the number of options in the menu.

		//The numberOfTabs parameter specifies the number of indentation tabs to be applied when displaying the menu.This allows for flexible formatting of the menu display.If not provided, no tabs will be applied by default.
		Menu(const char* menuContent, int numberOfTabs = 0);

		//Deallocates the dynamically allocated memory.
		~Menu();

		//The display method is responsible for presenting the Menu content to the user.
		//(check readme for specs)
		void display();

		//first calls the display function and then receives the user's selection as an integer value. The integer reference selection argument is then set to this value and returned.
		//Make sure that the entered value is validated as an integer(with no trailing characters) and also the value should be between 0 and the number of options in the menu.
		// If the above conditions are not met, a proper error message should be displayed and re - entry requested(see below)
		int& operator>>(int& Selection);
	};
	
}

#endif