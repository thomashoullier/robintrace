#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <cmath>
#define _USE_MATH_DEFINES

#include "robintrace.h"

// Test utils
#include "utils/ray_eq.h"

// Poaky test
#include "poaky/poaky_test.h"
#include "poaky/poaky_instantiators.h"
#include "poaky/poaky_printers.h"

// Pinyo test
#include "pinyo/pinyo_test.h"
#include "pinyo/pinyo_instantiators.h"
#include "pinyo/pinyo_printers.h"

// Pewit tests
#include "pewit/pewit_test.h"

#endif // TEST_MAIN_H
