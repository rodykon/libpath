#include "constraints/RotationalAccelerationConstraint.h"

std::vector<std::pair<double, double>> RotationalAccelerationConstraint::get_acceleration_range(const MotionProfileSegment& prev_segment, const MotionProfileSegment& curr_segment) const
{
    double intermediate, in_sqrt_1, in_sqrt_2, v1, v2, v1_star, v2_star, v1_hat, v2_hat;

    if (curr_segment.curvature == 0)
    {
        if (prev_segment.curvature == 0)
            return { { -1, -1 } };

        intermediate = (2 * prev_segment.length * max_alpha) / (prev_segment.curvature * prev_segment.velocity);
        v1_hat = -intermediate - prev_segment.velocity;
        v2_hat = intermediate - prev_segment.velocity;
        if (prev_segment.curvature > 0)
            return { { v1_hat, v2_hat } };
        else
            return { { v2_hat, v1_hat } };
    }

    intermediate = (curr_segment.curvature + prev_segment.curvature) * prev_segment.velocity;
    in_sqrt_1 = intermediate * intermediate + 8 * curr_segment.curvature * max_alpha * prev_segment.length;
    in_sqrt_2 = intermediate * intermediate - 8 * curr_segment.curvature * max_alpha * prev_segment.length;
    
    intermediate = (prev_segment.curvature - curr_segment.curvature) * prev_segment.velocity;
    v1 = (intermediate + sqrt(in_sqrt_1)) / (2 * curr_segment.curvature);
    v2 = (intermediate - sqrt(in_sqrt_1)) / (2 * curr_segment.curvature);

    v1_star = (intermediate + sqrt(in_sqrt_2)) / (2 * curr_segment.curvature);
    v2_star = (intermediate - sqrt(in_sqrt_2)) / (2 * curr_segment.curvature);

    if (curr_segment.curvature > 0)
    {
        if (in_sqrt_2 < 0)
            return { { v2, v1 } };
        else
            return { { v2, v2_star }, { v1_star, v1 } };
        
    }
    else
    {
        if (in_sqrt_1 < 0)
            return { { v1_star, v2_star } };
        else
            return { { v1_star, v1 }, { v2, v2_star } };
    }
}