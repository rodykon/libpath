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

void test_rotational_velocity_constraint()
{
    RotationalVelocityConstraint constraint(3.0);
    HermiteQuinticCurve curve = create_test_hermite_quintic_curve();
    std::cout << "RotationalVelocityConstraint(t=0.0): " << constraint.get_max_velocity(curve, 0.0) << std::endl;
    std::cout << "RotationalVelocityConstraint(t=0.25): " << constraint.get_max_velocity(curve, 0.25) << std::endl;
    std::cout << "RotationalVelocityConstraint(t=0.5): " << constraint.get_max_velocity(curve, 0.5) << std::endl;
    std::cout << "RotationalVelocityConstraint(t=0.75): " << constraint.get_max_velocity(curve, 0.75) << std::endl;
    std::cout << "RotationalVelocityConstraint(t=1.0): " << constraint.get_max_velocity(curve, 1.0) << std::endl;
}

void test_centripital_force_constraint()
{
    CentripitalForceConstraint constraint(200.0, 55.0);
    HermiteQuinticCurve curve = create_test_hermite_quintic_curve();
    std::cout << "CentripitalForceConstraint(t=0.0): " << constraint.get_max_velocity(curve, 0.0) << std::endl;
    std::cout << "CentripitalForceConstraint(t=0.25): " << constraint.get_max_velocity(curve, 0.25) << std::endl;
    std::cout << "CentripitalForceConstraint(t=0.5): " << constraint.get_max_velocity(curve, 0.5) << std::endl;
    std::cout << "CentripitalForceConstraint(t=0.75): " << constraint.get_max_velocity(curve, 0.75) << std::endl;
    std::cout << "CentripitalForceConstraint(t=1.0): " << constraint.get_max_velocity(curve, 1.0) << std::endl;
}