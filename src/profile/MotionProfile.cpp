#include "profile/MotionProfile.h"
#include <cmath>


inline double get_time(const MotionProfileSegment& segment)
{
    return (-segment.velocity + std::sqrt(segment.velocity * segment.velocity - 4 * segment.acceleration * segment.length)) / (2 * segment.acceleration);
}

MotionProfileSegment extrapolate(const MotionProfileSegment& from, double time)
{
    double dt = time - from.time;
    double length = from.length + from.velocity * dt + 0.5 * from.acceleration * dt * dt;
    double velocity = from.velocity + from.acceleration * dt;
    return { time, length, velocity, from.acceleration }
}


MotionProfileSegment MotionProfile::get_segment(double time)
{
    double curr_time = 0.0;
    MotionProfileSegment prev_segment = NULL;

    for (const auto& segment : segments)
    {
        curr_time += get_time(segment);

        if (curr_time >= time) {
            if (prev_segment == NULL) {
                prev_segment = segment;
            }

            return extrapolate(prev_segment, time);
        }

    }
}