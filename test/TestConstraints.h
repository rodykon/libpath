#pragma once
#include <iostream>
#include "TestCurve.h"
#include "constraints/TranslationalVelocityConstraint.h"
#include "constraints/TransationalAccelerationConstraint.h"
#include "constraints/RotationalVelocityConstraint.h"

void test_translational_velocity_constraint();
void test_translational_acceleration_constraint();
void test_rotational_velocity_constraint();