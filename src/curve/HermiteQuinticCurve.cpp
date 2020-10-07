#include "curve/HermiteQuinticCurve.h"

HermiteQuinticCurve::HermiteQuinticCurve(const Vector& p0, const Vector& v0, const Vector& a0, const Vector& p1, const Vector& v1, const Vector& a1)
{
    calculate_params(p0, v0, a0, p1, v1, a1);
}

void HermiteQuinticCurve::calculate_params(const Vector& p0, const Vector& v0, const Vector& a0, const Vector& p1, const Vector& v1, const Vector& a1)
{
    ax = -6 * p0.x - 3 * v0.x - 0.5 * a0.x + 0.5 * a1.x - 3 * v1.x + 6 * p1.x;
    ay = -6 * p0.y - 3 * v0.y - 0.5 * a0.y + 0.5 * a1.y - 3 * v1.y + 6 * p1.y;

    bx = 15 * p0.x + 8 * v0.x + 1.5 * a0.x - a1.x + 7 * v1.x - 15 * p1.x;
    by = 15 * p0.y + 8 * v0.y + 1.5 * a0.y - a1.y + 7 * v1.y - 15 * p1.y;

    cx = -10 * p0.x - 6 * v0.x - 1.5 * a0.x + 0.5 * a1.x - 4 * v1.x + 10 * p1.x;
    cy = -10 * p0.y - 6 * v0.y - 1.5 * a0.y + 0.5 * a1.y - 4 * v1.y + 10 * p1.y;

    dx = 0.5 * a0.x;
    dy = 0.5 * a0.y;

    ex = v0.x;
    ey = v0.y;

    fx = p0.x;
    fy = p0.y;
}

Vector HermiteQuinticCurve::get_point(double t) const
{
    double x = ax * t*t*t*t*t + bx * t*t*t*t + cx * t*t*t + dx * t*t + ex * t + fx;
    double y = ay * t*t*t*t*t + by * t*t*t*t + cy * t*t*t + dy * t*t + ey * t + fy;
    return {x, y};
}

Vector HermiteQuinticCurve::get_velocity(double t) const
{
    double x = 5 * ax * t*t*t*t + 4 * bx * t*t*t + 3 * cx * t*t + 2 * dx * t + ex;
    double y = 5 * ay * t*t*t*t + 4 * by * t*t*t + 3 * cy * t*t + 2 * dy * t + ey;
    return {x,y};
}

Vector HermiteQuinticCurve::get_acceleration(double t) const
{
    double x = 20 * ax * t*t*t + 12 * bx * t*t + 6 * cx * t + 2 * dx;
    double y = 20 * ay * t*t*t + 12 * by * t*t + 6 * cy * t + 2 * dy;
    return {x,y};
}

double HermiteQuinticCurve::get_curvature(double t) const
{
    Vector first_deriv = get_velocity(t);
    Vector second_deriv = get_acceleration(t);

    return (first_deriv.x * second_deriv.y - first_deriv.y * second_deriv.x) / 
        std::pow(first_deriv.x * first_deriv.x + first_deriv.y * first_deriv.y, 1.5);
}
