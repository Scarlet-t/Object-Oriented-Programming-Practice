//Name: Jenny Zhang
//Email: jzhang503@myseneca.ca
//ID: 142467232
//Date of Completion: 2024/03/22

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "DepositUtility.h"
#include "BankAccount.h"
#include "SavingsAccount.h"

namespace seneca {
	// A query that inserts into out interest rate (m_interest) formatted so that the precision is 3 and a '%' sign follows. 
	// For example, if m_interest is 0.12, 0.120% is written to out.
	void SavingsAccount::writeInterest(std::ostream& out) const {
		out << std::fixed << std::setprecision(3) << m_interest << '%';
	}

	// A constructor that updates all data members of the object. 
	// It must call the constructor of the base class and pass the required data.
	//  Assume all data is valid.
	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance) {
		m_interest = interest;
		m_interestDate = interestDate;
	}

	// A mutator that increases the account balance by the amount of interest; 
	// updates the date interest was last applied; and outputs a message to cout. 
	// The method will use writeCurrency() to output the account balances and writeInterest() to output the interest rate.
	// There are three spaces at the front.
	//    [Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] | [Original Interest Date] => [New Interest Date]
	void SavingsAccount::applyInterest(Date& dt) {
		std::cout << "   $" << 
			std::fixed << std::setprecision(2) << getBalance() << " + $" << (m_interest * getBalance()) << " (";
		writeInterest(std::cout);
		std::cout << ") = ";
		double balance = getBalance() * (1 + m_interest);
		writeCurrency(std::cout, balance);
		std::cout << " | " << m_interestDate << " => " << dt << '\n';
		setBalance(balance);
		m_interestDate = dt;
	}

	// A query that inserts into out the content of the object as formatted below. 
	// The method must call the write() function of the base class. 
	// It will call writeInterest() to output the interest rate and the insertion operator to output the interest date.
	// >> [Name] | [Balance] | [Date Opened] | [Deposit Info] | [Interest Rate] | [Interest Date]
	std::ostream& SavingsAccount::write(std::ostream& out) const {
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | " << m_interestDate;
		return out;
	}

	// A mutator that reads from the stream in the data for the current object. 
	// It must call the read() function of the base class.

	std::istream& SavingsAccount::read(std::istream& in)  {
		BankAccount::read(in);
		std::cout << "Interest Date ";
		m_interestDate.read(in);
		std::cout << "Interest Rate: ";
		in >> m_interest;
		clearBuffer(in);
		return in;
	}


	// Overload the extraction operator to extract a SavingsAccount from a stream. 
	// The extraction operator will call the read member function in the class SavingsAccount. 
	std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
		return acct.read(in);
	}

	// Overload the insertion operator to insert a SavingsAccount into a stream. 
	// The insertion operator will call the write member function in the class SavingsAccount.
	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
		return acct.write(out);
	}
}