#pragma once
#include <vector>

struct MotionProfileSegment
{
    double time;
    double length;
    double velocity;
    double acceleration;
};

class MotionProfile
{
public:
    MotionProfile(const std::vector<MotionProfileSegment>& segments) : segments(segments) { }
    MotionProfile(std::vector<MotionProfileSegment>&& segments) : segments(segments) { }

    MotionProfileSegment get_segment(double time) const;


private:
    std::vector<MotionProfileSegment> segments;
};