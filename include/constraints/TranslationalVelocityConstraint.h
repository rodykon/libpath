#include "constraints/IIsolatedConstraint.h"


class TranslationalVelocityConstraint : public IIsolatedConstraint
{
public:
    TranslationalVelocityConstraint(double max_velocity) : max_velocity(max_velocity) { }

    virtual double get_max_velocity(const ICurve& curve, double t) const override
    { return max_velocity; }

private:
    double max_velocity;
};
