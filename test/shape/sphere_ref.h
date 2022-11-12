#ifndef SPHERE_REF_H
#define SPHERE_REF_H

#include "poaky.h"
#include <Eigen/Dense>

ray sphere_intersect_ref (const sphere &s, const ray &r);
Vec3 sphere_normal_ref (const sphere &s, const ray &r);

#endif // SPHERE_REF_H
