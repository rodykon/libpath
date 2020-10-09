#include "constraints/IAccelerationalConstraint.h"
#include <math.h>


class RotationalAccelerationConstraint : public IAccelerationalConstraint
{
public:
    RotationalAccelerationConstraint(double max_alpha) : max_alpha(max_alpha) { }

    virtual std::vector<std::pair<double, double>> get_acceleration_range(const MotionProfileSegment& prev_segment, const MotionProfileSegment& curr_segment) const;

private:
    double max_alpha;
};
