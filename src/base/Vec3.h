#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <string>

class Vec3 {
  public:
    double l;
    double m;
    double n;

  Vec3 ();
  Vec3 (double _l, double _m, double _n);
};

double dot (Vec3 v1, Vec3 v2);
Vec3 operator* (const double scal, const Vec3 vec);

std::string coords_as_str (const Vec3 v);
std::ostream& operator<< (std::ostream &out, Vec3 const& v);

#endif //VEC3_H
