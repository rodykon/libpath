#include "TestCurve.h"

void write_curve_csv(std::string curve_file, const ICurve& curve)
{
    CSVWriter writer(curve_file, 4);
    writer.write_row(COLUMNS);
    for (double t = 0.0; t <= 1.0; t += 1.0 / CURVE_RESOLUTION)
    {
        Vector point = curve.get_point(t);
        Vector velocity = curve.get_velocity(t);
        Vector acceleration = curve.get_acceleration(t);
        writer.write_row({std::to_string(point.x), std::to_string(point.y), std::to_string(velocity.x), std::to_string(velocity.y), 
                          std::to_string(acceleration.x), std::to_string(acceleration.y), std::to_string(curve.get_curvature(t))});
    }
}

HermiteQuinticCurve create_test_hermite_quintic_curve()
{
    Vector p0 = {0.0, 0.0};
    Vector p1 = {2.0, 4.0};
    Vector v0 = {0.0, 3.0};
    Vector v1 = {0.0, 3.0};
    Vector a = {0.0, 0.0};
    return HermiteQuinticCurve(p0, v0, a, p1, v1, a);
}

void test_hermite_quintic()
{
    write_curve_csv("test/curves/hermite_quintic.csv", create_test_hermite_quintic_curve());
}