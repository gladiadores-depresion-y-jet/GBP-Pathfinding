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
   /*for(int i=0;i<10;i++)
   {
     m->setAsObstacle(i,i);
   }
   int l=9;
   for(int i=0;i<10;i++)
   {
        m->setAsObstacle(l,i);
        l--;
   }*/
   m->setAsObstacle(8,0);
   m->setAsObstacle(8,1);
   m->setAsObstacle(7,1);
    m->setAsObstacle(7,2);
    m->setAsObstacle(6,2);
    m->setAsObstacle(6,3);
    m->setAsObstacle(6,4);
    m->setAsObstacle(5,4);
    m->setAsObstacle(5,5);
    m->setAsObstacle(5,6);
    m->setAsObstacle(6,6);
    m->setAsObstacle(6,7);
    m->setAsObstacle(6,8);
    m->setAsObstacle(8,4);
    m->setAsObstacle(9,4);
    m->setAsObstacle(8,5);
    m->setAsObstacle(8,6);
    m->setAsObstacle(8,7);
    m->setAsObstacle(8,8);
    m->setAsObstacle(8,9);
    m->setAsObstacle(5,8);
    m->setAsObstacle(4,7);
    m->setAsObstacle(3,7);
    m->setAsObstacle(2,8);
    m->setAsObstacle(1,7);
    m->setAsObstacle(4,3);
    m->setAsObstacle(3,4);
    m->setAsObstacle(2,5);
    m->setAsObstacle(1,5);
    m->setAsObstacle(0,5);
    m->setAsObstacle(5,7);

   m->AstarFindPath(9,1,0,2);

   m->print();

    return 0;
}