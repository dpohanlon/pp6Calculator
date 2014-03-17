#ifndef PP6CALCULATOR_H
#define PP6CALCULATOR_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "myMap.hpp"
#include "myMath.hpp"

#include "pp6Days/dayOneFuncs.h"
#include "pp6Days/dayTwoFuncs.h"

// Evaluate binary functions from user input
double evalBFunc(std::string input);

// Display the main menu
void displayMenu(void);

#endif
