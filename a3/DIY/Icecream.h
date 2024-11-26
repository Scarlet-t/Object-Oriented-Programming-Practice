/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/11

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H
namespace seneca {
	class IceCream {
		int flavour;
		int numScoops;
		bool cone;
		double scoopsPrice;
		double waferPrice;
		double miscPrice;
	public:
		IceCream();
		void getOrder();
		void printOrder();
		double total;
	};
	int getIntRange(int inf, int sup);
	char getyn();
}
#endif