/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
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

#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_

namespace seneca {
	class Time {
	public:
		unsigned int m_min; // keep minutes

		// METHODS
			//resets the Time object to the current time using the U.getTime() method, which is available in the Utils module. 
			//It then returns a reference to the current object. 
		Time& reset();

		// sets the number of minutes held in the object to the value provided in the min parameter.
		Time(unsigned int min = 0u);

		// This method writes the time into ostream in the HH:MM format. 
		// If the hours or minutes are single-digit numbers, it pads them with a leading zero. 
		// For example, it formats the times as 03:02 , 16:55 , and 234:06
		std::ostream& write(std::ostream& ostr) const;

		// Reads the integer for the hours using istream.
		// Check the next character and verifies if it is : and discards is.
		// If it is not, it sets the istream reference to a failure state by executing the method : istr.setstate(ios::failbit); .
		// Reads the integer for the minutes using istream.
		// Note: Do not clear or flush the istream as this method adheres to the istream standards.The caller of this function may check the istream state to ensure that the read operation was successful, if necessary.
		std::istream& read(std::istream& istr);

		//This operator overloads the cast to unsigned int for the Time class. 
		// If a Time object is cast to an unsigned integer, it will return the number of minutes held in the object.
		operator unsigned int()const;

		//This operator overloads the multiplication assignment *= for the Time class. 
		// It multiplies the number of minutes held in the Time object by val, then returns a reference to the current object.
		Time& operator*= (int val);

		//This operator overloads the subtraction assignment -= between the current Time object and the Time object D for the Time class. 
		// It calculates the time difference passed as an argument. 
		// Note that the difference can never be a negative value. If the result would be negative, it adds 24 hours (or 1440 minutes) to ensure the result is positive.
		Time& operator-= (const Time& D);

		//This operator performs the same calculation as the subtraction assignment -= overload, except it has no side effect
		// It returns a new Time object representing the time difference between the current Time object and the Time object T.
		//assign the current object value to a temp tme object
		// substract - =
		//return temp obj
		Time operator-(const Time& T)const;


	};


	// Overload the insertion operator to be able to insert a Time object into an ostream reference as described in the write method.
	std::ostream& operator<<(std::ostream& os, const Time& time);

	//Overload the extraction operator to be able to extract data from an istream reference into the Time object as described in the read method.
	std::istream& operator>>(std::istream& is, Time& time);
}

#endif