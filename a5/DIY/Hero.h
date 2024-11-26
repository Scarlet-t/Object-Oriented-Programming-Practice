/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"

namespace seneca {
	const int MAX_NAME_LEN = 50;
	class Power;
	class Hero{
		char m_name[MAX_NAME_LEN];
		Power* m_powers;
		int m_numPower;
		int m_lvlPower;
	public:
		Hero();
		Hero(const char name[], Power* powers, int numPower);
		~Hero();
		//calculate power level
		void calcPowerLvl();
		std::ostream& display(std::ostream& os = std::cout) const;
		//operators
		// 
		//overload the += operator that accepts a power reference. The power should be added to the dynamic list of powers of your hero. Your heroes' power level and power count should be updated too.
		Hero& operator+=(const Power& power);

		// overload the -= operator that accepts an integer reference. This operator will decrease the power level of the hero by the integer value received.
		Hero& operator-=(int value);

		//operator< : This operator takes two references to two hero parameters. It will return true if the first hero's power level is less than the second hero's power level. It will return false otherwise.
		friend bool operator<(const Hero& lhs, const Hero& rhs);

		// operator> : This operator takes two references to two hero parameters. It will return true if the first hero's power level is greater than the second hero's power level. It will return false otherwise.
		friend bool operator>(const Hero& lhs, const Hero& rhs);

		//operator>> : This operator will take two parameters. The left parameter is a reference to a power. The right parameter is a reference to a hero. This operator will add power to the hero and update the hero accordingly.
		friend Hero& operator>>(const Power& lhs, Hero& rhs);

		//operator<< : This operator will take two parameters. The left parameter is a reference to a hero. The right parameter is a reference to a power. This operator will add power to the hero and update the hero accordingly.
		friend Hero& operator<<(Hero& lhs, const Power& rhs);

	};

}
#endif