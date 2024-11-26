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
#include "Icecream.h"
#include "Vendor.h"

namespace seneca {
	Vendor::Vendor() {
		std::cout <<
			"Seneca Icecream shop\n" <<
			"          @\n" <<
			"        (' .)\n" <<
			"       (*.`. )\n" <<
			"        \\###/\n" <<
			"         \\#/\n" <<
			"          V\n" <<
			"How many Icecreams?\n" <<
			"> ";
		std::cin >> numIceCream;
	}
	void Vendor::setEmpty () {
		icecream = new IceCream[numIceCream];
		subtotal = 0;
		tax = 0;
		total = 0;
	}
	void Vendor::takeOrders () {
		for (int i = 0; i < numIceCream; i++) {
			std::cout << "Order number " << i + 1 << ":" << std::endl;
			icecream[i].getOrder();
		}
	}
	void Vendor::displayOrders () {
		std::cout << "\n********** Order Summary **********" << std::endl;
		for (int i = 0; i < numIceCream; i++) {
			std::cout << "Order No: " << i + 1 << ":" << std::endl;
			icecream[i].printOrder();
			subtotal += icecream[i].total;
			if (i != numIceCream - 1) {
				std::cout << std::endl;
			}
		}
		tax = subtotal * 0.13;
		total = subtotal + tax;
		std::cout << "-----------------------------------\n";
		std::cout << std::left << std::setw(20) << "Price:"
			<< std::right << std::setw(15) << std::setprecision(2) << std::fixed << subtotal << std::endl;
		std::cout << std::left << std::setw(20) << "Tax:"
			<< std::right << std::setw(15) << std::setprecision(2) << std::fixed << tax << std::endl;
		std::cout << std::left << std::setw(20) << "Total Price ($):"
			<< std::right << std::setw(15) << std::setprecision(2) << std::fixed << total << std::endl;
	}
	void Vendor::clearData() {
		delete[] icecream;
		icecream = nullptr;
	}
}