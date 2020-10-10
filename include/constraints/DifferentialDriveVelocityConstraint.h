#pragma once
#include "constraints/IIsolatedConstraint.h"


class DifferentialDriveVelocityConstraint : public IIsolatedConstraint
{
public:
    
    /*
    * @brief: Constraint that makes sure the given max velocity passed by either side of a differential drive with the given distance between wheels.
    */
    DifferentialDriveVelocityConstraint(double wheel_distance, double max_velocity) : wheel_distance(wheel_distance), max_velocity(max_velocity) { }

    virtual double get_max_velocity(const ICurve& curve, double t) const override
    { return max_velocity / (1 + wheel_distance * std::abs(curve.get_curvature(t))); }

private:
    double wheel_distance;
    double max_velocity;
};