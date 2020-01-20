#ifndef UPOINT_H
#define UPOINT_H

class UPoint
{
   friend class Handle;
   private:
      Point p;
      int u;
      UPoint(): u(1) { }
      UPoint(int x, int y): p(x, y), u(1) { }
      UPoint(const Point& p0): p(p0), u(1) { }
      ~UPoint();
};

#endif
