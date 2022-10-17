#ifndef CGAL_TYPES_H
#define CGAL_TYPES_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_spherical_kernel_3.h>
#include <CGAL/Sphere_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Vector_3.h>
#include <CGAL/Line_3.h>

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
typedef Kf::Vector_3 Vector_3f;

#endif // CGAL_TYPES_H
