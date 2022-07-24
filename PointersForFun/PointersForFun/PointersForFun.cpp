#include <iostream>
#include "PointerBasics.h"
#include "PointersInScopeAndPointingToTheStack.h"
#include "PointersPointingToTheSameMemory.h"
#include "PointersPointingToPointers.h"
#include "PointersAsArrays.h"
#include "ArraysAndPointers.h"

using std::cout;
using std::endl;

int main()
{
    // Pointers are just another data type.
    // Just like an int is a container that holds data that our program interprets as an integer,
    // a pointer is a container that holds data that is that our program interprests as the address of what ever its pointing
    // as well as the type that its pointing to.

    // Pointers are useful for polymorphism, passing big objects by refernce and having control over the life cycle of an object and more.

    // When working with pointers its useful to know that a c++ program has 2 main spaces for memory, the stack and the heap.
    // The stack holds variables that are temporary and only usable within the scope they were defined in. 
    // The heap holds data that can be accessed anywhere in the program provided you have the address to it.
    // A pointer is a varaible declared on the stack that points to data allocated on the heap. 
    
    // When a variable goes out of scope, it is removed from the stack.
    // When a point (another variable) goes out of scope, it is removed from the stack, however the data it is point to remains on the heap.
    // If data is left on the heap and there are no pointers pointing to it, this is known as a memory leak. 
    // A memory leak is memory that cannot be reclaimed until the until the program ends. 
    // If enough memory leaks happen, your program will not be able to create any new data and will crash. 

    // See PointerBasics.h
    PointerBasics();
    cout << endl;

    // See PointersInScopeAndPointingToTheStack.h
    PoitnersInScopeAndPointingToTheStack();
    cout << endl;
    
    // See PointersPointingToTheSameMemory.h
    PointersPointingToTheSameMemory();
    cout << endl;
    
    // See PointersPointingToPointers/h
    PointersPointingToPointers();
    cout << endl;
    
    // See PointersAsArrays.h
    PointersAsArrays();
    cout << endl;

    // See ArraysAndPointers
    ArraysAndPointers();
    cout << endl;
}


