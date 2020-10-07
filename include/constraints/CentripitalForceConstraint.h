#pragma once
#include "constraints/IIsolatedConstraint.h"
#include <math.h>


class CentripitalForceConstraint : public IIsolatedConstraint
{
public:
    CentripitalForceConstraint(double max_force, double mass) : max_force(max_force), mass(mass) { }

    virtual double get_max_velocity(const ICurve& curve, double t) const override
    { return std::sqrt(max_force / (mass * std::abs(curve.get_curvature(t)))); }

private:
    double max_force;
    double mass;
};
