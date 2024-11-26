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
// File: iAccount.h
// Version 1.0
// Date: 2024/03/27
// Author: Jenny Zhang
// Description
// This file defines the iAccount interface
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>

namespace seneca {
	class iAccount {
	public:
		// destructor
		virtual ~iAccount() {};

		//adds a positive amount to the account balance
		virtual bool credit(double) = 0;

		// subtracts a positive amount from the account balance
		virtual bool debit(double) = 0;

		//applies month-end transactions to the account
		virtual void monthEnd() = 0;

		// inserts account information into an ostream object
		virtual void display(std::ostream&) const = 0;

	};
	iAccount* CreateAccount(const char*, double);
	
}
#endif