//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef PATHFINDING_LIST_H
#define PATHFINDING_LIST_H


#include "Node.h"
template <class T>
class List
{
    private:
        Node<T>* head;
        int length;
        List<T>* next;
    public:
        List()
        {
            this->head= nullptr;
            this->length=0;
            this->next= nullptr;
        }
        void add(T v)
        {
            Node<T>* n= new Node<T>(v);
            if(this->head== nullptr)
            {
                this->head=n;
            }
            else
            {
                Node<T>* temp= this->head;
                while(temp->getNext()!= nullptr)
                {
                    temp=temp->getNext();
                }
                temp->setNext(v);
            }
            length++;
        }
        List<T>* getNext()
        {
            return this->next;
        }
        int getLength()
        {
            return this->length;
        }
        void setNext(List<T>* l)
        {
            this->next=l;
        }
        Node<T>* getHead()
        {
            return this->head;
        }
};


#endif //PATHFINDING_LIST_H
