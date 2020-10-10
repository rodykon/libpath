#include "curve_splitter/ChordLengthCurveSplitter.h"


inline double length(const Vector& v1, const Vector& v2)
{
    return std::sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y));
}

std::vector<double> ChordLengthCurveSplitter::split(const ICurve& curve, double arc_length) const
{
    double t_current = epsilon, t_prev = 0.0;
    double current_length = 0.0;
    std::vector<double> result;

    result.push_back(0.0);
    for (; t_current <= 1.0; t_current += epsilon)
    {
        current_length += length(curve.get_point(t_prev), curve.get_point(t_current));
        if (current_length >= arc_length)
        {
            result.push_back(t_current);
            current_length = 0;
        }
        t_prev = t_current;
    }
    return result;
}
