#pragma once
#include <utility>
#include <vector>
#include "curve/ICurve.h"
#include "profile/MotionProfileSegment.h"


class IAccelerationalConstraint
{
public:
    /*
    * @brief: Returns the maximum acceleration allowed by this constraint.
    * 
    * @param[in]: prev_segment The profile segment of the previous point.
    * @param[in]: curr_segment The profile segment of the point to get constraint for.
    * @return: A list of ranges of allowed velocity at the current point.
    */
    virtual std::vector<std::pair<double, double>> get_acceleration_range(const MotionProfileSegment& prev_segment, const MotionProfileSegment& curr_segment) const = 0;
};
