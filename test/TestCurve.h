#pragma once
#include <string>
#include "curve/HermiteQuinticCurve.h"
#include "curve/HermiteCubicCurve.h"
#include "util/CSVWriter.h"

#define CURVE_RESOLUTION 10000
#define NUM_COLUMNS 8
#define COLUMNS {"px", "py", "vx", "vy", "ax", "ay", "c"}

void test_hermite_quintic();
void test_hermite_cubic();