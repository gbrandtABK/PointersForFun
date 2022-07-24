#pragma once
#include<iostream>

using std::cout;
using std::endl;

void PointersAsArrays()
{
    cout << "*************** Pointers As Arrays ****************" << endl << endl;

    // Pointers are implicitly arrays and arrays are implictly pointers with some caveats (You can blame C for the problems that come with this)
    const int arrayLength = 5;
    int* ptrArray = new int[arrayLength];

    ptrArray[0] = 1;
    ptrArray[1] = 2;
    ptrArray[2] = 3;
    ptrArray[3] = 4;
    ptrArray[4] = 5;

    cout << "Allocating 5 contigious integers {1,2,3,4,5}" << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << ptrArray[i] << endl;;
    }
    cout << endl;

    // Pointers are subject to "Pointer arithimitic". 
    // The address a pointer points to is a hexidecimal representation of the number of a byte in memory.
    // When you add or subtract an integer, or use ++ or -- you add the number of bytes of the size of its data type.
    // Example for clarity. Say a pointer to an int is point to 00000000 and use ++. The pointer will now point to the 00000004 because an int is 4 bytes.
    // When you declare an array of size 5, the memory allocator will allocate enough bytes of contiguous memory for 5 integers and 
    // returns the address of the first integer.

    // However, there is nothing stopping you from incrementing your pointer outside of its allocated memory and your pointer is unaware of what memory exists.
    // When a pointer goes out of bounds, you can read the data but it will be garbage because that memory is likely not integer data.
    // If you try to delete or modify the data, the program wil crash.

    cout << "Iterating array using a pointer and pointer arithmitic" << endl;
    for (int i = 0; i < arrayLength + 1; i++, ptrArray++)
    {
        cout << ptrArray << ", " << *ptrArray << endl;;
    }
    cout << endl;

    // *ptrArray = 6; <<<<<< Crash.

    // To delete a pointer that was allocated as an array, you call "delete[]". Since the pointer is out of bounds right now...
    // delete[] ptrArray; <<<< Crash

    // In order to delete we need to decrement the pointer back to starting position. 
    for (int i = 0; i < arrayLength + 1; i++, ptrArray--) {}

    delete[] ptrArray;
    ptrArray = nullptr;

    cout << "Decrement, delete[], and set to nullPtr" << endl;
    cout << ptrArray << endl << endl;

    // You can still do pointer arithmitic on pointers that are not pointing to values stored in arrays and likewise cause it to point to garbage.
    int* intPtr = new int(1);
    cout << "int* intPtr = new int(1);" << endl;

    cout << "The address of our new int is " << intPtr << endl;
    cout << "The value of our new int is " << *intPtr << endl << endl;

    intPtr++;
    cout << "intPtr++" << endl << endl;;

    cout << "The address of our new int is " << intPtr << endl;
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // Clean up
    intPtr--;
    delete intPtr;
    intPtr = nullptr;
}