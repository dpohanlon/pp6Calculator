#ifndef DAYFOURFUNCS_H
#define DAYFOURFUNCS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "MyFileReader.hpp"
#include "Vector4.hpp"
#include "Vector3.hpp"
#include "Particle.hpp"
#include "ParticleInfo.hpp"

namespace DayFourFuncs
{

void menu(void);

void displayMenu(void);

void sortVectorThing(void);

void muonAnalysis(std::string pdgFileName, std::string dataFileName);

std::vector<InvariantMassPair> makeInvariantMasses(ParticleInfo & pDB, MyFileReader & dataFile);

std::vector<Particle> readMuons(ParticleInfo & pDB, MyFileReader & dataFile);

Particle makeMuon(int id, int pdg, double mass, double px, double py,  double pz);

}

#endif
