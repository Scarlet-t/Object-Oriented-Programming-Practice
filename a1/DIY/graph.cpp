/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/01/28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include "io.h"
using namespace std;

namespace seneca {
    // Maximum number of samples in an graph
    const int MAX_NO_OF_SAMPLES = 20;
    const int GRAPH_WIDTH = 65;
    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(28);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH. 
    int findMax(int samples[], int noOfSamples) {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }
    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }
    // prints a graph comparing the sample values visually 
    void printGraph(int samples[], int noOfSamples, const char* label) {
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH + 14, label);
        for (int i = 0; i < noOfSamples; i++) {
            string barLbl = std::to_string(noOfSamples * (noOfSamples - i));
            cout << left << setw(4) << barLbl;
            printBar(samples[i], max);
        }
        line(GRAPH_WIDTH + 14);
    }
}
