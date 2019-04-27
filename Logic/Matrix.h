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
        void setNeighbours(Cell* cell);
        Cell* getNeighbour(Cell* c,string position);
        void setAsObstacle(int l,int c);
        int getHCost(Cell* askingC,Cell* end);
        int getGCost(Cell* askingC,List<Cell*>* closed,Cell* begining);
        void AstarFindPath(int lstart,int cstart,int lfinish,int cfinish);
        Node<Cell*>* lowestF(List<Cell*>* list);
        bool in(List<Cell*>* list,Cell* cell);
        bool isShorter(Cell* testCell,Cell* newParentCell);
};


#endif //PATHFINDING_MATRIX_H
