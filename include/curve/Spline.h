#pragma once
#include <vector>
#include "curve/ICurve.h"

class Spline : public ICurve
{
public:
    Spline(std::vector<ICurve&> curves) : curves(curves) { }

    virtual ~Spline() = default;

    virtual Vector get_point(double t) const override;

    virtual Vector get_velocity(double t) const override;

    virtual Vector get_acceleration(double t) const override;

    virtual double get_curvature(double t) const override;

private:
    std::vector<ICurve&> curves;
};