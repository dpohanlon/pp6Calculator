#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vector3
{
public:

    Vector3(void) : m_x(0), m_y(0), m_z(0) { }
    Vector3(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    double mag(void) const
    {
        double sqrtArg = pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2);

        if (sqrtArg < 0) throw(Exception::noRealRoots());
        else return sqrt(sqrtArg);
    }

    double getX(void) const { return m_x; }
    double getY(void) const { return m_y; }
    double getZ(void) const { return m_z; }

    void setX(double val) { m_x = val; }
    void setY(double val) { m_y = val; }
    void setZ(double val) { m_z = val; }

    Vector3 & operator += (const Vector3 & v) { m_x += v.getX(); m_y += v.getY(); m_z += v.getZ(); return *this; }
    Vector3 & operator -= (const Vector3 & v) { m_x -= v.getX(); m_y -= v.getY(); m_z -= v.getZ(); return *this; }
    Vector3 & operator *= (const Vector3 & v) { m_x *= v.getX(); m_y *= v.getY(); m_z *= v.getZ(); return *this; }
    Vector3 & operator /= (const Vector3 & v) { m_x /= v.getX(); m_y /= v.getY(); m_z /= v.getZ(); return *this; }

    Vector3 operator - (void) const { return Vector3(-m_x, -m_y, -m_z); }

private:

    double m_x;
    double m_y;
    double m_z;

};

inline Vector3 operator + (const Vector3 & v, const double c) { return Vector3(v.getX() + c, v.getY() + c, v.getZ() + c); }
inline Vector3 operator - (const Vector3 & v, const double c) { return Vector3(v.getX() - c, v.getY() - c, v.getZ() - c); }

inline Vector3 operator + (const double c, const Vector3 & v) { return Vector3(c + v.getX(), c + v.getY(), c + v.getZ()); }
inline Vector3 operator - (const double c, const Vector3 & v) { return Vector3(c - v.getX(), c - v.getY(), c - v.getZ()); }

inline Vector3 operator + (const Vector3 & v1, const Vector3 & v2) { return Vector3(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getY() + v2.getY()); }
inline Vector3 operator - (const Vector3 & v1, const Vector3 & v2) { return v1 + (-v2); }

inline std::ostream& operator<<(std::ostream & stream, const Vector3 & v)
{
    stream << "[ ";
    stream << v.getX() << " ";
    stream << v.getY() << " ";
    stream << v.getZ();
    stream << " ]";

    return stream;
}

inline std::istream& operator>>(std::istream & stream, Vector3 & v)
{
    double x = 0;
    double y = 0;
    double z = 0;

    stream >> x >> y >> z;

    v.setX(x);
    v.setY(y);
    v.setZ(z);

    return stream;
}

#endif
