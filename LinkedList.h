#ifndef LinkedList_H
#define LinkedList_H

#include "Node.h"

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int nNum;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        nNum = 0;
    }
    ~LinkedList();

    void InsertFirst(Node *h)
    {
        if (this->head == nullptr)
            this->head = this->tail = h;
        else
        {
            h->next = this->head;
            this->head = h;
        }
        this->nNum++;
    }
    void InsertTail(Node *t)
    {
        if (head == nullptr)
            head = tail = t;
        else
        {
            tail->next = t;
            tail = t;
        }
        nNum++;
    }
    bool DeleteFirst()
    {
        if (this->head == nullptr)
            return false;

        Node *p = head;
        head = head->next;
        
        nNum--;
        delete p;
        return true;
    }
    bool DeleteTail()
    {
        if (this->head == nullptr)
            return false;
        if (this->head->next == nullptr)
        {
            delete head;
            return true;
        }
        else
        {
            Node *p = this->head;
            while (p->next->next != nullptr)
                p = p->next;
            Node *tmp = p->next;
            delete tmp;
            p->next = nullptr;
            this->tail = p;
            this->nNum--;
            return true;
        }
    }
    bool RemoveAll()
    {
        if (this->head == nullptr)
            return false;
        else
        {
            do
            {
                Node *tmp = this->head;
                this->head = this->head->next;
                delete tmp;
            } while (this->head != this->tail);
            delete this->head;
        }
        return true;
    }
};

#endif 