#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <cmath>

#include "myMath.hpp"
#include <iostream>

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

    // Boost in alon z-axis by velocity v
    bool boostZ(double v);

    // Returns 4-vector magnitude using g = diag(-1, 1, 1, 1)
    double mag(void) const;

    Vector4 & operator += (const Vector4 & v) { m_t += v.getT(); m_x += v.getX(); m_y += v.getY(); m_z += v.getZ(); return *this; }
    Vector4 & operator -= (const Vector4 & v) { m_t -= v.getT(); m_x -= v.getX(); m_y -= v.getY(); m_z -= v.getZ(); return *this; }
    Vector4 & operator *= (const Vector4 & v) { m_t *= v.getT(); m_x *= v.getX(); m_y *= v.getY(); m_z *= v.getZ(); return *this; }
    Vector4 & operator /= (const Vector4 & v) { m_t /= v.getT(); m_x /= v.getX(); m_y /= v.getY(); m_z /= v.getZ(); return *this; }

    Vector4 operator - (void) { return Vector4(-m_t, -m_x, -m_y, -m_z); }

private:

    double m_t;
    double m_x;
    double m_y;
    double m_z;

    causalType m_interval;

    // Returns causal type of interval described by mag(this)
    causalType interval(void) const;

};

inline Vector4 operator + (const Vector4 & v, const double c) { return Vector4(v.getT() + c, v.getX() + c, v.getY() + c, v.getZ() + c); }
inline Vector4 operator - (const Vector4 & v, const double c) { return Vector4(v.getT() - c, v.getX() - c, v.getY() - c, v.getZ() - c); }

inline Vector4 operator + (const double c, const Vector4 & v) { return Vector4(c + v.getT(), c + v.getX(), c + v.getY(), c + v.getZ()); }
inline Vector4 operator - (const double c, const Vector4 & v) { return Vector4(c - v.getT(), c - v.getX(), c - v.getY(), c - v.getZ()); }

inline Vector4 operator + (const Vector4 & v1, const Vector4 & v2) { return Vector4(v1.getT() + v2.getT(), v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getY() + v2.getY()); }
inline Vector4 operator - (const Vector4 & v1, Vector4 & v2) { return v1 + (-v2); } // Second arg not const?

inline std::ostream& operator<<(std::ostream & stream, const Vector4 & v)
{
    stream << "[ ";
    stream << v.getT() << " ";
    stream << v.getX() << " ";
    stream << v.getY() << " ";
    stream << v.getZ();

    return stream;
}

inline std::istream& operator>>(std::istream & stream, Vector4 & v)
{
    double t = 0;
    double x = 0;
    double y = 0;
    double z = 0;

    stream >> t >> x >> y >> z;

    v.setT(t);
    v.setX(x);
    v.setY(y);
    v.setZ(z);

    return stream;
}



#endif