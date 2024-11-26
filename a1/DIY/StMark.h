/***********************************************************************
OOP244 Workshop # p2:
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/01/28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca {

    /// <summary>
    /// Record of a mark received by a student.
    /// </summary>
    struct StMark {
        char name[21];
        char surname[31];
        int mark;
    };

    void sort(StMark studentArray, int size);
    bool printReport(const char* filename);

}
#endif // !SENECA_STMARK_H


