/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/15

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {
   };

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

   //Initializes the current object to an empty state except for the model name which will be initialized by the value of the parameter. The parameter will also have a default value of "Stratocaster".
   Guitar::Guitar(const char* mod) {
       m_strings = nullptr;
       m_numStrings = 0;
       strcpy(m_model, mod);
   };

   // The three-argument constructor initializes the data members based on the provided parameters:
         // strs is an array of GuitarStr that will be used to populate the dynamic array.
         // ns is the size of the array argument(strs)
         // mod is a model name for the Guitar
   // If the parameters are not valid the current object is set to an empty state.
   Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
       m_strings = new GuitarStr[ns * sizeof(GuitarStr)];
       for (int i = 0; i < ns; i++) {
           m_strings[i] = strs[i];
       }
       strcpy(m_model, mod);
       m_numStrings = ns;
   };

   // The destructor deallocates any resources stored by the current object.
   Guitar::~Guitar() {
       if (m_strings != nullptr) {
           delete[] m_strings;
           m_strings = nullptr;
       }
   };

   // MODIFIERS

   //This function changes a GuitarStr on the Guitar by passing one in through the parameter gs. The sn parameter refers to the index in the array (m_strings) as to which GuitarStr is going to be changed. If the provided sn value is an invalid index for the array then no string change occurs.
   //This function returns true if a change occurred and false otherwise.
   bool Guitar::changeString(const GuitarStr& gs, int sn) {
       if (sn < 0 || sn >= m_numStrings || m_strings == nullptr) {
           return false;
       }
       m_strings[sn] = gs;
       return true;
   }

   // This function restrings the Guitar with a new set of GuitarStr provided through the parameters (an array of GuitarStr and an integer representing the size of that array). Take note to carefully manage any allocation/deallocation of dynamic memory when replacing the GuitarStr array.
   void Guitar::reString(GuitarStr strs[], int ns) {
       if (m_strings != nullptr) {
           delete[] m_strings;
           m_strings = nullptr;
       }
       m_numStrings = ns;
       m_strings = new GuitarStr[sizeof(GuitarStr) * ns];
       for (int i = 0; i < ns; i++) {
           m_strings[i] = strs[i];
       }
   }

   //This function will de-string the Guitar of all of its GuitarStr. This means to deallocate all resources currently held by the Guitar and to then set the m_numStrings to an empty state.
   void Guitar::deString() {
       if (m_strings != nullptr) {
           delete[] m_strings;
           m_strings = nullptr;
       }
       m_numStrings = 0;
       m_model[0] = '\0';
   }

   // QUERIES

   // This function will return true if the Guitar has GuitarStr and false otherwise.
   bool Guitar::strung() const {
       return m_strings != nullptr;
   }

   // This function will return true if any GuitarStr on the Guitar has a matching gauge value to the provided parameter and false otherwise.
   bool Guitar::matchGauge(double ga) const {
       for (int i = 0; i < m_numStrings; i++) {
           if (m_strings[i].gauge() == ga) {
               return true;
           }
       }
       return false;
   }

   // This function will display the details of a Guitar to the ostream via the parameter os.
   std::ostream& Guitar::display(std::ostream& os) const {
       if (m_numStrings == 0) {
           os << "***Empty Guitar***\n";
           return os;
       }
       os << "Guitar Model: " << m_model << std::endl;
       os << "Strings: " << m_numStrings << std::endl;
       if (m_strings == nullptr) {
           return os;
       }
       for (int i = 0; i < m_numStrings; i++) {
           os << "#" << i + 1 << std::setw(MAT_LEN) << std::right << m_strings[i].material() << std::setprecision(1) << " | " << m_strings[i].gauge() << std::endl;
       }
       return os;
   }
}
