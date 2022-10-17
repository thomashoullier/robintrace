#ifndef SPHERE_INTERSECT_VALID_H
#define SPHERE_INTERSECT_VALID_H

#include "poaky.h"
#include "cgal_types.h"

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
