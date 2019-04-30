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
   m->setAsObstacle(2,0);
   m->setAsObstacle(2,1);
   m->setAsObstacle(2,2);
   m->setAsObstacle(2,3);
   m->setAsObstacle(2,4);
   m->setAsObstacle(2,5);
   m->setAsObstacle(2,6);
    m->setAsObstacle(2,7);
    m->setAsObstacle(2,8);
   m->setAsObstacle(3,6);

   m->AstarFindPath(4,3,0,7);

   m->print();
    return 0;
}