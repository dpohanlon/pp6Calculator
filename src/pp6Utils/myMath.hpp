#ifndef MYMATH_H
#define MYMATH_H

#include <cmath>

namespace Exception {

struct input { };
struct divByZero { };
struct noRealRoots { };

} // namespace Exception

namespace MyMath {

inline double add(double a, double b) { return a + b; }
inline double subtract(double a, double b) { return a - b; }
inline double multiply(double a, double b) { return a * b; }
inline double pow(double a, double b) { return pow(a, b); }
inline double divide(double a, double b)
{ 
    if (b == 0) throw Exception::divByZero();
    return a / b;
}

inline double modulo(double a, double b)
{
    if (b == 0) throw Exception::divByZero();
    return int(a) % int(b);
}

inline double intercept(double m, double c) { return divide(-c, m); }

typedef double (*bFunc)(double, double);

} // namespace MyMath

#endif