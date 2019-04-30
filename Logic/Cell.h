//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef PATHFINDING_CELL_H
#define PATHFINDING_CELL_H

#include <vector>
#include "../Structures/List.h"

using namespace std;
class Cell
{
    private:
        int column;
        int line;
        int G;
        int H;
        bool obstacle;
        bool path;
        Cell* parent;
        List<Cell*>* neighbours;
    public:
        Cell();
        Cell(int l,int c);
        int getColumn();
        int getLine();
        int getF();
        int getH();
        int getG();
        void setLine(int l);
        void setColumn(int c);
        void setG(int g);
        void setH(int h);
        void addNeighbour(Cell* n);
        void setAsObstacle();
        bool isObstacle();
        bool isPath();
        void setAsPath();
        void markNeighbours();
        List<Cell*>* getNeighbours();
        Cell *getParent();
        void setParent(Cell *c);
};


#endif //PATHFINDING_CELL_H
