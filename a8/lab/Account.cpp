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
// File: Account.cpp
// Version 1.0
// Date: 2024/03/27
// Author: Jenny Zhang
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include "Account.h"

namespace seneca {
	// constructor receives either a double holding the initial account balance or nothing. 
		// If the amount received is not positive-valued or no amount is received, this function initializes the current balance to 0.0. 
		// If the amount received is positive-valued, this function initializes the current account balance to the received amount.
	Account::Account(double balance) {
		m_balance = balance > 0 ? balance : 0;
	}

	//  receives an amount to be credited (added) to the account balance and returns the success of the transaction. 
	// If the amount received is positive-valued, the transaction succeeds and this function adds the amount received to the current balance. 
	// If the amount is not positive-valued, the transaction fails and this function does not add the amount received.
	bool Account::credit(double amount) {
		if (amount > 0) {
			m_balance += amount;
			return true;
		}
		return false;
	}


	// receives an amount to be debited(subtracted) from the account balance and returns the success of the transaction.
	// If the amount received is positive - valued, the transaction succeeds and this function subtracts the amount received from the current balance.
	// If the amount is not positive - valued, the transaction fails and this function does not subtract the amount received.
	bool Account::debit(double amount) {
		if (amount > 0) {
			m_balance -= amount;
			return true;
		}
		return false;
	}

	// returns the current balance of the account.
	double Account::balance() const {
		return m_balance;
	}

}
