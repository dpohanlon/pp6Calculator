#include "dayFourFuncs.h"

void DayFourFuncs::menu(void)
{

}

void DayFourFuncs::displayMenu(void)
{

}

void DayFourFuncs::sortVectorThing(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<> uniform(0, 100);

    std::vector<int> vecOfTen(10);

    for (int i = 0; i < 10; ++i) vecOfTen[i] = uniform(mt);

    std::copy(vecOfTen.begin(), vecOfTen.end(), std::ostream_iterator<int>(std::cout, "\n"));

    std::sort(vecOfTen.begin(), vecOfTen.end());

    std::cout << "Min: " << vecOfTen.front() << std::endl;
    std::cout << "Max: " << vecOfTen.back() << std::endl;
    std::cout << "Sorted: " << std::endl;

    std::copy(vecOfTen.begin(), vecOfTen.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

struct DayFourFuncs::DayFourFuncs::InvariantMassPair
{
    int id1;
    int id2;
    double invariantMass;
};

std::ostream& operator<<(std::ostream & stream, const DayFourFuncs::InvariantMassPair & p)
{
    stream << "Pair: " << p.id1 << " " << p.id2 << std::endl;
    stream << "Invariant Mass: " << p.invariantMass << std::endl;
    std::endl;

    return stream;
}

void DayFourFuncs::muonAnalysis(std::string pdgFileName, std::string dataFileName)
{
    ParticleInfo pDB(pdgFileName);

    MyFileReader dataFile(dataFileName);

    std::vector<DayFourFuncs::InvariantMassPair> invariantMasses = makeInvariantMasses(readMuons(pDB, dataFile));

    std::sort(invariantMasses.begin(), invariantMasses.end(),
        [](DayFour::DayFourFuncs::InvariantMassPair & a, DayFour::DayFourFuncs::InvariantMassPair & b)
        {
            // Sort in descending order by invariant mass
            return a.invariantMass > b.invariantMass;
        });

    std::copy(invariantMasses.begin(), invariantMasses.end(), std::ostream_iterator<DayFourFuncs::InvariantMassPair>(std::cout, "\n"));
}

std::vector<Particle> DayFourFuncs::readMuons(ParticleInfo & pDB, MyFileReader & dataFile)
{
    std::vector<Particle> muons;

    if (dataFile.isValid()) {

        while (dataFile.nextLine()) {

            // Event Name p_x p_y p_z Data Source

            std::string particle = dataFile.getFieldAsString(2);
            std::string source = dataFile.getFieldAsString(6);

            if (particle == "mu+" || particle == "mu-") {

                int id = f.getFieldAsInt(1);
                int pdg = pDB.getPDGCode(particle);

                double mass = pDB.getMassMeV(pdg);

                double px = f.getFieldAsFloat(3);
                double py = f.getFieldAsFloat(4);
                double pz = f.getFieldAsFloat(5);

                muons.push_back(DayFourFuncs::makeMuon(id, pdg, mass, px, py, pz));
            }
        }
    }

    return muons;
}

Particle DayFourFuncs::makeMuon(int id, int pdg, double mass, double px, double py,  double pz)
{

    Vector3 p3 = Vector3(px, py, pz);

    double e = sqrt( pow(muonMass, 2) + pow(p3.mag(), 2));

    Vector4 p4 = Vector4(e, p3.getX(), p3.getY(), p3.getZ());

    Particle mu = Particle();

    mu.id = id;
    mu.pdg = pdg;
    mu.mass = muonMass;
    mu.p3 = p3;
    mu.p4 = p4;

    return mu;
}

std::vector<DayFourFuncs::InvariantMassPair> DayFourFuncs::makeInvariantMasses(std::vector<Particle> & particles)
{
    std::vector<DayFourFuncs::InvariantMassPair> pairs;

    for (auto & p1 : muons) {
        for (auto & p2 : muons) {
            if (p1 != p2) {
                DayFourFuncs::InvariantMassPair im;

                im.id1 = p1.id;
                im.id2 = p2.id;
                im.invariantMass = (p1.p4 + p2.p4).mag();

                pairs.push_back(im);
            }
        }
    }

    return pairs;
}
