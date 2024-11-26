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
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Jenny Zhang  ||  Date: 2024/03/20  ||  Reason: Added functions countChar, firstNotNum, lastNotNum
// Name: Jenny Zhang  ||  Date: 2024/03/30  ||  Reason: Added overloaded function clearBuffer
//***********************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
    int Utils::getTime() {
        int mins = -1;
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // end provided code

        // counts number of times char c appears in a string
    int countChar(const char c, const char* str) {
        int count = 0;
        if (str != nullptr) {
            for (unsigned int i = 0; i < strlen(str); i++) {
                if (str[i] == c) count++;
            }
        }
        return count;
    }

    //returns index where first instance of non-digit is found
    // if -1 then all digits / is number
    int firstNotNum(std::string str) {
        int index = -1;
        for (unsigned int i = 0; i < str.length() && index == -1; i++) {
            if (!isdigit(str[i])) {
                index = i;
            }
        }
        return index;
    }

    //returns index where first instance of non-digit is found
     // if -1 then all digits / is number
    //returns index where last instance of non-digit is found
    int lastNotNum(std::string str) {
        int index = -1;
        for (unsigned int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                index = i;
            }
        }
        return index;
    }

    void clearBuffer(std::istream& in) {
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void clearBuffer(std::istream& in, char end) {
        in.ignore(std::numeric_limits<std::streamsize>::max(), end);
    }
}