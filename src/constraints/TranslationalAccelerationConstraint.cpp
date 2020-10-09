#include "constraints/TranslationalAccelerationConstraint.h"

std::vector<std::pair<double, double>> TranslationalAccelerationConstraint::get_acceleration_range(const MotionProfileSegment& prev_segment, const MotionProfileSegment& curr_segment) const
{
    double prev_vel_squared, two_a_delta_s, v_min, v_max;

    prev_vel_squared = prev_segment.velocity * prev_segment.velocity;
    two_a_delta_s = 2 * max_acceleration * prev_segment.length;
    
    v_min = prev_vel_squared > two_a_delta_s ? sqrt(prev_vel_squared - two_a_delta_s) : 0.0;
    v_max = sqrt(prev_vel_squared + two_a_delta_s);
    return { { v_min, v_max } };
}