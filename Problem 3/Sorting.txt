//
// Created by islam on 9/19/2018.
//

#ifndef PM2HW1P3_SORTING_H
#define PM2HW1P3_SORTING_H
#include <iostream>
#include <cstdlib>
using namespace std;


#define SIZE 10


class stack
{
    int *arr;
    int top;
    int capacity;

public:
    stack(int size = SIZE);

    void push(int);
    int pop();
    int peek();
    int pastPeek();
    void insertionSort(int arr[], int n);

    int size();
    bool isEmpty();
    bool isFull();
};


stack::stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        cout<<"it has been swapped with b";

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    cout<<"sorting is now finished";
}

void stack::push(int x)
{
    if (isFull())
    {
        cout << "There is OverFlow occuring causing issues \n";
        exit;
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}


int stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "There is UnderFlow occuring";
        exit;
    }

    cout << "It is now Removing " << peek() << endl;

    return arr[top--];
}

int stack::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit;
}

int stack::pastPeek()
{
    return arr[top];

}
#endif //PM2HW1P3_SORTING_H
