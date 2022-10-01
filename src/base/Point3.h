#ifndef POINT3_H
#define POINT3_H

#include <iostream>

class Point3 {
  public:
    double x;
    double y;
    double z;

  Point3 ();
  Point3 (double _x, double _y, double _z);
};

std::ostream& operator<< (std::ostream &out, Point3 const& p);

#endif // POINT3_H
