/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/19

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())					
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);	
		m_monthlyTransactions = 0;	
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount::operator bool() const { return isOpen(); }
	bankAccount::operator double() const { return m_funds; }
	bankAccount& bankAccount::operator++() {
		if (m_funds <= 0) return *this;
		double interest = m_checking ? m_funds * 0.005 : m_funds * 0.025;
		m_funds += interest;
		return *this;
	}
	bankAccount& bankAccount::operator--() {
		if (!isOpen()) return *this;
		double fee = m_checking ? 1.25 : 3.50;
		m_funds -= fee * m_monthlyTransactions;
		return *this;
	}
	bool bankAccount::operator+= (double value) {
		if (!isOpen()) return false;
		m_funds += value;
		m_monthlyTransactions++;
		value >= 0 ? std::cout << "Deposit $" : std::cout << "Withdraw $";
		std::cout << std::fixed << std::setprecision(2) << abs(value) << " for " << m_userName << "\n";
		return true;
	}
	bool bankAccount::operator-= (double value) {
		if (!isOpen()) return false;
		double withdrawAmt = value * -1;
		return *this += withdrawAmt;
	}
	bool bankAccount::operator== (const bankAccount& acc) const {
		if (strcmp(acc.m_userName, m_userName) != 0) return false;
		if (m_funds != acc.m_funds) return false;
		if (m_checking != acc.m_checking) return false;
		return true;
	}
	bool bankAccount::operator> (double value) const {
		if (!isOpen()) return false;
		return m_funds > value;
	}
	bool bankAccount::operator<= (double value) const {
		if (!isOpen()) return false;
		return !(m_funds > value);
	}

	bool bankAccount::operator<<(bankAccount& acc) {
		if (!isOpen() || !acc.isOpen() || acc.m_funds <= 0) return false;
		cout << "Transfer $" << acc.m_funds << std::setprecision(2) << " from " << acc.m_userName << " to " << m_userName << "\n";
		*this += acc.m_funds;
		acc -= acc.m_funds;
		return true;
	}

	void bankAccount::display(void) const {
		if (isOpen()) {
			std::cout <<
				"Display Account -> User:" <<
				std::setw(16) << std::setfill('-') << std::right << m_userName <<
				" | " <<
				(m_checking ? "Checking" : " Savings") <<
				" | Balance: $" <<
				std::fixed << std::setprecision(2) << std::setw(8) << std::setfill(' ') << std::right << m_funds <<
				" | Transactions:" <<
				std::setw(3) << std::setfill('0') << std::right << m_monthlyTransactions <<
				"\n";
			return;
		}
		std::cout << "Display Account -> User:------- NOT OPEN\n";
	}

	// ADD: Global Helper Functions
	bool operator> (double lhs, const bankAccount& rhs) {
		if (!bool(rhs)) return false;
		return lhs > double(rhs);
	}
	bool operator<= (double lhs, const bankAccount& rhs) {
		return !(lhs > rhs);
	}
}
