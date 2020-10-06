#include "curve/ICurve.h"


class IIsolatedConstraint
{
public:
    /*
    * @brief: Returns the maximum velocity allowed by this constraint.
    * 
    * @param[in]: curve The curve we are returning the constraint for.
    * @param[in]: t The curve parameter of the point to get constraint for.
    * @return: The maximum velocity allowed by this constraint.
    */
    virtual double get_max_velocity(const ICurve& curve, double t) const = 0;
};