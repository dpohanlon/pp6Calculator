#ifndef DAYONEFUNCS_H
#define DAYONEFUNCS_H

#include <cmath>
#include <iostream>

#include "myMath.hpp"

namespace DayOneFuncs
{

// Day One entry point
void menu(void);

// Display the day one menu
void displayMenu(void);

// Solve quadratic, places roots in r1 and r2, returns bool for real roots
bool quadratic(const double a, const double b, const double c,
               double & r1, double & r2);

// Calculates magnitude of three vector
double threeVecMag(double x, double y, double z);

// Calculates magnitude of four vector assuming g = diag(-1, 1, 1, 1)
double fourVecMag(double t, double x, double y, double z);

// Calculates invariant mass of two particles with Pi = (ei, pxi, pyi, pzi)
double invariantMass(double e1, double px1, double py1, double pz1,
                     double e2, double px2, double py2, double pz2);

} // namespace DayOneFuncs

#endif
