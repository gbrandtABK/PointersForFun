#pragma once
#include<iostream>

using std::cout;
using std::endl;

void ArraysAndPointers()
{
    cout << "*************** Arrays And Pointers ****************" << endl << endl;

    const int arrayLength = 5;
    int intArray[arrayLength]{ 1,2,3,4,5 };
    cout << "int intArray[arrayLength]{ 1,2,3,4,5 };" << endl;

    for (int i = 0; i < arrayLength; i++)
    {
        cout << intArray[i] << endl;;
    }
    cout << endl;

    // You can set a pointer to 0th element of an array and follow all the same rules as above.
    int* intPtr = intArray;
    cout << "int* intPtr = intArray;" << endl << endl;

    cout << "Indexing a pointer" << endl; 
    for (int i = 0; i < arrayLength; i++)
    {
        cout << intPtr[i] << endl;;
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

    cout << "Iterating a pointer pointing to array values" << endl;
    for (int i = 0; i < arrayLength + 1; i++, intPtr++)
    {
        cout << intPtr << ", " << *intPtr << endl;;
    }
    cout << endl;

    // *ptrArray = 6; <<<<<< Crash.

    // To delete a pointer that was allocated as an array, you call "delete[]". Since the pointer is out of bounds right now...
    // delete[] ptrArray; <<<< Crash

    // In order to delete we need to decrement the pointer back to starting position. 
    for (int i = 0; i < arrayLength + 1; i++, intPtr--) {}

    //delete[] ptrArray; <<<<<< Crash because you array was declared on the stack.
    intPtr = nullptr;

    cout << "Decrement pointer and set to nullPtr" << endl;
    cout << intPtr << endl << endl;
}