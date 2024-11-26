/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/03/31

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
//***********************************************************************
// OOP244 Project
//
// File  Utils.h
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Jenny Zhang  ||  Date: 2024/03/20  ||  Reason: Added functions countChar, firstNotNum, lastNotNum
// Name: Jenny Zhang  ||  Date: 2024/03/30  ||  Reason: Added overloaded function clearBuffer
//***********************************************************************
#ifndef SENECA_UTILS_H_
#define SENECA_UTILS_H_
#include <iostream>
namespace seneca {
   class Utils {
      /// <summary>
      /// Start point for the simulated time
      /// Set to 8 AM
      /// </summary>
      unsigned int m_testMins = 480;
      /// <summary>
      /// index for the time addition intervals ({ 3,5,9,20,30 });
      /// </summary>
      unsigned int m_testIndex = 0;
   public:
      /// <summary>
      /// Set the debug global variable to true and sets the m_testMins attribute to 
      ///  hour x 60 + min. This value will be the intial starting time for debugging
      ///  and testing. 
      /// </summary>
      /// <param name="hour">hours</param>
      /// <param name="min">minutes</param>
      void setDebugTime(int hour, int min);
      /// <summary>
      /// If not in debugging mode, returns the current minute value of the system hour
      ///  and minute. If debugging is active it will first return the value of m_testMins 
      ///  then adds the following values in these intervals (3,5,9,20,30) to simulate passage
      ///  of time. 
      /// </summary>
      /// <returns>the current time in minutes</returns>
      int getTime(); // returns the time of day in minutes

      /// <summary>
      /// compares s1 to s2
      /// </summary>
      /// <param name="s1">Cstring</param>
      /// <param name="s2">Cstring</param>
      /// <returns> &gt;0 if s1 &gt; s2  OR  &lt;0 if s1 &lt; s2 OR 0 if s1 = s2</returns>
      int strcmp(const char* s1, const char* s2)const;
   };

   // counts number of times char c appears in a string
   int countChar(const char c, const char* str);

   //returns index where first instance of non-digit is found
   int firstNotNum(std::string str);

   //returns index where last instance of non-digit is found
   int lastNotNum(std::string str);

   void clearBuffer(std::istream& in);

   void clearBuffer(std::istream& in, char end);

   /// <summary>
      /// making seneca::debug variable global to all the files
      /// which include "Utils.h"
      /// </summary>
   extern bool debug;
   /// <summary>
   /// making seneca::U "Utils" object global to all the files which include "Utils.h"
   /// </summary>
   extern Utils U;

}
#endif // !SENECA_UTILS_H_

