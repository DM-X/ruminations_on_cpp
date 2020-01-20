#include <iostream>
#include "vehiclesurrogate.hpp"

using std::cout;
using std::endl;

int main()
{
   VehicleSurrogate v[100];
   {
      Automobile a;
      a.set_weight(1200);
      a.set_nbr_tyres(4);
      a.set_cabriot(true);
      cout << "------------a-------------" << endl;
      cout << "weight: "    << a.weight() << endl;
      cout << "nbr_tyres: " << a.nbr_tyres() << endl;
      cout << "cabriot: "   << a.cabriot() << endl;

      Bike b;
      b.set_weight(12);
      b.set_nbr_tyres(2);
      b.set_electric(false);
      cout << "------------b-------------" << endl;
      cout << "weight: "    << b.weight() << endl;
      cout << "nbr_tyres: " << b.nbr_tyres() << endl;
      cout << "electric: "  << b.electric() << endl;

      v[0] = a;
      v[1] = b;
   }

   cout << "-----------v[0]------------" << endl;
   cout << "weight: "    << v[0].weight() << endl;
   cout << "nbr_tyres: " << v[0].nbr_tyres() << endl;
   cout << "cabriot: "   << v[0].cabriot() << endl;

   cout << "-----------v[1]------------" << endl;
   cout << "weight: "    << v[1].weight() << endl;
   cout << "nbr_tyres: " << v[1].nbr_tyres() << endl;
   cout << "electric: "  << v[1].electric() << endl;

   return 0;
}
