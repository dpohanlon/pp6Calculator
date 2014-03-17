#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <cmath>

#include "myMath.hpp"

class Vector4
{

public:

    Vector4(double t, double x, double y, double z)
        : m_t(t), m_x(x), m_y(y), m_z(z) {}

    inline double getT(void) const { return m_t; }
    inline double getX(void) const { return m_x; }
    inline double getY(void) const { return m_y; }
    inline double getZ(void) const { return m_z; }

    bool setT(double val);
    bool setX(double val);
    bool setY(double val);
    bool setZ(double val);

    enum causalType {
        SPACELIKE,
        TIMELIKE,
        LIGHTLIKE
    };

    // Boost in z-direction by velocity v
    bool boostZ(double v);

    // Returns 4-vector magnitude using g = diag(-1, 1, 1, 1)
    double mag(void) const;

    // Returns causal type of interval described by mag(this)
    causalType interval(void) const;

private:

    double m_t;
    double m_x;
    double m_y;
    double m_z;
};

#endif