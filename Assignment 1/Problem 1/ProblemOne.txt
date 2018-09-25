//
// Created by islam on 9/19/2018.
//

#ifndef UNTITLED_ARBRITATYQUEUELINKEDLIST_H
#define UNTITLED_ARBRITATYQUEUELINKEDLIST_H
#include<iostream>
using namespace std;

struct xQueue{

    int infoInput;

    struct xQueue *next;

};

class ArbitraryQueue{

private:

    xQueue *rear;

    xQueue *front;

public:

    ArbitraryQueue();
    void push(int infoInput);
    int pop();
    void enqueue(int );
    void dequeue();
    void traverse();

};

ArbitraryQueue::ArbitraryQueue(){

    rear = NULL;

    front = NULL;

}
void ArbitraryQueue::push(int newInfo){
    xQueue*temp=front;
    front= new xQueue();
    front->infoInput = newInfo;
    front->next = temp;
}
int ArbitraryQueue::pop(){
    int temp=front->infoInput;
    front=front->next;
    return temp;
}
void ArbitraryQueue::enqueue(int data){

    xQueue *temp = new xQueue;


    temp->infoInput = data;

    temp->next = NULL;

    if(front == NULL){

        front = temp;

    }else{

        rear->next = temp;

    }

    rear = temp;

}

void ArbitraryQueue::dequeue(){

    xQueue *temp = new xQueue;

    if(front == NULL){

        cout<<"\nThere is nothing in the queue\n";

    }else{

        temp = front;

        front = front->next;

        delete temp;

    }

}

void ArbitraryQueue::traverse(){

    xQueue *p = new xQueue;

    p = front;

    if(front == NULL){

        cout<<"\nThere is nothing there try again\n";

    }else{

        while(p!=NULL){

            cout<<p->infoInput << " ";
            p = p->next;

        }

    }

}

#endif //UNTITLED_ARBRITATYQUEUELINKEDLIST_H
