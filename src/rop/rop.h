#ifndef ROP_H
#define ROP_H

#include "base/Vec3.h"
#include "ray/ray.h"
#include <cmath>

void reflect (ray &r, const Vec3 &N);
void refract (ray &r, const Vec3 &N, double nr);

#endif // ROP_H
