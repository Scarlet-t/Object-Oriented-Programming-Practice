/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/02/12

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Fridge.h"
#include "Fridge.h"
using namespace std;

namespace seneca{

   const char* Food::name() const {
      return m_name;
   }
   int Food::weight() const {
      return m_weight;
   }
   Food::Food() {
       m_name[0] = { '\0' };
       m_weight = 0;
   }

   Food::Food(const char* nm, int wei) {
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }
   //The default constructor will initialize the data members to an empty state. The m_numFoods will be set to 0 and the m_model set to nullptr. The array of Food items will initialized by default from the provided Food struct code.
   Fridge::Fridge() {
       m_numFoods = 0;
       m_model = nullptr;
   }
   Fridge::Fridge(Food farr[], int nf, const char* mod) {
       m_numFoods = 0;
       if (nf > 0 && mod != nullptr && mod[0] != '\0') {
           m_numFoods = nf;
           m_model = new char[strlen(mod) + 1];
           strcpy(m_model, mod);
           for (int i = 0; i < nf; i++) {
               m_foods[i] = farr[i];
           }
       }
       else {
           m_model = nullptr;
       }

   }
   Fridge::~Fridge() {
       if (m_model != nullptr) {
           delete[] m_model;
           m_model = nullptr;
       }
   }
   //Modifiers

   //This function will attempt to add a Food item to the m_foods array. If the m_numFoods is less than the FRIDGE_CAP then assign the parameter Food item to the m_foods array at the index of m_numFoods. Increment the m_numFoods by 1 to reflect the added Food item.
   // 
   //This function returns true if we have successfully added a Food item and false otherwise.
   bool Fridge::addFood(const Food& f) {
       if (m_numFoods < FRIDGE_CAP) {
           m_foods[m_numFoods] = f;
           m_numFoods++;
           return true;
       }
       return false;
   }

   //This function will modify the model_name of the Fridge using the parameter provided if it is valid (ie not nullptr or the empty string).
   //If it is valid then first deallocate the memory of the m_model then allocate enough memory to store the provided value and copy it to m_model.
   void Fridge::changeModel(const char* m) {
       if (m == nullptr || m[0] == '\0') {
           return;
       }
       if (m_model != nullptr) {
           delete[] m_model;
           m_model = nullptr;
       }
       m_model = new char[strlen(m) + 1];
       strcpy(m_model, m);
   }
   //Queries
   // This function will return whether or not the Fridge is full. A Fridge is considered to be full if m_numFoods has reached FRIDGE_CAP.
   bool Fridge::fullFridge() const {
       return m_numFoods >= FRIDGE_CAP;
   }

   // This function will attempt to determine whether this Fridge holds a particular Food item by comparing its name to the parameter value. If a Food item is found with the same name then return true otherwise return false.
   bool Fridge::findFood(const char* f) const {
       for (int i = 0; i < m_numFoods; i++) {
           if (strncmp((m_foods[i]).name(), f, NAME_LEN) == 0) {
               return true;
           }
       }
       return false;
   }
   std::ostream& Fridge::display(std::ostream& os) const {
       if (m_model == nullptr || m_model[0] == '\0') {
           return os;
       }
       os << "Fridge Model: " << m_model << "\n";
       os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << "\n";
       os << "List of Foods\n";
       if (m_numFoods <= 0) {
           return os;
       }
       for (int i = 0; i < m_numFoods; i++) {
           os << std::setw(20) << m_foods[i].name() << " | " << m_foods[i].weight() << "\n";
       }
       return os;
   }
}
