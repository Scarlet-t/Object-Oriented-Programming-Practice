//Name: Jenny Zhang
//Email: jzhang503@myseneca.ca
//ID: 142467232
//Date of Completion: 2024/03/22

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BANK_ACCOUNT_H
#define SENECA_BANK_ACCOUNT_H

namespace seneca {
	// forward declaration
	class Date;
	class DepositInfo;

	class BankAccount {
		char m_name[50]; //The name of the person that owns the account
		Date m_openDate; // hold the date the account was opened
		DepositInfo m_depInfo; // hold the direct deposit information
		double m_balance; //hold the current balance of the account

	protected:
		// query method to return the current balance of the account (m_balance)
		double getBalance() const;

		// mutator that sets the current balance of the account (m_balance).
		void setBalance(double balance);

		//utility method that inserts into out a formatted dollar amount. The amount is written with a leading '$' sign and a precision of 2. 
		// For example, if amount is 1.2, $1.20 is written to out.
		void writeCurrency(std::ostream& out, double amount) const;

	public:
		// constructor that updates all of the data members of the object. 
		// Assume all data is valid.
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);

		// A query that inserts into out the content of the object as formatted below. 
			// >> [Name] | [Balance] | [Date Opened] | [Deposit Info]
		// The method will use writeCurrency() to output the account balance.
		std::ostream& write(std::ostream& out) const;

		//A mutator that reads from the stream in the data for the current object.
		/*
		Name: [USER TYPES HERE]
		Opening Balance: [USER TYPES HERE]
		Date Opened (year month day): [USER TYPES HERE]
		Transit #: [USER TYPES HERE]
		Institution #: [USER TYPES HERE]
		Account #: [USER TYPES HERE]
		*/
		std::istream& read(std::istream& in);

	};
	// helper functions
// 
	// Overload the extraction operator to extract a BankAccount from a stream. The extraction operator will call the read member function in the class BankAccount.
	std::istream& operator>>(std::istream& in, BankAccount& acct);

	//Overload the insertion operator to insert a BankAccount into a stream.The insertion operator will call the write member function in the class BankAccount.
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);

	void clearBuffer(std::istream& in);
}


#endif