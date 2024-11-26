/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author   Jenny Zhang
Revision History
-----------------------------------------------------------
Date      2024/03/22
2023/03/20  Preliminary release
2024/03/22  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cmath>

#include "Utils.h"
#include "Time.h"

namespace seneca {
	//resets the Time object to the current time using the U.getTime() method, which is available in the Utils module. 
//It then returns a reference to the current object. 
	Time& Time::reset() {
		m_min = U.getTime();
		return *this;
	}

	// sets the number of minutes held in the object to the value provided in the min parameter.
	Time::Time(unsigned int min) {
		m_min = min;
	}

	// This method writes the time into ostream in the HH:MM format. 
	// If the hours or minutes are single-digit numbers, it pads them with a leading zero. 
	// For example, it formats the times as 03:02 , 16:55 , and 234:06
	std::ostream& Time::write(std::ostream& ostr) const {
		int hours, mins;
		hours = floor(m_min / 60);
		mins = m_min % 60;
		ostr <<
			std::setw(2) << std::setfill('0') << hours << ':' <<
			std::setw(2) << std::setfill('0') << mins;
		return ostr;
	}

	// Reads the integer for the hours using istream.
	// Check the next character and verifies if it is : and discards is.
	// If it is not, it sets the istream reference to a failure state by executing the method : istr.setstate(ios::failbit); .
	// Reads the integer for the minutes using istream.
	// Note: Do not clear or flush the istream as this method adheres to the istream standards.The caller of this function may checkthe istream state to ensure that the read operation was successful, if necessary.
	std::istream& Time::read(std::istream& istr) {
		int hours, mins;

		istr >> hours; // read hours

		// check for colon
		if (istr.peek() != ':') istr.setstate(std::ios::failbit);
		else istr.ignore();

		istr >> mins; // read mins

		// calc m_min
		if (istr) 
			m_min = (hours * 60) + mins; 

		return istr;

	}

	//This operator overloads the cast to unsigned int for the Time class. 
	// If a Time object is cast to an unsigned integer, it will return the number of minutes held in the object.
	Time::operator unsigned int()const {
		return m_min;
	}

	//This operator overloads the multiplication assignment *= for the Time class. 
	// It multiplies the number of minutes held in the Time object by val, then returns a reference to the current object.
	Time& Time::operator *= (int val) {
		m_min *= val;
		return *this;
	}

	//This operator overloads the subtraction assignment -= between the current Time object and the Time object D for the Time class. 
	// It calculates the time difference passed as an argument. 
	// Note that the difference can never be a negative value. If the result would be negative, it adds 24 hours (or 1440 minutes) toensure the result is positive.
	Time& Time::operator -= (const Time& D) {
		int diff = m_min - D.m_min;
		m_min =  diff > 0 ? diff : diff + 1440;
		return *this;
	}

	//This operator performs the same calculation as the subtraction assignment -= overload, except it has no side effect
	// It returns a new Time object representing the time difference between the current Time object and the Time object T.
	//assign the current object value to a temp tme object
	// substract - =
	//return temp obj
	Time Time::operator-(const Time& T)const {
		Time temp(m_min);
		temp -= T;
		return temp;
	}


	// Overload the insertion operator to be able to insert a Time object into an ostream reference as described in the write method.
	std::ostream& operator<<(std::ostream& os, const Time& time) {
		return time.write(os);
	}

	//Overload the extraction operator to be able to extract data from an istream reference into the Time object as described in theread method.
	std::istream& operator>>(std::istream& is, Time& time) {
		return time.read(is);
	}
}
