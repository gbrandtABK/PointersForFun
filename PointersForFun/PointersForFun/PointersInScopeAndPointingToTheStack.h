#pragma once
#include<iostream>

using std::cout;
using std::endl;

void PtrByReferenceAssignScopedVariable(int*& ptr)
{
    cout << "Setting pointer passed by reference to address of int declared on the stack within a scope" << endl;
    int scopedInt = 5;
    ptr = &scopedInt;

    cout << "The address of our new int in this scope is " << ptr << endl;
    cout << "The value of our new int in this scope is " << *ptr << endl << endl;
}

void PtrByValueAssignScopedVariable(int* ptr)
{
    cout << "Setting pointer passed by value to address of int declared on the stack within a scope" << endl;
    int scopedInt = 5;
    ptr = &scopedInt;

    cout << "The address of our copied pointer in this scope is " << ptr << endl;
    cout << "The value of our copied pointer in this scope is " << *ptr << endl << endl;
}

void PtrByReferenceAllocatedOnHeap(int*& ptr)
{
    cout << "Setting pointer passed by reference to new int(7)" << endl;
    ptr = new int(7);

    cout << "The address of our new int in this scope is " << ptr << endl;
    cout << "The value of our new int in this scope is " << *ptr << endl << endl;
}

void PtrByValueAssignAllocatedOnHeap(int* ptr)
{
    cout << "Setting pointer passed by value to new int(6)" << endl;
    ptr = new int(6);

    cout << "The address of our copied pointer in this scope is " << ptr << endl;
    cout << "The value of our copied pointer in this scope is " << *ptr << endl << endl;

    // memory leak.
}

void PoitnersInScopeAndPointingToTheStack()
{
    cout << "*************** Pointers In Scope And Pointing to the Stack ****************" << endl << endl;

    // INTO THE WEEDS

    int* intPtr;

    // You can assign a pointer to the address of a variable of the same type.

    // Declare variable on the stack.
    int stackInt = 4;

    cout << "The value of our stack int is " << stackInt << endl;

    // We can get the address of our variable using '&'. In this case, the address is on the stack. This has some implications that will get into.
    cout << "The address of our stack int is " << &stackInt << endl << endl;

    // Using the '&' we can assign the address of our stack into to a pointer.
    intPtr = &stackInt;

    cout << "The address of our new int is " << intPtr << endl;
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // Because c++ is intuitive and fun, the below line will crash the program.
    // delete intPtr;

    // You cannot delete memory that is allocated on the stack!

    // if we pass our pointer by value, it gets copied. Meaning a new pointer is declared on the stack and our original pointer is unaffected by the function.
    PtrByValueAssignScopedVariable(intPtr);

    cout << "The address of our new int is " << intPtr << endl;
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // If we let this function assign the address of a scoped varable to our pointer, it will point the garbage once the original variable goes out of scope.
    PtrByReferenceAssignScopedVariable(intPtr);

    cout << "The address of our new int is " << intPtr << endl;
    cout << "Our pointer is pointing to garbage now -> " << *intPtr << endl << endl;



    // if we pass our pointer by value, it gets copied. Meaning a new pointer is declared on the stack and our original pointer is unaffected by the function.
    // Since this function allocated memory on the heap but didn't clean it up, it caused a memory leak.
    PtrByValueAssignAllocatedOnHeap(intPtr);

    cout << "The address of our new int is " << intPtr << endl;
    cout << "Our pointer is still pointing to garbage now -> " << *intPtr << endl << endl;

    // If we let this function assign the address of a newly allocated object, we are now responsible for cleaning up that data.
    PtrByReferenceAllocatedOnHeap(intPtr);

    cout << "The address of our new int is " << intPtr << endl;
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // cleanup
    delete intPtr;
    intPtr = nullptr;
}