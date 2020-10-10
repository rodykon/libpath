#pragma once
#include <vector>
#include "curve/ICurve.h"

class ICurveSplitter
{
public:

    /**
     * @brief: Split the curve into equal arc length pieces.
     * 
     * @param[in]: curve The curve to split.
     * @param[in]: arc_length The curve will be split into equal parts of this length.
     * @return: A list of the curve parameter values that are equal arc length from eachother.
     **/
    virtual std::vector<double> split(const ICurve& curve, double arc_length) const = 0;
};