#ifndef UVEC3_H
#define UVEC3_H

#include <iostream>
#include <cmath>

class UVec3 {
  public:
    double l;
    double m;
    double n;

  UVec3 ();
  UVec3 (double _l, double _m, double _n);
};

UVec3 UVec3_lm (double _l, double _m, bool nsign);

std::ostream& operator<< (std::ostream &out, UVec3 const& v);

#endif //UVEC3_H
