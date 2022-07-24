#pragma once
#include<iostream>

using std::cout;
using std::endl;

void PointersPointingToPointers()
{
    cout << "*************** Pointers Pointing To Pointers ****************" << endl << endl;

    // Pointers have an address in memory as well and can point to other points.
    // decalre an pointer to an int
    int* p = new int(1);

    // decalre a pointer to a pointer to an int.
    int** pp = &p;

    cout << p << ", " << *p << endl;
    cout << pp << ", " << *pp << ", " << **pp << endl << endl;
}