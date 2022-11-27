#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cmath>
#define _USE_MATH_DEFINES

#include "poaky.h"
#include "shape/sphere_ref.h"
#include "rop/reflect_ref.h"
#include "rop/refract_ref.h"
#include "utils/ray_eq.h"
#include "transfer/transfer_ref.h"

#include "instantiators.h"
#include "printers.h"

#endif // TEST_MAIN_H
