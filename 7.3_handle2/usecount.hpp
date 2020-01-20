#ifndef USECOUNT_H
#define USECOUNT_H

class UseCount
{
   public:
      UseCount(): p(new int(1)) { }
      UseCount(const UseCount& u): p(u.p) {++*p;}
      ~UseCount() {if (--*p==0) delete p;}
      bool only() {return *p==1;}
      bool makeonly() {
         if (*p == 1) {
            return false;
         }
         --*p;
         p = new int(1);
         return true;
      }
      bool reattach(const UseCount& u) {
         ++*u.p;
         if (--*p == 0) {
            delete p;
            p = u.p;
            return true;
         }
         p = u.p;
         return false;
      }
   private:
      UseCount& operator=(const UseCount& u) { }
      int* p;
};

#endif
