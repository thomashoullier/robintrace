#ifndef ROP_H
#define ROP_H

#include "base/Vec3.h"
#include "ray/ray.h"
#include "ray/ray_eig.h"
#include <cmath>

void reflect (ray &r, const Vec3 &N);
void refract (ray &r, const Vec3 &N, double nr);

void reflect_eig (ray_eig &r, const Eigen::Vector3d &N);

#endif // ROP_H
