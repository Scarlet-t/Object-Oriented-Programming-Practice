//Name: Jenny Zhang
//Email: jzhang503@myseneca.ca
//ID: 142467232
//Date of Completion: 2024/03/22

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <limits>
#include "DepositUtility.h"
#include "BankAccount.h"
namespace seneca {

	// query method to return the current balance of the account (m_balance)
	double BankAccount::getBalance() const {
		return m_balance;
	}

	// mutator that sets the current balance of the account (m_balance).
	void BankAccount::setBalance(double balance) {
		m_balance = balance;
	}

	//utility method that inserts into out a formatted dollar amount. The amount is written with a leading '$' sign and a precision of 2. 
	// For example, if amount is 1.2, $1.20 is written to out.
	void BankAccount::writeCurrency(std::ostream& out, double amount) const {
		out << "$" << std::fixed << std::setprecision(2) << amount;
	}

	// constructor that updates all of the data members of the object. 
	// Assume all data is valid.
	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) {
		strcpy(m_name, name);
		m_openDate = openDate;
		m_depInfo = depInfo; 
		m_balance = balance; 
	}

	// A query that inserts into out the content of the object as formatted below. 
		// >> [Name] | [Balance] | [Date Opened] | [Deposit Info]
	// The method will use writeCurrency() to output the account balance.
	std::ostream& BankAccount::write(std::ostream& out) const{
		out << ">> ";
		out << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | " << m_openDate << " | " << m_depInfo;
		return out;
	}

	//A mutator that reads from the stream in the data for the current object.
	std::istream& BankAccount::read(std::istream& in) {
		/*
		Name: [USER TYPES HERE]
		Opening Balance: [USER TYPES HERE]
		Date Opened (year month day): [USER TYPES HERE]
		Transit #: [USER TYPES HERE]
		Institution #: [USER TYPES HERE]
		Account #: [USER TYPES HERE]*/
		std::cout << "Name: ";
		in.getline(m_name, 50);

		std::cout << "Opening Balance: ";
		in >> m_balance;

		std::cout << "Date Opened ";
		m_openDate.read(in);

		m_depInfo.read(in);

		clearBuffer(in);

		return in;
	}

	// helper functions
	// Overload the extraction operator to extract a BankAccount from a stream. The extraction operator will call the read member function in the class BankAccount.
	std::istream& operator>>(std::istream& in, BankAccount& acct) {
		return acct.read(in);
	}

	//Overload the insertion operator to insert a BankAccount into a stream.The insertion operator will call the write member function in the class BankAccount.
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
		acct.write(out);
		return out;
	}

	void clearBuffer(std::istream& in) {
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
