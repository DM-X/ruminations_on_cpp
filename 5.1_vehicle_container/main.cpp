#include <iostream>

using std::cout;
using std::endl;

class Vehicle
{
   public: 
      virtual double weight() const {return w;}
      virtual double set_weight(double weight) {w = weight;}
      virtual double length() const {return l;}
      virtual double set_length(double length) {l = length;}
   private:
      double w;
      double l;
};

class RoadVehicle: public Vehicle
{
   public: 
      int    nbr_tyres() const {return t;}
      void   set_nbr_tyres(int nbr_t) {t=nbr_t;}
   private:
      int t;
};

class Automobile: public RoadVehicle
{
   public: 
      bool   cabriot() const {return c;}
      void   set_cabriot(bool cab) {c = cab;}
   private:
      bool c;
};

class Bike: public RoadVehicle
{
   public: 
      bool   electric() const {return e;}
      void   set_electric(bool el) {e = el;}
   private:
      bool e;
};

int main()
{
   Automobile a;
   a.set_weight(1200);
   a.set_length(3.5);
   a.set_nbr_tyres(4);
   a.set_cabriot(true);
   cout << "------------a-------------" << endl;
   cout << "weight: "    << a.weight() << endl;
   cout << "lenght: "    << a.length() << endl;
   cout << "nbr_tyres: " << a.nbr_tyres() << endl;
   cout << "cabriot: "   << a.cabriot() << endl;

   Bike b;
   b.set_weight(12);
   b.set_length(1.2);
   b.set_nbr_tyres(2);
   b.set_electric(false);
   cout << "------------b-------------" << endl;
   cout << "weight: "    << b.weight() << endl;
   cout << "lenght: "    << b.length() << endl;
   cout << "nbr_tyres: " << b.nbr_tyres() << endl;
   cout << "electric: "  << b.electric() << endl;

   Vehicle v[100];
   v[0] = a;
   v[1] = b;

   cout << "-----------v[0]------------" << endl;
   cout << "weight: "    << v[0].weight() << endl;
   cout << "lenght: "    << v[0].length() << endl;
   //error: class Vehicle has no member...
   //cout << "nbr_tyres: " << v[0].nbr_tyres() << endl;
   //cout << "cabriot: "   << v[0].cabriot() << endl;

   cout << "-----------v[1]------------" << endl;
   cout << "weight: "    << v[1].weight() << endl;
   cout << "lenght: "    << v[1].length() << endl;
   //error: class Vehicle has no member...
   //cout << "nbr_tyres: " << v[1].nbr_tyres() << endl;
   //cout << "electric: "  << v[1].electric() << endl;

   return 0;
}
