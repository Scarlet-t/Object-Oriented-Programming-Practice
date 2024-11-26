/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/03/27

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date: 2024/03/27
// Author: Jenny Zhang
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace seneca {
	// constructor receives a double holding the initial account balance and a double holding the interest rate to be applied to the balance. 
// If the interest rate received is positive-valued, this function stores the rate.
// If not, this function stores 0.0 as the rate to be applied.
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		m_interestRate = interestRate > 0 ? interestRate : 0;
	}

	//this modifier calculates the interest earned on the current balance and credits the account with that interest.
	void SavingsAccount::monthEnd() {
		double interest = balance() * m_interestRate;
		credit(interest);
	}

	// receives a reference to an ostream object and inserts the following output on separate lines to the object. 
	// The values marked in red are fixed format with 2 decimal places and no fixed field width:
	/*
	* Account type: Savings
	* Balance: $xxxx.xx
	* Interest Rate (%): x.xx
	*/
	void SavingsAccount::display(std::ostream& os) const {
		os <<
			"Account type: Savings\n" <<
			"Balance: $" << std::fixed << std::setprecision(2) << balance() << '\n' <<
			"Interest Rate (%): " << m_interestRate * 100 << '\n';
	}
}