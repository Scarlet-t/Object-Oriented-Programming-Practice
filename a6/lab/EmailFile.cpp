/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include "EmailFile.h"

using namespace std;
namespace seneca
{
    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            if (m_email != nullptr) delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                if (m_name != nullptr) delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }


   // constructor
   EmailFile::EmailFile(){
       m_filename = nullptr;
       m_emailLines = nullptr;
       m_noOfEmails = 0;
   }

   // filename constructor
   EmailFile::EmailFile(const char* filename) {

       if (filename != nullptr) {
           setFilename(filename);
           setNoOfEmails();
           loadEmails();
       }
       else {
           m_filename = nullptr;
           m_emailLines = nullptr;
           m_noOfEmails = 0;
       }
   }

   //copy constructor
   EmailFile::EmailFile(const EmailFile& source) {
       *this=source;
   }

   // destructor 
   EmailFile::~EmailFile() {
       this->setEmpty();
   }

   // copy from source
   void EmailFile::copyFrom(const EmailFile& source) {
       if (source.m_emailLines != nullptr) {
           setEmpty();
           m_emailLines = new Email[source.m_noOfEmails];
           for (int i = 0; i < source.m_noOfEmails; i++) {
               m_emailLines[i]=source.m_emailLines[i];
           }
           m_filename = new char[strlen(source.m_filename) + 1];
           strcpy(m_filename, source.m_filename);
           m_noOfEmails = source.m_noOfEmails;
       }
   }

   // copy assignment operator
   EmailFile& EmailFile::operator=(const EmailFile& rhs) {
       if (this != &rhs) {
           this->copyFrom(rhs);
       }
       return *this;
   }

    void EmailFile::setFilename(const char* filename)
    {
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }

        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        if (m_emailLines != nullptr) {
            for (int i = 0; i < m_noOfEmails; i++) {
                if (m_emailLines[i].m_email != nullptr) {
                    delete[] m_emailLines[i].m_email;
                    m_emailLines[i].m_email = nullptr;
                }
                if (m_emailLines[i].m_name != nullptr) {
                    delete[] m_emailLines[i].m_name;
                    m_emailLines[i].m_name = nullptr;
                }
                m_emailLines->m_year[0] = '\0';
            }
            delete[] m_emailLines;
            m_emailLines = nullptr;
        }
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            std::cout << "Failed to open file: " << m_filename << std::endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        file.close();
        return isValid;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                if (m_emailLines[i].m_email != nullptr && m_emailLines[i].m_name != nullptr) {
                    ostr.width(35);
                    ostr.setf(ios::left);
                    ostr << m_emailLines[i].m_email;
                    ostr.width(25);
                    ostr << m_emailLines[i].m_name;
                    ostr << "Year = " << m_emailLines[i].m_year << endl;
                }

            }
        }

            return ostr;
    }



    void EmailFile::loadEmails() {
        if (m_filename != nullptr) {
            if (m_emailLines != nullptr) { 
                for (int i = 0; i < m_noOfEmails; i++) {
                    if (m_emailLines[i].m_email != nullptr) delete[] m_emailLines[i].m_email;
                    if (m_emailLines[i].m_name != nullptr) delete[] m_emailLines[i].m_name;
                }
                delete[] m_emailLines; 
                m_emailLines = nullptr; 
            }
            m_emailLines = new Email[m_noOfEmails];
            std::ifstream f(m_filename);

            for (int i = 0; i < m_noOfEmails; i++) {
                Email temp;

                //load
                temp.load(f);

                m_emailLines[i] = temp;
            }
            f.close();
        }
    }

    EmailFile::operator bool()const {
        if (m_emailLines == nullptr && m_filename == nullptr && m_noOfEmails == 0) 
            return false;
        return true;
    }

    // save to file
    bool EmailFile::saveToFile(const char* filename) const {
        std::ofstream fout(filename);
        if (!fout.is_open()) {
            std::cout << "Error: Could not open file: " << filename << "\n";
            return false;
        }
        for (int i = 0; i < m_noOfEmails; i++) {
            if (m_emailLines[i].m_email != nullptr && m_emailLines[i].m_name != nullptr)
            {
                fout << this->m_emailLines[i].m_email << ',';
                fout << this->m_emailLines[i].m_name << ',';
                fout << this->m_emailLines[i].m_year << '\n';
            }
        }
        fout.close();
        return true;

    }

    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        if (!(bool(*this)) || !(bool(obj))) return;
        int total = this->m_noOfEmails + obj.m_noOfEmails;

        Email* newEmailLines = new Email[total];

        for (int i = 0; i < m_noOfEmails; i++) {
            newEmailLines[i] = m_emailLines[i];
        }

        for (int i = 0; i < obj.m_noOfEmails; i++) {
            newEmailLines[m_noOfEmails + i] = obj.m_emailLines[i];
        }


        if (m_emailLines != nullptr) {
            for (int i = 0; i < m_noOfEmails; i++) {
                if (m_emailLines[i].m_email != nullptr) delete[] m_emailLines[i].m_email;
                if (m_emailLines[i].m_name != nullptr) delete[] m_emailLines[i].m_name;
            }
            delete[] m_emailLines;
            m_emailLines = nullptr;
        }
        m_emailLines = newEmailLines;

        if (name != nullptr) {
            delete[] m_filename;
            m_filename = new char[strlen(name) + 1];
            strcpy(m_filename, name);
        }

        m_noOfEmails = total;
        saveToFile(m_filename);
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

}
