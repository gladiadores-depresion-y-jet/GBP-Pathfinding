//
// Created by dcamachog1501 on 24/04/19.
//

#include "Cell.h"

Cell::Cell()
{
    this->obstacle=false;
    this->column=0;
    this->line=0;
    this->F=0;
    this->G=0;
    this->H=0;
}

Cell::Cell(int l, int c)
{
    this->obstacle=false;
    this->column=c;
    this->line=l;
    this->F=0;
    this->G=0;
    this->H=0;
}

int Cell::getColumn()
{
    return this->column;
}

int Cell::getLine()
{
    return this->line;
}

int Cell::getF()
{
    return this->F;
}

int Cell::getH()
{
    return this->H;
}

void Cell::setLine(int l)
{
    this->line=l;
}

void Cell::setColumn(int c)
{
    this->column=c;
}

void Cell::setF()
{
    this->F=this->G+this->H;
}

void Cell::setG(int g)
{
    this->G=g;
}

void Cell::setH(int h)
{
    this->H=h;
}

void Cell::addNeighbour(Cell *n)
{
    this->neighbours.push_back(n);
}

void Cell::setAsObstacle()
{
    this->obstacle=true;
}

bool Cell::isObstacle()
{
    return this->obstacle;
}

int Cell::getG() {
    return this->G;
}

void Cell::markNeighbours()
{
    for(int i=0;i<neighbours.size();i++)
    {
        neighbours[i]->setG(-1);
    }
}
