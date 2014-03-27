#include "ParticleInfo.hpp"

ParticleInfo::ParticleInfo(std::string fileName)
{
    MyFileReader f(fileName);

    if (f.isValid()) {
        while (f.nextLine()) {

            ParticleRecord * r = new ParticleRecord();

            f.getField(1, r->name);
            f.getField(2, r->pdg);
            f.getField(3, r->charge);
            f.getField(4, r->mass);

            names.insert(std::make_pair(r->name, r));
            pdgs.insert(std::make_pair(r->pdg, r));
        }
    }

}

ParticleInfo::~ParticleInfo(void)
{
    for (auto & e : names) {
        delete e.second;
        e.second = nullptr;
    }
}

int ParticleInfo::getPDGCode(std::string name)
{
    return names[name]->pdg;
}

int ParticleInfo::getCharge(int pdg)
{
    return pdgs[pdg]->charge;
}

std::string ParticleInfo::getName(int pdg)
{
    return pdgs[pdg]->name;
}

double ParticleInfo::getMassMeV(int pdg)
{
    return pdgs[pdg]->mass;
}

double ParticleInfo::getMassGeV(int pdg)
{
    return pdgs[pdg]->mass * 0.001;
}
