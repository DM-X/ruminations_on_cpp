#include "handle.hpp"

//------------------------------------------------------------------------------ 
Handle::Handle(): p(new Point) { }
//------------------------------------------------------------------------------ 
Handle::Handle(int x, int y): p(new Point(x, y)) { }
//------------------------------------------------------------------------------ 
Handle::Handle(const Point& p): p(new Point(p)) { }
//------------------------------------------------------------------------------ 
Handle::Handle(const Handle& h): u(h.u), p(h.p) { }
//------------------------------------------------------------------------------ 
Handle& Handle::operator=(const Handle& h) 
{
   if (u.reattach(h.u)) {
      delete p;
   }
   p = h.p;
   return *this;
}
//------------------------------------------------------------------------------ 
Handle::~Handle()
{
   if (u.only()) {
      delete p;
   }
}
//------------------------------------------------------------------------------ 
int Handle::x() const
{
   return p->x();
}
//------------------------------------------------------------------------------ 
int Handle::y() const
{
   return p->y();
}
//------------------------------------------------------------------------------ 
Handle& Handle::x(int x0)
{
   if (u.makeonly()) { //multiple handles
      p = new Point(*p);
   }

   p->x(x0);
   return *this;
}
//------------------------------------------------------------------------------ 
Handle& Handle::y(int y0)
{
   if (u.makeonly()) { //multiple handles
      p = new Point(*p);
   }

   p->y(y0);
   return *this;
}
//------------------------------------------------------------------------------ 
