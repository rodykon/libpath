#pragma once
#include <utility>
#include "curve/ICurve.h"


class IAccelerationalConstraint
{
public:
    /*
    * @brief: Returns the maximum acceleration allowed by this constraint.
    * 
    * @param[in]: curve The curve we are returning the constraint for.
    * @param[in]: t_prev The curve parameter of the previous point.
    * @param[in]: t_curr The curve parameter of the point to get constraint for.
    * @return: The maximum acceleration allowed by this constraint.
    */
    virtual std::pair<double, double> get_acceleration_range(const ICurve& curve, double t_prev, double t_curr) const = 0;
};
