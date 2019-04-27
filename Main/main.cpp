#include <iostream>
#include "../Logic/Matrix.h"

using namespace std;

int main()
{
   /*cout<<" ______"<<endl;
   cout<<"|******|"<<endl;
   cout<<"|******|"<<endl;
   cout<<"|  60  |"<<endl;
   cout<<"|______|"<<endl;*/

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
   Cell* c=m->get(0,3);
   m->setNeighbours(c->getLine(),c->getColumn());
   //c->markNeighbours();
   m->print();

    return 0;
}