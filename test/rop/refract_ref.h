#ifndef REFRACT_REF_H
#define REFRACT_REF_H

#include "poaky.h"
#include <cmath>

ray refract_ref (const ray &r, const Vec3 &N, double nr);

#endif // REFRACT_REF_H
