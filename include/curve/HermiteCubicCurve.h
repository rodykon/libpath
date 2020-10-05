#pragma once
#include <cmath>
#include "curve/ICurve.h"

class HermiteCubicCurve : public ICurve
{
public:
    HermiteCubicCurve(const Vector& p0, const Vector& v0, const Vector& p1, const Vector& v1);

    virtual ~HermiteCubicCurve() = default;

    virtual Vector get_point(double t) const override;

    virtual Vector get_velocity(double t) const override;

    virtual Vector get_acceleration(double t) const override;

    virtual double get_curvature(double t) const override;

private:
    void calculate_params(const Vector& p0, const Vector& v0, const Vector& p1, const Vector& v1);

    double ax, bx, cx, dx;
    double ay, by, cy, dy;
};