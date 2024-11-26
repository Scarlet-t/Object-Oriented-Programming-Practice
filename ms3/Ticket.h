/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/03/31

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
/***********************************************************************
// OOP244 Project ms3
//
// File  Ticket.h
// Author  ??
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Jenny Zhang    Date: 2024.Mar.31    Reason: edit constructor
***********************************************************************/
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
   class Ticket:public IOAble{
      Time m_time; // The time the Ticket was issued
      int m_number; //The ticket number; sequential integer, starting from one, unique
   public:

      Ticket(int number = 0, int time = 0u);

      //A query that returns the time when the ticket was issued.
      Time time()const;

      // A query returning the number of the ticket
      int number()const;

      // Sets the Ticket time to the current time.
      void resetTime();

      // copy assignment operator
      bool operator=(Ticket& source);

      //Inserts a ticket into the ostream to be displayed on the console 
      // or inserts comma-separated ticket number and time into ostream based on the ostream reference being cout or not.
      std::ostream& write(std::ostream& ostr )const;

      // Extracts the ticket number and time in a comma-separated format from istream.
      std::istream& read(std::istream& istr);
   };
}
#endif // !SENECA_TICKET_H_
