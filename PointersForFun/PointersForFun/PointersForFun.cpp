#include <iostream>

using std::cout;
using std::endl;

void PtrByReferenceAssignScopedVariable(int*& ptr);
void PtrByValueAssignScopedVariable(int* ptr);

void PtrByReferenceAllocatedOnHeap(int*& ptr);
void PtrByValueAssignAllocatedOnHeap(int* ptr);

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

    cout << "*************** Part 1 ****************" << endl << endl;

    // Pointer declared on the stack. Originally points to nothing.
    int* intPtr;

    // cout << intPtr << endl; <- causes crash because it points to nothing

    intPtr = nullptr;

    cout << "Address of nullPtr is " << intPtr << endl << endl;; // Address of nullPtr is 00000000

    // 00000000 is a special address assinged to a ptr to signify that it is intentially pointing to nothing.

    // Using the "new" keyword, we allocate a new int on the heap and assign its address to the pointer. 
    // The address assigned is determined by the memory allocator and will be different every time the program runs.
    // The memory allocator will look for memory that is not being used and give you its address and store your data there.
    intPtr = new int(1);

    cout << "The address of our new int is " << intPtr << endl;

    // Placing a "*" before a pointer is known as dereferencing a pointer. It's how you get the value the pointer is pointing to.
    cout << "The value of our new int is " << *intPtr << endl << endl;

    // By dereferncing a pointer, you can change the value its pointing too.
    *intPtr = 2;
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

    cout << "The address of our new int is " << intPtr << endl; 
    // The address of our int is now 00008123.
    // 00008123 is a special address that prevents you from dereferencing it. 
    // When you attempt to dereference it, the program will crash.
    
    // Pointers can be used implicitly as a boolean value for if statements as well as integers.
    // if(0) is valid and it will be treated as if(false)
    // if(intPtr) is valid and will only return false if its set to nullPtr or 0;
    
    if (intPtr)
    {
        cout << "Our program thinks this pointer is still pointing to something." << endl;
    }
    else
    {
        cout << "Our program knows this pointer does not point to anything." << endl;
    }
    
    // It's good habbit to assign nullPtr to a pointer after you delete it.

    intPtr = nullptr;
    
    cout << "The address of our new int is " << intPtr << endl;

    if (intPtr)
    {
        cout << "Our program thinks this pointer is still pointing to something." << endl;
    }
    else
    {
        cout << "Our program knows this pointer does not point to anything." << endl << endl;
    }

    // When dereferncing a pointer, its a good habbit to check if its pointing to something first.

    if (intPtr)
    {
        cout << "The value of our new int is " << *intPtr << endl;
    }
    else
    {
        cout << "Our pointer isn't pointing to anything" << endl;
    }

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

    cout << "*************** Part 2 ****************" << endl << endl;


    // INTO THE WEEDS

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

    cout << "*************** Part 3 ****************" << endl << endl;

    // Pointers with the same addresses:

    // lets decare normal ints and play with these for a minute.
    int a = 1;
    int b = 2;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl << endl;

    b = a;
    a = 3;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl << endl;

    // Notice that regular variables can be copies of eachother but remain independent of each other.
    // Pointers, however when copied and have their data modifed, they both will have their data modifed. 

    int* ptr1 = new int(1);
    int* ptr2 = new int(2);

    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;

    // Keep good habbits
    delete ptr2;
    
    ptr2 = ptr1;
    *ptr1 = 3;

    // ptr1 and ptr2 now point the same address and one pointer had its data modified. 
    // Since they point the same memeory address, they both dereference the same value.
    cout << "ptr1: " << ptr1 << ", " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << ", " << *ptr2 << endl << endl;

    // This is cool and all but this can lead to problems of what part of the code is repsonsible for cleaning up the data?
    // Lets say the two pointers were in two totally separate parts of the program and one pointer got deleted.
    delete ptr1;

    cout << "ptr2 now poitnts to garbage -> " << *ptr2 << endl;
}

void PtrByReferenceAssignScopedVariable(int*& ptr)
{
    int scopedInt = 5;
    ptr = &scopedInt;

    cout << "The address of our new int in this scope is " << ptr << endl;
    cout << "The value of our new int in this scope is " << *ptr << endl << endl;
}

void PtrByValueAssignScopedVariable(int* ptr)
{
    int scopedInt = 5;
    ptr = &scopedInt;

    cout << "The address of our copied pointer in this scope is " << ptr << endl;
    cout << "The value of our copied pointer in this scope is " << *ptr << endl << endl;
}

void PtrByReferenceAllocatedOnHeap(int*& ptr)
{
    ptr = new int(7);

    cout << "The address of our new int in this scope is " << ptr << endl;
    cout << "The value of our new int in this scope is " << *ptr << endl << endl;
}

void PtrByValueAssignAllocatedOnHeap(int* ptr)
{
    ptr = new int(6);

    cout << "The address of our copied pointer in this scope is " << ptr << endl;
    cout << "The value of our copied pointer in this scope is " << *ptr << endl << endl;

    // memory leak.
}
