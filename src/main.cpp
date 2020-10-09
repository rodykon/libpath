#include "TestCurve.h"
#include "TestConstraints.h"

int main(int, char**) {
    test_hermite_quintic();
    test_hermite_cubic();
    test_translational_velocity_constraint();
    test_rotational_velocity_constraint();
    test_centripital_force_constraint();
    test_translational_acceleration_constraint();
    test_rotational_acceleration_constraint();
}
