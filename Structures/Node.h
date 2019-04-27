//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef PATHFINDING_NODE_H
#define PATHFINDING_NODE_H

template <class T>
class Node
{
    private:
        T value;
        Node* next;
    public:
        Node()
        {
            this->next= nullptr;
        }
        Node(T v)
        {
            this->value=v;
            this->next= nullptr;
        }
        T getValue()
        {
            return value;
        }
        Node* getNext()
        {
            return next;
        }
        void setNext(T v)
        {
            Node<T>* n= new Node(v);
            this->next=n;

        }
};


#endif //PATHFINDING_NODE_H
