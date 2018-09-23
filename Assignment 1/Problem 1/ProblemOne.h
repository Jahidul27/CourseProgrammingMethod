//
// Created by islam on 9/19/2018.
//

#ifndef UNTITLED_ARBRITATYQUEUELINKEDLIST_H
#define UNTITLED_ARBRITATYQUEUELINKEDLIST_H
#include<iostream>
using namespace std;

struct ArbitraryQueue{

    int infoInput;

    struct ArbitraryQueue *next;

};

class Queue{

private:

    ArbitraryQueue *rear;

    ArbitraryQueue *front;

public:

    Queue();
    void push(int infoInput);
    int pop();
    void enqueue(int );
    void dequeue();
    void traverse();

};

Queue::Queue(){

    rear = NULL;

    front = NULL;

}
void Queue::push(int newInfo){
    ArbitraryQueue*temp=front;
    front= new ArbitraryQueue();
    front->infoInput = newInfo;
    front->next = temp;
}
int Queue::pop(){
    int temp=front->infoInput;
    front=front->next;
    return temp;
}
void Queue::enqueue(int data){

    ArbitraryQueue *temp = new ArbitraryQueue;


    temp->infoInput = data;

    temp->next = NULL;

    if(front == NULL){

        front = temp;

    }else{

        rear->next = temp;

    }

    rear = temp;

}

void Queue::dequeue(){

    ArbitraryQueue *temp = new ArbitraryQueue;

    if(front == NULL){

        cout<<"\nThere is nothing in the queue\n";

    }else{

        temp = front;

        front = front->next;

        delete temp;

    }

}

void Queue::traverse(){

    ArbitraryQueue *p = new ArbitraryQueue;

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
