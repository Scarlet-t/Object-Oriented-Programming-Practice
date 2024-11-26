/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/11

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
namespace seneca {
	class IceCream;
	class Vendor {
		int numIceCream = 0;
		IceCream* icecream = nullptr;
		double subtotal = 0;
		double tax = 0;
		double total = 0;
	public:
		Vendor();
		void setEmpty();
		void takeOrders();
		void displayOrders();
		void clearData();
	};
}
#endif