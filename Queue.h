#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

class Queue
{
public:
    int nNum;
    LinkedList *linkedList;

    Queue()
    {
        nNum = 0;
        linkedList = new LinkedList();
    }
    ~Queue();
    void push(Node *n)
    {
        this->linkedList->InsertTail(n);
        this->nNum++;
    }
    void pop()
    {
        linkedList->DeleteFirst();
        this->nNum--;
    }
    Node *back()
    {
        if (nNum != 0)
            return linkedList->tail;
    }
    Node *front()
    {
        if (nNum != 0)
            return linkedList->head;
    }

    bool empty() {return !nNum;}
    int size() { return nNum; }
};

#endif