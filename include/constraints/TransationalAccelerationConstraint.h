#include "constraints/IAccelerationalConstraint.h"


class TranslationalAccelerationConstraint : public IAccelerationalConstraint
{
public:
    TranslationalAccelerationConstraint(double max_acceleration) : max_acceleration(max_acceleration) { }

    virtual std::pair<double, double> get_acceleration_range(const ICurve& curve, double t_prev, double t_curr) const 
    { return {-max_acceleration, max_acceleration}; }

private:
    double max_acceleration;
};
