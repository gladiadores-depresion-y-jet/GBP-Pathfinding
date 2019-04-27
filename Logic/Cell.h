//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef PATHFINDING_CELL_H
#define PATHFINDING_CELL_H

#include <vector>

using namespace std;
class Cell
{
    private:
        int column;
        int line;
        int F;
        int G;
        int H;
        bool obstacle;
        vector<Cell*> neighbours;
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
        void setF();
        void setG(int g);
        void setH(int h);
        void addNeighbour(Cell* n);
        void setAsObstacle();
        bool isObstacle();
        void markNeighbours();

};


#endif //PATHFINDING_CELL_H
