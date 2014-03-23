#ifndef DAYTHREEFUNCS_H
#define DAYTHREEFUNCS_H

#include <iostream>
#include <cmath>
#include <cassert>
#include <sstream>

#include "Vector4.hpp"
#include "Vector3.hpp"
#include "Particle.hpp"

#include "dayOneFuncs.h"
#include "dayTwoFuncs.h"

namespace DayThreeFuncs
{

// Entry point into day three functions
void menu(void);

// Display day three menu
void displayMenu(void);

void countMuons(FileReader & f, int & nMuP, int & nMuM);

void readMuons(std::string fileName);

double invariantMass(const Particle & p1, const Particle & p2);

Particle makeMuon(int id, int pdg, double px, double py,  double pz);

void bubbleSortWithKey(int * array, const double * key, int size);

void swap(int & a, int & b);

} // DayThreeFuncs

#endif
