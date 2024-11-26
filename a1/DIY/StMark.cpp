/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/01/28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#include <cstdio>
#include <iostream>
#include <iomanip>
#include "StMark.h"
#include "io.h"
#include "graph.h"
#include "file.h"
namespace seneca {
	void sort(StMark studentArray[], int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (studentArray[j].mark < studentArray[j + 1].mark) {
					StMark temp = studentArray[j + 1];
					studentArray[j + 1] = studentArray[j];
					studentArray[j] = temp;
				}
			}
		}
		return;
	}

	bool printReport(const char* filename) {
		//declares
		int numMarks;
		StMark* marks = nullptr;
		marks = new StMark[MAX_NO_RECS]; //dynamic allocation
		if (!openFile(filename)) {
			return false;
		} // null return
		numMarks = readMarks(marks); //read marks into array and get numMarks
		closeFile(); // close file
		sort(marks, numMarks); // sort
		//actual marks
		int* numPerMark = nullptr;
		numPerMark = new int[10];
		int num = 0;
		int lastNum = 0;
		int id = 0;
		for (int i = 100; i > 10; i -= 10) {
			for (int j = lastNum; marks[j].mark <= i && marks[j].mark > (i - 10); j++) {
				num++;
			}
			// printf("%d %d\n", num, lastNum);
			numPerMark[id] = num - lastNum;
			lastNum = num;
			id++;
		}
		numPerMark[9] = numMarks - lastNum; //last range has lower bound inclusive
		printGraph(numPerMark, 10, "Students' mark distribution");
		for (int i = 0; i < numMarks; i++)
		{
			std::cout << std::left << std::setw(3) << i + 1;
			std::cout << ": " << "[";
			std::cout << std::left << std::setw(3) << marks[i].mark;
			std::cout << "] " << marks[i].name << " " << marks[i].surname << std::endl;
		}
		std::cout << "----------------------------------------" << std::endl;
		delete[] numPerMark;
		delete [] marks;
		numPerMark = nullptr;
		marks = nullptr;
		return true;
	}
}