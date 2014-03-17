#ifndef DAYTHREEFUNCS_H
#define DAYTHREEFUNCS_H

#include <iostream>
#include <cmath>

#include "Vector4.hpp"
#include "dayOneFuncs.h"

namespace DayThreeFuncs
{

// Entry point into day three functions
void menu(void);

// Display day three menu
void displayMenu(void);

// Returns 4-vector boosted by v
Vector4::Vector4 * boostZ(double t, double x, double y, double z, double v);

// Fills provided 4-vector boosted by v, returns true on success
bool boostZ(const Vector4::Vector4 & vec, double v, Vector4::Vector4 & vecPrime);

// Returns magnitude of 4-vector
double fourVecMag(const Vector4::Vector4 & vec);

// Returns causal type of interval described by 4-vector
Vector4::causalType interval(const Vector4::Vector4 & vec);

} // DayThreeFuncs

#endif
