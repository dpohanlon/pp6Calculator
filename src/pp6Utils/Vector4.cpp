#include "Vector4.hpp"

Vector4::Vector4(double t, double x, double y, double z)
    : m_t(t), m_x(x), m_y(y), m_z(z)
{
    m_interval = this->interval();
}

bool Vector4::setT(double val)
{
    m_t = val;
    return true;
}

bool Vector4::setX(double val)
{
    m_x = val;
    return true;
}

bool Vector4::setY(double val)
{
    m_y = val;
    return true;
}

bool Vector4::setZ(double val)
{
    m_z = val;
    return true;
}

bool Vector4::boostZ(double v)
{
    double beta = v; // units where c == 1
    double gamma = sqrt(1 - pow(beta, 2));

    m_t = gamma * (m_t - beta * m_z);
    m_z = gamma * (m_z - beta * m_t);

    return true;
}

double Vector4::mag(void) const
{
    double sqrtArg = pow(m_t, 2) - (pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));

    if (sqrtArg < 0) throw(Exception::noRealRoots());
    else return sqrt(sqrtArg);
}

Vector4::causalType Vector4::interval(void) const
{
    double mag = this->mag();

    return (mag > 0) ? Vector4::SPACELIKE : Vector4::TIMELIKE;
    return Vector4::LIGHTLIKE;
}
