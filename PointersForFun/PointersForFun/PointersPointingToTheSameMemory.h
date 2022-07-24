#pragma once
#include<iostream>

using std::cout;
using std::endl;

void PointersPointingToTheSameMemory()
{
    cout << "*************** Pointers Pointing To The Same Memory ****************" << endl << endl;

    // Pointers with the same addresses:

    // lets decare normal ints and play with these for a minute.
    int a = 1;
    int b = 2;
    cout << "int a = 1; int b = 2;" << endl;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl << endl;

    b = a;
    a = 3;
    cout << "b = a; a = 3" << endl;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl << endl;

    // Notice that regular variables can be copies of eachother but remain independent of each other.
    // Pointers, however when copied and have their data modifed, they both will have their data modifed. 

    int* ptr1 = new int(1);
    int* ptr2 = new int(2);
    cout << "int* ptr1 = new int(1); int* ptr2 = new int(2);" << endl;

    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;

    // Keep good habbits
    delete ptr2;

    ptr2 = ptr1;
    *ptr1 = 3;
    cout << "ptr2 = ptr1; *ptr1 = 3;" << endl;

    // ptr1 and ptr2 now point the same address and one pointer had its data modified. 
    // Since they point the same memeory address, they both dereference the same value.
    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;

    // This is cool and all but this can lead to problems of what part of the code is repsonsible for cleaning up the data?
    // Lets say the two pointers were in two totally separate parts of the program and one pointer got deleted.
    delete ptr1;
    cout << "delete ptr1;" << endl;

    cout << "ptr2 now poitnts to garbage -> " << *ptr2 << endl;

    // You can copy the values pointers are pointing to.
    ptr1 = new int(3);
    ptr2 = new int(4);
    cout << "ptr1 = new int(3); ptr2 = new int(4);" << endl;
    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;


    *ptr2 = *ptr1;
    cout << "*ptr2 = *ptr1;" << endl;
    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;

    *ptr1 = 5;
    cout << "*ptr1 = 5;" << endl;
    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;
}