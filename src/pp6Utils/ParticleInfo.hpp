#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP

#include <map>

#include "MyFileReader.hpp"

class ParticleInfo
{

public:

    ParticleInfo(std::string fileName);
    ~ParticleInfo(void);

    int getPDGCode(std::string name);

    int getCharge(int pdg);

    std::string getName(int pdg);

    double getMassMeV(int pdg);

    double getMassGeV(int pdg);


private:

    struct ParticleRecord
    {
        std::string name;
        int pdg;
        int charge;
        double mass;
    };

    std::map<std::string, ParticleRecord *> names;
    std::map<int, ParticleRecord *> pdgs;

    ParticleInfo(const ParticleInfo & p);

    inline ParticleInfo & operator=(const ParticleInfo &);

};

#endif