#include "TestConstraints.h"

void test_translational_velocity_constraint()
{
    TranslationalVelocityConstraint constraint(5.0);
    std::cout << "TranslationalVelocityConstraint: " << constraint.get_max_velocity(create_test_hermite_quintic_curve(), 0.0) << std::endl;
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

std::string acceleration_constraint_str(const std::vector<std::pair<double, double>>& constraint)
{
    std::string result("{ ");
    for (const auto& pair : constraint)
    {
        result += "{ ";
        result += std::to_string(pair.first);
        result += ", ";
        result += std::to_string(pair.second);
        result += " }, ";
    }
    return result += "}";
}

void test_translational_acceleration_constraint()
{
    TranslationalAccelerationConstraint constraint(5.0);
    std::vector<std::pair<double, double>> result = constraint.get_acceleration_range({0.01, 3.0, -1.0}, {0.01, 7.0, -0.999});
    std::cout << "TranslationalAccelerationConstraint: " << acceleration_constraint_str(result).data() << std::endl;
}

void test_rotational_acceleration_constraint()
{
    RotationalAccelerationConstraint constraint(20.0);
    std::vector<std::pair<double, double>> result = constraint.get_acceleration_range({0.01, 3.0, -1.0}, {0.01, 7.0, -0.9});
    std::cout << "RotationalAccelerationConstraint: " << acceleration_constraint_str(result).data() << std::endl;
}
