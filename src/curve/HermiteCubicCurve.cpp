#include "curve/HermiteCubicCurve.h"

HermiteCubicCurve::HermiteCubicCurve(const Vector& p0, const Vector& v0, const Vector& p1, const Vector& v1)
{
    calculate_params(p0, v0, p1, v1);
}

void HermiteCubicCurve::calculate_params(const Vector& p0, const Vector& v0, const Vector& p1, const Vector& v1)
{
    ax = v1.x + v0.x - 2 * p1.x + 2 * p0.x;
    ay = v1.y + v0.y - 2 * p1.y + 2 * p0.y;

    bx = -1 * v1.x - 2 * v0.x - 3 * p0.x + 3 * p1.x;
    by = -1 * v1.y - 2 * v0.y - 3 * p0.y + 3 * p1.y;

    cx = v0.x;
    cy = v0.y;

    dx = p0.x;
    dy = p0.y;
}

Vector HermiteCubicCurve::get_point(double t) const
{
    double x = ax * t*t*t + bx * t*t + cx * t + dx;
    double y = ay * t*t*t + by * t*t + cy * t + dy;
    return {x, y};
}

Vector HermiteCubicCurve::get_velocity(double t) const
{
    double x = 3 * ax * t*t + 2 * bx * t + cx;
    double y = 3 * ay * t*t + 2 * by * t + cy;
    return {x, y};
}

Vector HermiteCubicCurve::get_acceleration(double t) const
{
    double x = 6 * ax * t + 2 * bx;
    double y = 6 * ay * t + 2 * by;
    return {x, y};
}

double HermiteCubicCurve::get_curvature(double t) const
{
    Vector first_deriv = get_velocity(t);
    Vector second_deriv = get_acceleration(t);

    return (first_deriv.x * second_deriv.y - first_deriv.y * second_deriv.x) / 
        std::pow(first_deriv.x * first_deriv.x + first_deriv.y * first_deriv.y, 1.5);
}
