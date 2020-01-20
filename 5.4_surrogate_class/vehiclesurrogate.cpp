#include "vehiclesurrogate.hpp"
//------------------------------------------------------------------------------ 
VehicleSurrogate::VehicleSurrogate(): vp(0)
{
}
//------------------------------------------------------------------------------ 
VehicleSurrogate::VehicleSurrogate(const Vehicle& v): vp(v.copy())
{
}
//------------------------------------------------------------------------------ 
VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& vs):
   vp(vs.vp ? vs.vp->copy() : 0)
{
}
//------------------------------------------------------------------------------ 
VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& vs)
{
   if (this != &vs) {
      delete vp;
      vp = (vs.vp ? vs.vp->copy() : 0);
   }
   return *this;
}
//------------------------------------------------------------------------------ 
VehicleSurrogate::~VehicleSurrogate()
{
   delete vp;
}
//------------------------------------------------------------------------------ 
double VehicleSurrogate::weight() const
{
   if (vp==0)
      throw "empty VehicleSurrogate.weight()";
   return vp->weight();
}
//------------------------------------------------------------------------------ 
int  VehicleSurrogate::nbr_tyres() const
{
   return vp->nbr_tyres();
}
//------------------------------------------------------------------------------ 
bool VehicleSurrogate::cabriot() const
{
   return vp->cabriot();
}
//------------------------------------------------------------------------------ 
bool VehicleSurrogate::electric() const
{
   return vp->electric();
}
//------------------------------------------------------------------------------ 
//------------------------------------------------------------------------------ 
