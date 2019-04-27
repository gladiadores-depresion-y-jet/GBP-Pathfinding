//
// Created by dcamachog1501 on 24/04/19.
//

#include <string>
#include <iostream>
#include "Matrix.h"
Matrix::Matrix()
{
    this->head= nullptr;
}

void Matrix::fill10()
{
    for(int i=0;i<10;i++)
    {
        List<Cell*>* l= new List<Cell*>();
        if(this->head== nullptr)
        {
            this->head=l;
        }
        else
        {
            List<Cell*>*temp= this->head;
            while(temp->getNext()!= nullptr)
            {
                temp=(List<Cell*>*)temp->getNext();
            }
            temp->setNext(l);
        }
        int c=0;
        while(l->getLength()<10)
        {
            Cell* cl= new Cell(i,c);
            l->add(cl);
            c++;
        }
    }

}

void Matrix::print()
{
    List<Cell*>* temp= this->head;
    while(temp!= nullptr)
    {
        Node<Cell*>* temp2=temp->getHead();
        string one= "";
        while(temp2!= nullptr)
        {
            one+=" ______";
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string two= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                two+="******|";
            }
            else
            {
                two+=to_string(temp2->getValue()->getG())+"   "+to_string(temp2->getValue()->getH())+" |";
            }
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string three= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                three+="******|";
            }
            else
            {
                three+="      |";
            }
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string four= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                four+="******|";
            }
            else
            {
                four+="   "+to_string(temp2->getValue()->getF())+"  |";
            }
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string five= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                five+="******|";
            }
            else
            {
                five += "______|";
            }
            temp2=temp2->getNext();
        }
        cout<<one<<endl;
        cout<<two<<endl;
        cout<<three<<endl;
        cout<<four<<endl;
        cout<<five<<endl;
        temp=temp->getNext();
    }
}

Cell *Matrix::get(int f, int c)
{
    if(f>9||c>9)
    {
        return nullptr;
    }
    List<Cell*>* temp=this->head;
    while(temp->getHead()->getValue()->getLine()!=f)
    {
        if(temp== nullptr)
        {
            break;
        }
        temp=temp->getNext();
    }
    Node<Cell*>*temp2=temp->getHead();
    while(temp2->getValue()->getColumn()!=c)
    {
        if(temp2== nullptr)
        {
            return nullptr;
        }
        temp2=temp2->getNext();
    }
    return temp2->getValue();
}

void Matrix::setNeighbours(int l,int c)
{
    Cell* cell= get(l,c);
    if (cell->getLine() == 0)
    {
        if (cell->getColumn() == 0) {
            cell->addNeighbour(getNeighbour(cell, "r"));
            cell->addNeighbour(getNeighbour(cell, "d"));
            cell->addNeighbour(getNeighbour(cell, "dr"));
        } else if (cell->getColumn() == 9) {
            cell->addNeighbour(getNeighbour(cell, "l"));
            cell->addNeighbour(getNeighbour(cell, "d"));
            cell->addNeighbour(getNeighbour(cell, "dl"));
        } else {
            cell->addNeighbour(getNeighbour(cell, "r"));
            cell->addNeighbour(getNeighbour(cell, "dr"));
            cell->addNeighbour(getNeighbour(cell, "d"));
            cell->addNeighbour(getNeighbour(cell, "dl"));
            cell->addNeighbour(getNeighbour(cell, "l"));
        }
    }
    else if (cell->getLine() == 9)
    {
        if (cell->getColumn() == 0) {
            cell->addNeighbour(getNeighbour(cell, "u"));
            cell->addNeighbour(getNeighbour(cell, "ur"));
            cell->addNeighbour(getNeighbour(cell, "r"));
        } else if (cell->getColumn() == 9) {
            cell->addNeighbour(getNeighbour(cell, "u"));
            cell->addNeighbour(getNeighbour(cell, "ul"));
            cell->addNeighbour(getNeighbour(cell, "l"));
        } else {
            cell->addNeighbour(getNeighbour(cell, "l"));
            cell->addNeighbour(getNeighbour(cell, "ul"));
            cell->addNeighbour(getNeighbour(cell, "u"));
            cell->addNeighbour(getNeighbour(cell, "ur"));
            cell->addNeighbour(getNeighbour(cell, "r"));
        }
    }
    else if (cell->getColumn() == 0)
    {
        cell->addNeighbour(getNeighbour(cell, "u"));
        cell->addNeighbour(getNeighbour(cell, "ur"));
        cell->addNeighbour(getNeighbour(cell, "r"));
        cell->addNeighbour(getNeighbour(cell, "dr"));
        cell->addNeighbour(getNeighbour(cell, "d"));
    }
    else if (cell->getColumn() == 9)
    {
        cell->addNeighbour(getNeighbour(cell, "u"));
        cell->addNeighbour(getNeighbour(cell, "ul"));
        cell->addNeighbour(getNeighbour(cell, "l"));
        cell->addNeighbour(getNeighbour(cell, "dl"));
        cell->addNeighbour(getNeighbour(cell, "d"));
    }
    else
    {
        cell->addNeighbour(getNeighbour(cell, "ul"));
        cell->addNeighbour(getNeighbour(cell, "u"));
        cell->addNeighbour(getNeighbour(cell, "ur"));
        cell->addNeighbour(getNeighbour(cell, "r"));
        cell->addNeighbour(getNeighbour(cell, "dr"));
        cell->addNeighbour(getNeighbour(cell, "d"));
        cell->addNeighbour(getNeighbour(cell, "dl"));
        cell->addNeighbour(getNeighbour(cell, "l"));
    }

}

Cell *Matrix::getNeighbour(Cell* c,string position)
{
    if(position=="u")
    {
        return get(c->getLine()-1,c->getColumn());
    }
    else if(position=="ul")
    {
        return get(c->getLine()-1,c->getColumn()-1);
    }
    else if(position=="ur")
    {
        return get(c->getLine()-1,c->getColumn()+1);
    }
    else if(position=="l")
    {
        return get(c->getLine(),c->getColumn()-1);
    }
    else if(position=="r")
    {
        return get(c->getLine(),c->getColumn()+1);
    }
    else if(position=="d")
    {
        return get(c->getLine()+1,c->getColumn());
    }
    else if(position=="dl")
    {
        return get(c->getLine()+1,c->getColumn()-1);
    }
    else if (position=="dr")
    {
        return get(c->getLine()+1,c->getColumn()+1);
    }
}

void Matrix::setAsObstacle(int l,int c)
{
    Cell* cell=get(l,c);
    cell->setAsObstacle();

}
