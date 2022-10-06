#ifndef SPHERE_INTERSECT_VALID_H
#define SPHERE_INTERSECT_VALID_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_spherical_kernel_3.h>
#include <CGAL/Sphere_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Vector_3.h>
#include <CGAL/Line_3.h>

#include "poaky.h"

typedef CGAL::Exact_spherical_kernel_3 K;
typedef K::Point_3 Point_3;
typedef K::Vector_3 Vector_3;
typedef K::Sphere_3 Sphere_3;
typedef K::Line_3 Line_3;
typedef K::Intersect_3 intersect;
typedef K::Circular_arc_point_3 CPoint_3;
typedef std::pair <CPoint_3, unsigned> Inter;

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kf;
typedef Kf::Point_3 Point_3f;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

ray cgal_sphere_intersect (const sphere s, const ray r);

Point_3f intersection_to_point (CGAL::Object inter);
Sphere_3 sphere_tocgal (sphere s);
Line_3 ray_tocgal (ray r);
bool is_closer_tolocalplane (Point_3f p1, Point_3f p2);

#endif // SPHERE_INTERSECT_VALID_H
