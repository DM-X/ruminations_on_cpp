#include "handle.hpp"

//------------------------------------------------------------------------------ 
Handle::Handle(): up(new UPoint) { }
//------------------------------------------------------------------------------ 
Handle::Handle(int x, int y): up(new UPoint(x, y)) { }
//------------------------------------------------------------------------------ 
Handle::Handle(const Point& p): up(new UPoint(p)) { }
//------------------------------------------------------------------------------ 
Handle::Handle(const Handle& h): up(h.up)
{
   ++(up->u);
}
//------------------------------------------------------------------------------ 
Handle& Handle::operator=(const Handle& h) 
{
   if (&h != this) {
      if (--(up->u) == 0) {
         delete up;
      }
      up = h.up;
      ++(up->u);
   }
   return *this;

   //or:

   //++(h.up->u);
   //if (--(up->u) == 0) {
   //   delete up;
   //}
   //up = h.up;
   //return *this;
}
//------------------------------------------------------------------------------ 
Handle::~Handle()
{
   if(--(up->u) == 0) {
      delete up;
   }
}
//------------------------------------------------------------------------------ 
int Handle::x() const
{
   return up->p.x();
}
//------------------------------------------------------------------------------ 
int Handle::y() const
{
   return up->p.y();
}
//------------------------------------------------------------------------------ 
Handle& Handle::x(int x0)
{
   if (up->u != 1) { //multiple handles
      --(up->u);
      up = new UPoint(up->p);
   }

   up->p.x(x0);
   return *this;
}
//------------------------------------------------------------------------------ 
Handle& Handle::y(int y0)
{
   if (up->u != 1) { //multiple handles
      --(up->u);
      up = new UPoint(up->p);
   }

   up->p.y(y0);
   return *this;
}
//------------------------------------------------------------------------------ 
