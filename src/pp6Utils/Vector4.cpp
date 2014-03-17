#include "Vector4.hpp"

Vector4::Vector4 * Vector4::createVector4(double t, double x, double y, double z)
{
    Vector4 * vec = new Vector4();
    vec->t = t;
    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}

void Vector4::destroyVector4(Vector4::Vector4 * vec)
{
    delete vec;
    vec = nullptr;
}
