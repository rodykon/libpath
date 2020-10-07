#pragma once
#include "constraints/IIsolatedConstraint.h"
#include <math.h>


class RotationalVelocityConstraint : public IIsolatedConstraint
{
public:
    RotationalVelocityConstraint(double max_omega) : max_omega(max_omega) { }

    virtual double get_max_velocity(const ICurve& curve, double t) const override
    { return max_omega / std::abs(curve.get_curvature(t)); }

private:
    double max_omega;
};
