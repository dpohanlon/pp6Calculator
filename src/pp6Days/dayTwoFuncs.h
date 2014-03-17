#ifndef DAYTWOFUNCS_H
#define DAYTWOFUNCS_H

#include <cmath>
#include <random>
#include <iostream>

#include "FileReader.hpp"

#include "myMath.hpp"

namespace DayTwoFuncs
{

// Day two entry point
void menu(void);

// Display the day two menu
void displayMenu(void);

// Bubble sort an array, ascending order
void bubbleSort(double * array, int size);

// Swap two locations
void swap(double & a, double & b);

// Sum an array
double sum(const double * array, int size);

// Find the mean of an array
double mean(const double * array, int size);

// Find the population standard deviation of an array
double stdDev(const double * array, int size);

// Square all elements in an array
// (take argument of array to avoid creating on heap)
void square(const double * array, int size, double * out);

// Generates 100 random particle energies and reports stats
void genParticles(void);

// Reads in muons from file and reports stats
// INCOMPLETE
void readMuons(std::string fileName);

} // namespace DayTwoFuncs

#endif
