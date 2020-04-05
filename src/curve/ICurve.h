#pragma once
#include "math/Vector.h"

class ICurve
{
public:

    /**
     * @brief: Get the point at the given curve parameter t.
     * 
     * @param[in]: t The curve parameter for which to extract the point.
     * @return: The point at the given curve parameter.
     **/
    virtual Vector get_point(double t) const = 0;

    /**
     * @brief: Get the velocity (first derivative) at the given curve parameter t.
     * 
     * @param[in]: t The curve parameter for which to extract the velocity.
     * @return: The velocity (first derivative) at the given curve parameter.
     **/
    virtual Vector get_velocity(double t) const = 0;

    /**
     * @brief: Get the acceleration (second derivative) at the given curve parameter t.
     * 
     * @param[in]: t The curve parameter for which to extract the acceleration.
     * @return: The acceleration (second derivative) at the given curve parameter.
     **/
    virtual Vector get_acceleration(double t) const = 0;

    /**
     * @brief: Get the curvature at the given curve parameter t. The sign of the curve is kept in order to differentiate
     * curve direction.
     * 
     * @param[in]: t The curve parameter for which to extract the curvature.
     * @return: The curvature at the given curve parameter.
     **/
    virtual double get_curvature(double t) const = 0;
};