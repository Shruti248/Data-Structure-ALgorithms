#include <bits/stdc++.h>
using namespace std;

void increment(int var1)
{
    cout << "Passed by value" << endl;
    // var1 is teh new variable
    var1++;
    // cout<<var1<<endl;
    cout << &var1 << endl;
}
void swap(int *var1, int *var2)
{
    cout << "Passed by reference" << endl;

    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}
int main()
{
    // Pointers are variables that store the address of other variables

    int a = 10;
    // a will have unique address

    // Pointer that poit to a
    int *aptr;
    aptr = &a;

    cout << &a << endl;   // address of
    cout << aptr << endl; // same

    // the variable can be accessed using the point , hence we use it
    cout << *aptr << endl; // deferencing : value of a = 10

    // modifying value
    *aptr = 20;
    cout << *aptr << endl;

    // varibale can be accesssed and modified using the pointer

    // POINTER ARITHEMTIC
    // Incremenet , Decrement , add , subtract
    cout << "Increment : " << ++*aptr << endl; // 21
    cout << "Decrement : " << --*aptr << endl; // 20

    int b = 30;
    int *bptr = &b;

    cout << "a+b ptr : " << *aptr + *bptr << endl;
    cout << "a-b ptr : " << *aptr - *bptr << endl;

    cout << aptr << endl; // address of a
    aptr++;
    cout << aptr << endl; // address of a + 4(size of int)

    // Pointers & Arrays
    int arr[] = {10, 20, 30};

    // arr point to the starting index of the array , we cannot modify it like the pointers but it still behaves in the similar way as pointers
    cout << *arr << endl; // 0th element

    int *ptr = arr;

    // Printing using pointer
    cout << "Array : " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << *ptr << endl;
        ptr++;
    }

    // Using Array ointer printing
    cout << "Array : " << endl;
    for (int i = 0; i < 3; i++)
    {
        // cout<<*arr<<endl;
        // arr++;  //not Allowed
        // NOTE : arr is the constant pointer : the value cannot be modified
        // Therefore adding
        cout << *(arr + i) << endl; // arr : is indexing pointer
    }

    // Pointer to Pointer
    int var = 10;
    int *p;
    p = &var;

    cout << *p << endl; // 10

    int **q = &p; // q is the address of p (pointer)

    cout << *q << endl; // Deferencing once : Address of p
    cout << p << endl;  //*q =p

    cout << **q << endl; // Dereferencing twice : Address of p + address of  var = 10
    cout << *p << endl;  //**q = *p

    // Poniter to pointer to pointer can also be made

    // IMP
    // Passing Pointer to function

    // originally teh variable passed in the function is pass by value
    int var1 = 25;
    int var2 = 35;
    increment(var1);
    cout << var1 << endl; // 10
    cout << &var1 << endl;
    // Address of both the variables passed in the fucntion and without are different. Hance both are treated differently.

    // Address before swapping
    cout << var1 << " : " << &var1 << " , " << var2 << " : " << &var2 << endl;
    swap(&var1, &var2);
    cout << var1 << " " << var2 << endl;
    // Address after swapping
    cout << var1 << " : " << &var1 << " , " << var2 << " : " << &var2 << endl;

    return 0;
}