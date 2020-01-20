#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
   public: 
      virtual double weight() const {return w;}
      virtual double set_weight(double weight) {w = weight;}
      virtual int    nbr_tyres() const {} 
      virtual bool   cabriot() const {} 
      virtual bool   electric() const {} 
      virtual Vehicle* copy() const = 0; 
      virtual ~Vehicle() {}
   private:
      double w;
      double l;
};

class RoadVehicle: public Vehicle
{
   public: 
      int    nbr_tyres() const {return t;}
      void   set_nbr_tyres(int nbr_t) {t=nbr_t;}
      Vehicle* copy() const {return new RoadVehicle(*this);}
   private:
      int t;
};

class Automobile: public RoadVehicle
{
   public: 
      bool   cabriot() const {return c;}
      void   set_cabriot(bool cab) {c = cab;}
      Vehicle* copy() const {return new Automobile(*this);}
   private:
      bool c;
};

class Bike: public RoadVehicle
{
   public: 
      bool   electric() const {return e;}
      void   set_electric(bool el) {e = el;}
      Vehicle* copy() const {return new Bike(*this);}
   private:
      bool e;
};

#endif
