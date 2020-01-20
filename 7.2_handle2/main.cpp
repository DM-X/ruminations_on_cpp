#include <iostream>
#include "point.hpp"
#include "handle.hpp"

using std::cout;
using std::endl;

int main() 
{
   Point p;
   p.x(5).y(6);

   cout << "p.x(5).y(6) = " << p.x() << " / " << p.y() << endl;

   Handle h_test(p);

   Handle h(3, 4);
   Handle h2 = h;
   h2.x(5);
   cout << "h.x()  = " << h.x()  << endl;
   cout << "h2.x() = " << h2.x() << endl;

   return 0;
}
