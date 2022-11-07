#ifndef UVEC3_H
#define UVEC3_H

#include <iostream>
#include <cmath>
#include "base/Vec3.h"

class UVec3 : public Vec3 {
  using Vec3::Vec3;
};

UVec3 UVec3_lm (double _l, double _m, bool nsign);
std::ostream& operator<< (std::ostream &out, UVec3 const& v);

#endif //UVEC3_H
