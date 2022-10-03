#ifndef SPHERE_INTERSECT_VALID_H
#define SPHERE_INTERSECT_VALID_H

//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_spherical_kernel_3.h>
#include <CGAL/Sphere_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Vector_3.h>
#include <CGAL/Line_3.h>
//#include <CGAL/Spherical_kernel_intersections.h>

typedef CGAL::Exact_spherical_kernel_3 K;
typedef K::Point_3 Point_3;
typedef K::Vector_3 Vector_3;
typedef K::Sphere_3 Sphere_3;
typedef K::Line_3 Line_3;
typedef K::Intersect_3 intersect;

#include <iostream>
#include <cmath>

int foo ();

#endif // SPHERE_INTERSECT_VALID_H
