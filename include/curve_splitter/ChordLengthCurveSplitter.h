#pragma once
#include "curve_splitter/ICurveSplitter.h"
#include <cmath>


class ChordLengthCurveSplitter : public ICurveSplitter
{
public:

    ChordLengthCurveSplitter(double epsilon) : epsilon(epsilon) { }

    virtual std::vector<double> split(const ICurve& curve, double arc_length) const override;

private:
    double epsilon;
};
