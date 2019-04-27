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

void Matrix::setNeighbours(Cell* cell)
{
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

void Matrix::AstarFindPath(int lstart, int cstart, int lfinish, int cfinish)
{
    Cell* start=get(lstart,cstart);
    Cell* finish= get(lfinish,cfinish);
    List<Cell*>* open= new List<Cell*>;
    List<Cell*>* closed= new List<Cell*>;

    open->add(start);

    while(true)
    {
        Node<Cell*>* temp= open->getHead();
        while(temp!= nullptr)
        {
            temp->getValue()->setG(getGCost(temp->getValue(),closed,start));
            temp->getValue()->setH(getHCost(temp->getValue(),finish));
            temp=temp->getNext();
        }
        Node<Cell*>* currentNode= lowestF(open);
        Cell* current=currentNode->getValue();

        closed->add(currentNode->getValue());
        open->del(currentNode->getOrder());

        if(current->getLine()==finish->getLine()&&current->getColumn()==finish->getColumn())
        {
            break;
        }
        setNeighbours(current);
        List<Cell*>* currentN=current->getNeighbours();
        temp=currentN->getHead();
        while(temp!= nullptr)
        {
            if(temp->getValue()->isObstacle()||in(closed,temp->getValue()))
            {
                temp=temp->getNext();
            }
            else
            {

            }
        }



    }
}

int Matrix::getHCost(Cell *askingC,Cell* destiny)
{
    if(askingC->getLine()==destiny->getLine()&&askingC->getColumn()==destiny->getColumn())
    {
        return 0;
    }
    else
    {
        int cost=0;
        int line=askingC->getLine();
        int column=askingC->getColumn();
        while(true)
        {
            if(line==destiny->getLine()&&column==destiny->getColumn())
            {
                return cost;
            }
            else if(destiny->getLine()>line)
            {
                if(destiny->getColumn()>column)
                {
                    cost+=14;
                    line+=1;
                    column+=1;
                }
                else if(destiny->getColumn()<column)
                {
                    cost+=14;
                    line+=1;
                    column-=1;
                }
                else
                {
                    cost+=10;
                    line+=1;
                }
            }
            else if(destiny->getLine()<line)
            {
                if(destiny->getColumn()>column)
                {
                    cost+=14;
                    line-=1;
                    column+=1;
                }
                else if(destiny->getColumn()<column)
                {
                    cost+=14;
                    line-=1;
                    column-=1;
                }
                else
                {
                    cost+=10;
                    line-=1;
                }
            }
            else
            {
                if(destiny->getColumn()>column)
                {
                    cost+=10;
                    column+=1;
                }
                else if(destiny->getColumn()<column)
                {
                    cost+=10;
                    column-=1;
                }
            }
        }
    }
}
int Matrix::getGCost(Cell *askingC, List<Cell *> *closed,Cell* begining)
{
    Cell* cNeigh= nullptr;
    Node<Cell*>* temp=askingC->getNeighbours()->getHead();
    while(temp!= nullptr)
    {
        if(in(closed,temp->getValue()))
        {
            if(cNeigh== nullptr||cNeigh->getG()>temp->getValue()->getG())
            {
                cNeigh=temp->getValue();
            }
        }
        temp=temp->getNext();
    }
    if(cNeigh!= nullptr)
    {
        if (cNeigh->getLine() > askingC->getLine()||cNeigh->getLine() < askingC->getLine()) {
            if (cNeigh->getColumn() > askingC->getColumn()||cNeigh->getColumn() < askingC->getColumn())
            {
                return (14 + cNeigh->getG());
            }
            else
            {
                return (10 + cNeigh->getG());
            }
        }
        else
        {
            return (14 + cNeigh->getG());
        }

    }
    else
    {
        return 0;
    }
}


Node<Cell*>*Matrix::lowestF(List<Cell *> *list)
{
    Node<Cell*>* temp=list->getHead();
    Node<Cell*>* c= temp;
    while(temp!= nullptr)
    {
        if(temp->getValue()->getF()<c->getValue()->getF())
        {
            c=temp;
        }
        else if(temp->getValue()->getF()==c->getValue()->getF())
        {
            if(temp->getValue()->getH()<c->getValue()->getH())
            {
                c=temp;
            }
        }
        temp=temp->getNext();
    }
    return c;
}

bool Matrix::in(List<Cell *> *list, Cell *cell)
{
    Node<Cell*>*temp=list->getHead();
    while(temp!= nullptr)
    {
        if(temp->getValue()->getLine()==cell->getLine()&&temp->getValue()->getColumn()==cell->getColumn())
        {
            return true;
        }
        temp=temp->getNext();
    }
    return false;
}

bool Matrix::isShorter(Cell *testCell, Cell *newParentCell)
{
    int gCost=0;
}
