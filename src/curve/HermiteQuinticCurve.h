#pragma once
#include "curve/ICurve.h"

class HermiteQuinticCurve : public ICurve
{
public:
    HermiteQuinticCurve(Vector p0, Vector v0, Vector a0, Vector p1, Vector v1, Vector a1);

    virtual ~HermiteQuinticCurve() = default;

    virtual Vector get_point(double t) const override;

    virtual Vector get_velocity(double t) const override;

    virtual Vector get_acceleration(double t) const override;

    virtual double get_curvature(double t) const override;

private:
    void calculate_params(Vector p0, Vector v0, Vector a0, Vector p1, Vector v1, Vector a1);

    double ax, bx, cx, dx, ex, fx;
    double ay, by, cy, dy, ey, fy;
};