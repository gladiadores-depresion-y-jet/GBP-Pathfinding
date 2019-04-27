#include <iostream>
#include "../Logic/Matrix.h"

using namespace std;

int main()
{
   /*cout<<" ______"<<endl;
   cout<<"|******|"<<endl;
   cout<<"|******|"<<endl;
   cout<<"|  60  |"<<endl;
   cout<<"|______|"<<endl;

   Matrix* m= new Matrix();
   m->fill10();
   for(int i=0;i<10;i++)
   {
     m->setAsObstacle(i,i);
   }
   int l=9;
   for(int i=0;i<10;i++)
   {
        m->setAsObstacle(l,i);
        l--;
   }
   m->setAsObstacle(4,0);
   Cell* cell=m->get(1,2);
   Cell* start=m->get(6,7);
   int g=m->getCost(cell,start);
   cout<<"Costo de G: "<<to_string(g)<<endl;
   m->setNeighbours(cell);
   cell->markNeighbours();
   m->print();
*/
   List<Cell*>* l= new List<Cell*>;
   for(int i=0;i<10;i++)
   {
       Cell* c= new Cell;
       l->add(c);
   }
   l->del(8);
   l->del(1);
   l->del(5);
    return 0;
}