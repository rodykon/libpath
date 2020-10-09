#pragma once
#include <iostream>
#include "TestCurve.h"
#include "constraints/TranslationalVelocityConstraint.h"
#include "constraints/TranslationalAccelerationConstraint.h"
#include "constraints/RotationalVelocityConstraint.h"
#include "constraints/CentripitalForceConstraint.h"
#include "constraints/RotationalAccelerationConstraint.h"

void test_translational_velocity_constraint();
void test_translational_acceleration_constraint();
void test_rotational_velocity_constraint();
void test_centripital_force_constraint();
void test_rotational_acceleration_constraint();
