//
// Created by islam on 9/19/2018.
//

#ifndef PM2HW1P2_ARBITRARYQUEUEARRAY_H
#define PM2HW1P2_ARBITRARYQUEUEARRAY_H
#include <iostream>
using namespace std;

const int size=10;
class ArbitraryQueueArray
{

private:
    int front; // index at front
    int back; // index at rear queue
    char items[size]; //store item in Q
    int top=-1;

public:
    void Queue();
    void push();
    void pop();
    void enqueue(char);
    void dequeue(char);
    void traverse();

};

void ArbitraryQueueArray::Queue()
{ front = 0;
    back = -1;

}

void ArbitraryQueueArray::push()
{
    int val;

    if(top==size-1)
    {
        printf("\nThe stack is full so try again");
    }
    else
    {
        printf("\nPlease Enter what you want to push now:");
        scanf("%d",&val);
        top=top+1;
        items[top]=val;
    }
}

void ArbitraryQueueArray::pop()
{
    if(top==-1)
    {
        printf("\nThe stack is now empty please try again");
    }
    else
    {
        printf("\nThe deleted item was %d",items[top]);
        top=top-1;
    }
}
void ArbitraryQueueArray::enqueue(char insertItem)
{ if (back==size-1)
        cout<<"\nThe queue is full try again";
    else
    { //insert at back
        cout<<"enter the data that you want to enqueue"<<insertItem;
        back++;
        items[back] = insertItem;
    }
}

void ArbitraryQueueArray::dequeue(char deletedItem)
{ if (back<front)
        cout<< "\nCannot remove item. Empty Queue!";
    else
    {
        cout<<"the data dequeue that you selected is as follows: "<<deletedItem;
        deletedItem = items[front];
        front++;
    }
}

void ArbitraryQueueArray::traverse()
{
    if(front==back)
    {
        cout <<" The queue that you have currently selected is empty";
        return;
    }
    for(int x=front+1;x<=back;x++)
        cout<<items[x]<<" ";
}
#endif //PM2HW1P2_ARBITRARYQUEUEARRAY_H
