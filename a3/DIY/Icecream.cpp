/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/11

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include "Icecream.h"
#define SCOOP_PRICE 5
#define CHOC_EXTRA 1

namespace seneca {
	IceCream::IceCream() {
		flavour = 0;
		numScoops = 0;
		cone = false;
		total = 0;
		scoopsPrice = 0;
		waferPrice = 0;
		miscPrice = 0;
	}
	void IceCream::getOrder() {
		std::cout <<
			"Select flavour:\n" <<
			"----------------\n" <<
			"1: Chocolate\n" <<
			"2: Strawberry\n" <<
			"3: Mango\n" <<
			"4: Tutti fruit\n" <<
			"5: Almond crunch\n" <<
			"----------------\n" <<
			"> ";

		flavour = getIntRange(1, 5);

		std::cout << 
			"Number of Scoops (max 3)\n" <<
			"> ";
		numScoops = getIntRange(1, 3);
		// CONE?
		std::cout <<
			"Vanilla wafer cone?\n" <<
			"(Y)es/(N)o > ";
		cone = getyn() == 'y';
		return;
	}

	void IceCream::printOrder() {
		//CALCULATIONS
		scoopsPrice = (SCOOP_PRICE * numScoops); // NUMBER OF SCOOPS
		total += scoopsPrice;
		waferPrice = (cone ? 5.00 : 0.00); // WAFER
		total += waferPrice;

		//PRINTING
		std::cout <<
			"Order details:                Price\n" <<
			"-----------------------------------\n";
		// NUMBER OF SCOOPS
		std::cout << std::left << std::setw(18)
			<< "Number of scoops, " << numScoops << " total:";
		std::cout << std::right << std::setw(9) << std::setprecision(2) << std::fixed << scoopsPrice << std::endl;

		// FLAVOR
		switch (flavour) {
		case 1:
			miscPrice = (CHOC_EXTRA * numScoops);
			total += miscPrice;
			std::cout << std::left << std::setw(30) << "Chocolate flavour:";
			std::cout << std::right << std::setw(5) << std::setprecision(2) << std::fixed <<
				miscPrice << std::endl;
			break;
		case 2:
			std::cout << "Strawberry flavour" << std::endl;
			break;
		case 3:
			std::cout << "Mango flavour" << std::endl;
			break;
		case 4:
			std::cout << "Tutti fruit flavour" << std::endl;
			break;
		case 5:
			std::cout << "Almond crunch flavour" << std::endl;
			break;
		}
		// WAFER
		std::cout << std::left << std::setw(30) << "Vanilla Wafer:";
		std::cout << std::right << std::setw(5) << std::setprecision(2) << std::fixed << waferPrice << std::endl;
		//PRICE
		std::cout << std::left << std::setw(30) << "Price:";
		std::cout << std::right << std::setw(5) << std::setprecision(2) << std::fixed << total << std::endl;
	}

	int getIntRange(int inf, int sup) {
		char temp = ' ';
		std::string str;
		int i = 0;
		do {
			std::getline(std::cin, str);
			if (!str.empty()) {
				temp = str[0];
				i = temp - '0';

				if (!std::isdigit(temp)) {
					std::cout << "Invalid entry, retry" << std::endl;
					std::cout << "> ";
				}
				else if (i < inf || i > sup) {
					std::cout << "Invlid value(" << inf << "<=val<=" << sup << ")" << std::endl;
					std::cout << "> ";
				}
			}
		} while (str.empty() || !std::isdigit(temp) || i < inf || i > sup);
		return i;
	}
	char getyn() {
		std::string str;
		char temp = ' ';
		do {
			std::getline(std::cin, str);
			if (!str.empty()) {
				temp = str[0];
				if (str.length() != 1 || strchr("YNyn", temp) == nullptr) {
					std::cout << "Only Y or N are acceptable:" << std::endl;
					std::cout << "> ";
				}
			}
		} while (str.empty() || str.length() != 1 || strchr("YNyn", temp) == nullptr);
		return tolower(temp);
	}
}

