/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "Utils.h"
#include "Menu.h"

namespace seneca {
	Menu::Menu() {
		m_menuCont = nullptr;
		m_numOptions = 0;
		m_numTabs = 0;
	}

	//This constructor is designed to initialize a Menu object. It takes two parameters: a pointer to a character string menuContent, and an optional integer numberOfTabs with a default value of 0.

	//The constructor dynamically allocates memory to store the content pointed to by menuContent in the member variable m_text.It then scans m_text to count the number of newline characters(\n), which is used to determine the number of options in the menu.

	//The numberOfTabs parameter specifies the number of indentation tabs to be applied when displaying the menu.This allows for flexible formatting of the menu display.If not provided, no tabs will be applied by default.
	Menu::Menu(const char* menuContent, int numberOfTabs) {
		if (menuContent == nullptr) {
			m_menuCont = nullptr;
			m_numOptions = 0;
		}
		else {
			m_menuCont = new char[strlen(menuContent) + 1];
			strcpy(const_cast<char*>(m_menuCont), menuContent);
			m_numOptions = countChar('\n', m_menuCont);
		}
		m_numTabs = numberOfTabs;
	}

	//Deallocates the dynamically allocated memory.
	Menu::~Menu() {
		if (m_menuCont != nullptr) {
			delete[] m_menuCont;
			m_menuCont = nullptr;
		}
	}

	//The display method is responsible for presenting the Menu content to the user.
	//(check readme for specs)
	void Menu::display() {
		std::string indent(m_numTabs * 3, ' ');
		std::stringstream menu(m_menuCont);
		std::string option;

		while (getline(menu, option)) {
			std::cout << indent << option << '\n'; //each option from menu, newline delim
		}

		std::cout <<
			indent << "0- Exit" << std::endl <<
			indent << "> ";

	}

	//first calls the display function and then receives the user's selection as an integer value. The integer reference selection argument is then set to this value and returned.
	//Make sure that the entered value is validated as an integer(with no trailing characters) and also the value should be between 0 and the number of options in the menu.
	// If the above conditions are not met, a proper error message should be displayed and re - entry requested(see below)
	int& Menu::operator>>(int& Selection) {
		std::string indent(m_numTabs * 3, ' ');
		bool hasInt = false;
		bool hasNonInt = false;
		bool validInput = false;
		display();

		while (!validInput) {
			hasInt = false;
			hasNonInt = false;
			std::string usrInput;
			std::getline(std::cin, usrInput);
			for (unsigned int i = 0; i < usrInput.length(); i++) {
				if (isdigit(usrInput[i])) hasInt = true;
				else if (usrInput[i] != '-') hasNonInt = true;
			}
			if (hasInt && !hasNonInt) {
				Selection = std::stoi(usrInput);
				if (Selection >= 0 && Selection <= m_numOptions) {
					validInput = true; // exit loop if valid input
				}

				else 
					std::cout << indent << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
			}
			else if (hasInt) {
				std::cout << indent << "Only enter an integer, try again: ";
			}
			else {
				std::cout << indent << "Bad integer value, try again: ";
			}
		}
		return Selection;

	}
}