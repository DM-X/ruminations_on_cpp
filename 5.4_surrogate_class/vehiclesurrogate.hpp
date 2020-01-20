#ifndef VEHICLESURROGATE_H
#define VEHICLESURROGATE_H

#include "vehicle.hpp"

class VehicleSurrogate
{
   public: 
      VehicleSurrogate();
      VehicleSurrogate(const VehicleSurrogate&);
      VehicleSurrogate(const Vehicle&);
      ~VehicleSurrogate();
      VehicleSurrogate& operator=(const VehicleSurrogate&);

      //operations from class Vehicle
      double weight() const; 
      double set_weight(double weight);
      int    nbr_tyres() const; 
      bool   cabriot() const; 
      bool   electric() const; 
   private:
      Vehicle* vp;
};

#endif
