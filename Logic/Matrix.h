//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef PATHFINDING_MATRIX_H
#define PATHFINDING_MATRIX_H


#include "Cell.h"
#include "../Structures/List.h"

class Matrix
{
    private:
        List<Cell*>*head;

    public:
        Matrix();
        void fill10();
        void print();
        Cell* get(int f,int c);
        void setNeighbours(int l,int c);
        Cell* getNeighbour(Cell* c,string position);
        void setAsObstacle(int l,int c);
};


#endif //PATHFINDING_MATRIX_H
