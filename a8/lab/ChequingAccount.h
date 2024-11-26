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
// File: ChequingAccount.h
// Version 1.0
// Date: 2024/03/27
// Author: Jenny Zhang
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace seneca {
	class ChequingAccount : public Account {
		double m_transFee;
		double m_monthFee;
	public:
		// constructor receives a double holding the initial account balance, a double holding the transaction fee to be applied to the balance and a double holding the month-end fee to be applied to the account. 
		// If the transaction fee received is positive-valued, this function stores the fee. 
		// If not, this function stores 0.0 as the fee to be applied. 
		// If the monthly fee received is positive-valued, this function stores the fee. 
		// If not, this function stores 0.0 as the fee to be applied.
		ChequingAccount(double, double, double);

		// this modifier credits the balance by the amount received and if successful debits the transaction fee from the balance. 
		// This function returns true if the transaction succeeded; false otherwise.
		bool credit(double); 

		// this modifier debits the balance by the amount received and if successful debits the transaction fee from the balance. 
		// This function returns true if the transaction succeeded; false otherwise.
		bool debit(double);

		// this modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit.
		void monthEnd();

		// receives a reference to an ostream object and inserts the following output on separate lines to the object. 
		// The values marked in red are fixed format with 2 decimal places and no fixed field width:
		/*
		Account type: Chequing
		Balance: $xxxx.xx
		Per Transaction Fee: x.xx
		Monthly Fee: x.xx

		*/
		void display(std::ostream&) const;
	};


}
#endif