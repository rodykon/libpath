#pragma once
#include "curve_splitter/ChordLengthCurveSplitter.h"
#include "curve/HermiteCubicCurve.h"
#include <iostream>

void print_curve_splitter_result(const ICurve& curve, const std::vector<double>& spline_params)
{
    for (auto& t : spline_params)
    {
        std::cout << "\tt=" << t << ";point={" << curve.get_point(t).x << "," << curve.get_point(t).y << "}" << std::endl;
    }
}

void test_chord_length_curve_splitter()
{
    ChordLengthCurveSplitter splitter(0.0001);
    HermiteCubicCurve curve({0.0, 0.0}, {0.0, 2.0}, {0.0, 4.0}, {0.0, 2.0});
    print_curve_splitter_result(curve, splitter.split(curve, 1.0));
}
