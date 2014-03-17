#ifndef VECTOR4_HPP
#define VECTOR4_HPP

namespace Vector4
{

enum causalType {
    SPACELIKE,
    TIMELIKE,
    LIGHTLIKE
};

struct Vector4
{
    double t;
    double x;
    double y;
    double z;
};

// Create a 4-vector
Vector4 * createVector4(double t, double x, double y, double z);

// Destroy a 4-vector
void destroyVector4(Vector4 * vec);

inline double getT(const Vector4 & vec) { return vec.t; }

inline double getX(const Vector4 & vec) { return vec.x; }

inline double getY(const Vector4 & vec) { return vec.y; }

inline double getZ(const Vector4 & vec) { return vec.z; }

inline bool setT(Vector4 & vec, double val)
{
    vec.t = val;
    return true;
}

inline bool setX(Vector4 & vec, double val)
{
    vec.x = val;
    return true;
}

inline bool setY(Vector4 & vec, double val)
{
    vec.y = val;
    return true;
}

inline bool setZ(Vector4 & vec, double val)
{
    vec.z = val;
    return true;
}

} // namespace Vector4

#endif