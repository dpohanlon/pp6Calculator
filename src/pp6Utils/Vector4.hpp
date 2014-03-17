#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <cmath>

#include "myMath.hpp"

class Vector4
{

public:

    Vector4(double t, double x, double y, double z);

    enum causalType {
        SPACELIKE,
        TIMELIKE,
        LIGHTLIKE
    };

    inline double getT(void) const { return m_t; }
    inline double getX(void) const { return m_x; }
    inline double getY(void) const { return m_y; }
    inline double getZ(void) const { return m_z; }
    inline causalType getInterval(void) const { return m_interval; }

    bool setT(double val);
    bool setX(double val);
    bool setY(double val);
    bool setZ(double val);

    // Boost in z-direction by velocity v
    bool boostZ(double v);

    // Returns 4-vector magnitude using g = diag(-1, 1, 1, 1)
    double mag(void) const;

private:

    double m_t;
    double m_x;
    double m_y;
    double m_z;

    causalType m_interval;

    // Returns causal type of interval described by mag(this)
    causalType interval(void) const;

};

#endif