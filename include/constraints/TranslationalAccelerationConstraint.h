#include "constraints/IAccelerationalConstraint.h"
#include <math.h>


class TranslationalAccelerationConstraint : public IAccelerationalConstraint
{
public:
    TranslationalAccelerationConstraint(double max_acceleration) : max_acceleration(max_acceleration) { }

    virtual std::vector<std::pair<double, double>> get_acceleration_range(const MotionProfileSegment& prev_segment, const MotionProfileSegment& curr_segment) const;

private:
    double max_acceleration;
};
