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
// File  Ticket.cpp
// Author  ??
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Jenny Zhang    Date: 2024.Mar.31    Reason: edit constructor
***********************************************************************/
#include <iostream>
#include "Ticket.h"
using namespace std;
namespace seneca {

   Ticket::Ticket(int number, int time) : m_time(time) {
       m_number = number;
   }
   Time Ticket::time() const
   {
      return m_time;
   }
   int Ticket::number() const {
      return m_number;
   }
   void Ticket::resetTime() {
      m_time.reset();
   }

   bool Ticket::operator=(Ticket& source) {
       if (source.m_number == m_number && source.m_time == m_time) return false;
       m_number = source.m_number;
       m_time = source.m_time;
       return true;
   }

   std::ostream& Ticket::write(std::ostream& ostr) const {
      if (&ostr != &cout) {
         ostr << m_number << "," << m_time;
      }
      else {
         ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
      }
      return  ostr;
   }
   std::istream& Ticket::read(std::istream& istr) {
      istr >> m_number;
      istr.ignore();
      return istr >> m_time;
   }
}
