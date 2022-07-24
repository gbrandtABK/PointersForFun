#pragma once
#include<iostream>

using std::cout;
using std::endl;

void PointerBasics()
{
    cout << "*************** Pointer Basics ****************" << endl << endl;

    // Pointer declared on the stack. Originally points to nothing.
    int* intPtr;

    // cout << intPtr << endl; <- causes crash because it points to nothing

    intPtr = nullptr;

    cout << "Pointer pointing to nullPtr" << endl;
    cout << "Address of nullPtr is " << intPtr << endl << endl;; // Address of nullPtr is 00000000

    // 00000000 is a special address assinged to a ptr to signify that it is intentially pointing to nothing.

    // Using the "new" keyword, we allocate a new int on the heap and assign its address to the pointer. 
    // The address assigned is determined by the memory allocator and will be different every time the program runs.
    // The memory allocator will look for memory that is not being used and give you its address and store your data there.
    intPtr = new int(1);

    cout << "Pointer pointing to new int(1)" << endl;
    cout << "The address of our new int is " << intPtr << endl;

    // Placing a "*" before a pointer is known as dereferencing a pointer. It's how you get the value the pointer is pointing to.
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // By dereferncing a pointer, you can change the value its pointing too.
    *intPtr = 2;
    cout << "Changing value of of memory" << endl;
    cout << "The address of our new int is " << intPtr << endl;
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // What happens if we use the "new" keyword on our pointer.

    // intPtr = new int(3);

    // We just asked the memory allocator to find us unused memory and store 3 in there.
    // What happend to our 2?
    // It is now a memory leak.
    // How do we prevent this from happening.
    // We use keyword delete.

    delete intPtr;

    // Now what happens if we dereferece our pointer?

    cout << "Delete pointer" << endl;
    cout << "The address of our new int is " << intPtr << endl << endl;
    // The address of our int is now 00008123.
    // 00008123 is a special address that prevents you from dereferencing it. 
    // When you attempt to dereference it, the program will crash.

    // Pointers can be used implicitly as a boolean value for if statements as well as integers.
    // if(0) is valid and it will be treated as if(false)
    // if(intPtr) is valid and will only return false if its set to nullPtr or 0;

    cout << "Using pointer in if statement before setting it to nullPtr" << endl;

    if (intPtr)
    {
        cout << "Our program thinks this pointer is still pointing to something." << endl << endl;
    }
    else
    {
        cout << "Our program knows this pointer does not point to anything." << endl << endl;
    }

    // It's good habbit to assign nullPtr to a pointer after you delete it.

    cout << "Using pointer in if statement after setting it to nullPtr" << endl;

    intPtr = nullptr;

    cout << "The address of our new int is " << intPtr << endl;

    if (intPtr)
    {
        cout << "Our program thinks this pointer is still pointing to something." << endl << endl;
    }
    else
    {
        cout << "Our program knows this pointer does not point to anything." << endl << endl;
    }

    // When dereferncing a pointer, its a good habbit to check if its pointing to something first.

    if (intPtr)
    {
        cout << "The value of our new int is " << *intPtr << endl << endl;
    }
    else
    {
        cout << "Our pointer isn't pointing to anything" << endl << endl;
    }

    cout << "Set pointer to new int(3)" << endl;
    intPtr = new int(3);

    if (intPtr)
    {
        cout << "The value of our new int is " << *intPtr << endl << endl;
    }
    else
    {
        cout << "Our pointer isn't pointing to anything" << endl << endl;
    }

    // clean up.
    delete intPtr;
    intPtr = nullptr;
}