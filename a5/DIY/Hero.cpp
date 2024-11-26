#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#include "Hero.h"

namespace seneca {
	Hero::Hero() {
		m_name[0] = '\0';
		m_powers = nullptr;
		m_numPower = 0;
		m_lvlPower = 0;
	}
	Hero::Hero(const char name[], Power* powers, int numPower) {
		strcpy(m_name, name);

		if (powers != nullptr) {
			m_powers = new Power[sizeof(Power) * numPower];
			for (int i = 0; i < numPower; i++) { m_powers[i] = powers[i]; }
		}
		m_numPower = numPower;
		calcPowerLvl();
	}
	Hero::~Hero() {
		if (m_powers != nullptr) {
			delete[] m_powers;
			m_powers = nullptr;
		}
	}

	//power level is The sum of the rarity of all the heroes' powers multiplied by the total count of powers.
	void Hero::calcPowerLvl() {
		if (m_powers == nullptr) {
			m_lvlPower = 0;
			return;
		}
		int totalRarity = 0;
		for (int i = 0; i < m_numPower; i++) { totalRarity += m_powers[i].checkRarity(); }
		m_lvlPower = totalRarity * m_numPower;
	}
	std::ostream& Hero::display(std::ostream& os) const {
		if (m_powers == nullptr) return os;
		os << "Name: " << m_name << std::endl;
		os << "List of available powers: \n";
		for (int i = 0; i < m_numPower; i++) {
			os << "  Name: " << m_powers[i].checkName() << ", Rarity: " << m_powers[i].checkRarity() << "\n";
		}
		os << "Power Level: " << m_lvlPower;
		return os;
	}
	//operators
 
	//overload the += operator that accepts a power reference. The power should be added to the dynamic list of powers of your hero. Your heroes' power level and power count should be updated too.
	Hero& Hero::operator+=(const Power& power) {
		if (power.isEmpty()) return *this;

		Power* powersOldTemp = nullptr;

		if (m_powers != nullptr) {
			powersOldTemp = new Power[sizeof(Power) * m_numPower];
			for (int i = 0; i < m_numPower; i++) { powersOldTemp[i] = m_powers[i]; }
			delete[] m_powers;
			m_powers = nullptr;
		}

		m_powers = new Power[sizeof(Power) * m_numPower++];
		m_powers[m_numPower - 1] = power;

		if (powersOldTemp != nullptr) {
			for (int i = 0; i < m_numPower - 1; i++) { m_powers[i] = powersOldTemp[i]; }
			delete[] powersOldTemp;
			powersOldTemp = nullptr;
		}
		calcPowerLvl();
		return *this;
	}

	// overload the -= operator that accepts an integer reference. This operator will decrease the power level of the hero by the integer value received.
	Hero& Hero::operator-=(int value) {
		m_lvlPower -= value;
		return *this;
	}

	//operator< : This operator takes two references to two hero parameters. It will return true if the first hero's power level is less than the second hero's power level. It will return false otherwise.
	bool operator<(const Hero& lhs, const Hero& rhs)
	{
		if (lhs.m_lvlPower < rhs.m_lvlPower) {
			return true;
		}
		return false;
	}

	// operator> : This operator takes two references to two hero parameters. It will return true if the first hero's power level is greater than the second hero's power level. It will return false otherwise.
	bool operator>(const Hero& lhs, const Hero& rhs) {
		return !(lhs < rhs);
	}

	//operator>> : This operator will take two parameters. The left parameter is a reference to a power. The right parameter is a reference to a hero. This operator will add power to the hero and update the hero accordingly.
	Hero& operator>>(const Power& lhs, Hero& rhs) {
		rhs += lhs;
		return rhs;
	}

	//operator<< : This operator will take two parameters. The left parameter is a reference to a hero. The right parameter is a reference to a power. This operator will add power to the hero and update the hero accordingly.
	Hero& operator<<(Hero& lhs, const Power& rhs) {
		lhs += rhs;
		return lhs;
	}

}