/*
Name: Jenny Zhang
Email: jzhang503@myseneca.ca
ID: 142467232
Date of Completion: 2024/04/09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_MATCH_PAIR_H
#define SDDS_MATCH_PAIR_H

namespace seneca {
    template <class T, class U>
    class Pair {
    public:
        T first;
        U second;
    };

    template<typename T, typename U>
    void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size) {
        Pair<T, U>* temp = new Pair<T, U>[size + 1];
        for (int k = 0; pArray && k < size; k++) {
            temp[k] = pArray[k];
        }
        temp[size].first = first;
        temp[size].second = second;
        delete[] pArray;
        pArray = temp;
        size++;
    }

    template <typename T, typename U>
    Pair<T, U>* matches(T arr1[], U arr2[], int size1, int size2, int& ref) {
        //First, creates a pointer called pt for pointing to an object of Pair type instantiated for the two type parameters; 
        // initializes pt to nullptr.This pointer is to be used for pointing to a dynamic memory space to hold an array of Pair type objects.
        Pair<T, U>* pt = nullptr;

        //Second, initializes the fifth reference parameter to zero.
        // This parameter is to keep track of the number of elements in the pt - pointed array.
        ref = 0;

        //Third, in its core logic, function iterates through all the elements of the first array arr1, 
        // and in each of these iterations it runs a nested loop to iterate, or sub - iterate, through all the elements of the second array arr2.
        // Each sub - iteration is to compare the current element of arr1 with the current element of arr2 for equality(using == operator).
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                //If the compared elements are equal, it calls addDynamicPairElement function to add the matched Pair as a new elemet to the pt dynamic array.

                if (arr1[i] == arr2[j]) addDynamicPairElement(pt, arr1[i], arr2[j], ref);
            }
        }


        //Finally, function matches returns the address of the first element of the new dynamic array; remember that its size is returned through the fifth function parameter.NOTE: The return type of matches is to be set to the type of the returned data.
        return pt;
    }

    template <typename T>
    void releaseMem (T* arrptr) {
        if (arrptr != nullptr) {
            delete[] arrptr;
            arrptr = nullptr;
        }
    }
}

#endif