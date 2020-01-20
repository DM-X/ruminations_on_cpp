#ifndef POINT_H
#define POINT_H

class Point
{
   public:
      Point(): xval(0), yval(0) { }
      Point(int x, int y): xval(x), yval(y) { }
      int x() {return xval;}
      int y() {return yval;}
      Point& x(int x) {xval = x; return *this;}
      Point& y(int y) {yval = y; return *this;}

   private:
      int xval;
      int yval;
};

#endif
