#include "TestConstraints.h"

void test_translational_velocity_constraint()
{
    TranslationalVelocityConstraint constraint(5.0);
    std::cout << "TranslationalVelocityConstraint: " << constraint.get_max_velocity(create_test_hermite_quintic_curve(), 0.0) << std::endl;
}

void test_translational_acceleration_constraint()
{
    TranslationalAccelerationConstraint constraint(5.0);
    std::pair<double, double> result = constraint.get_acceleration_range(create_test_hermite_quintic_curve(), 0.0, 0.0);
    std::cout << "TranslationalAccelerationConstraint: " << result.first << ", " << result.second << std::endl;
}