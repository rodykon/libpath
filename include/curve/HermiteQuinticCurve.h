#pragma once
#include <math.h>
#include "curve/ICurve.h"

class HermiteQuinticCurve : public ICurve
{
public:
    HermiteQuinticCurve(const Vector& p0, const Vector& v0, const Vector& a0, const Vector& p1, const Vector& v1, const Vector& a1);

    virtual ~HermiteQuinticCurve() = default;

    virtual Vector get_point(double t) const override;

    virtual Vector get_velocity(double t) const override;

    virtual Vector get_acceleration(double t) const override;

    virtual double get_curvature(double t) const override;

private:
    void calculate_params(const Vector& p0, const Vector& v0, const Vector& a0, const Vector& p1, const Vector& v1, const Vector& a1);

    double ax, bx, cx, dx, ex, fx;
    double ay, by, cy, dy, ey, fy;
};
