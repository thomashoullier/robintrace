#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <string>
#include <cmath>

class Vec3 {
  public:
    double l;
    double m;
    double n;

  Vec3 ();
  Vec3 (double _l, double _m, double _n);
  Vec3 (double _l, double _m, bool nsign);
};

double dot (Vec3 v1, Vec3 v2);
Vec3 operator* (const double scal, const Vec3 vec);
Vec3 operator+ (const Vec3 v1, const Vec3 v2);

std::string coords_as_str (const Vec3 v);
std::ostream& operator<< (std::ostream &out, Vec3 const& v);

#endif //VEC3_H
