#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector4.hpp"
#include "Vector3.hpp"

class Particle
{
public:

    Particle(void) : pdg(), r3(), r4(), p3(), p4() { }
    Particle(int id_, int pdg_, double mass_, Vector3 r3_, Vector3 p3_, Vector4 r4_, Vector4 p4_)
        : id(id_), pdg(pdg_), mass(mass_), r3(r3_), r4(r4_), p3(p3_), p4(p4_) { }

    // All or nothing - abiguity between (r,p)(3,4)

    int id;

    int pdg;
    double mass;

    Vector3 r3;
    Vector4 r4;

    Vector3 p3;
    Vector4 p4;

};

#endif
