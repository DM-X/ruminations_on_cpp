#ifndef HANDLE_H
#define HANDLE_H

#include "upoint.hpp"

class Handle
{
   public:
      Handle();
      Handle(int, int);
      Handle(const Point&);
      Handle(const Handle&);
      Handle& operator=(const Handle&);
      ~Handle();

      int x() const; 
      int y() const; 
      Handle& x(int); 
      Handle& y(int);

   private:
      UPoint* up;
};

#endif
