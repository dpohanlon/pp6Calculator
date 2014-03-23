#include "DayThreeFuncs.h"

void DayThreeFuncs::menu(void)
{
    while(1) {

        DayThreeFuncs::displayMenu();

        std::string input;
        std::getline(std::cin, input);

        char c = toupper(input.c_str()[0]);

        switch (c) {
            case '1':
                // std::cout << "Generating 100 random particles..." << std::endl;
                // DayTwoFuncs::genParticles();
                break;
            case 'Q':
                return;
        }
    }
}

void DayThreeFuncs::displayMenu(void)
{
    std::cout << "Day Three Menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Q. Back" << std::endl;
    std::cout << "1. Generate 100 particles" << std::endl;
    std::cout << std:: endl;
}

void DayThreeFuncs::countMuons(FileReader & f, int & nMuP, int & nMuM)
{

    if (f.isValid()) {
        while (f.nextLine()) {

            std::string particle = f.getFieldAsString(2);
            std::string source = f.getFieldAsString(6);

            if (source == "run4.dat") {
                if (particle == "mu+") {
                    nMuP++;
                } else if (particle == "mu-") {
                    nMuM++;
                }
            }
        }
    }
    f.reset();
}

void DayThreeFuncs::readMuons(std::string fileName)
{

    FileReader f(fileName);

    int nMuP = 0;
    int nMuM = 0;
    countMuons(f, nMuP, nMuM);

    Particle * muP = new Particle[nMuP];
    Particle * muM = new Particle[nMuM];

    if (f.isValid()) {
        int im = 0;
        int ip = 0;

        while (f.nextLine()) {

            // Event Name p_x p_y p_z Data Source

            std::string particle = f.getFieldAsString(2);
            std::string source = f.getFieldAsString(6);

            if (source == "run4.dat" &&
               (particle == "mu+" || particle == "mu-")) {

                int pdg = (particle == "mu-") ? 13 : -13;

                int id = f.getFieldAsInt(1);

                double px = f.getFieldAsFloat(3);
                double py = f.getFieldAsFloat(4);
                double pz = f.getFieldAsFloat(5);

                if (particle == "mu+") {
                    muP[ip++] = DayThreeFuncs::makeMuon(id, pdg, px, py, pz);
                } else if (particle == "mu-") {
                    muM[im++] = DayThreeFuncs::makeMuon(id, pdg, px, py, pz);
                }

            }
        }
    }

    int nPairs = nMuP * nMuM;

    int indices[nPairs];

    for (int i = 0; i < nPairs; ++i) {
        indices[i] = i;
    }

    double masses[nPairs];
    std::string * ids = new std::string[nPairs];

    int i = 0;
    for (int p1 = 0; p1 < nMuP; ++p1) {
        for (int p2 = 0; p2 < nMuM; ++p2) {
            masses[i++] = DayThreeFuncs::invariantMass(muP[p1], muM[p2]);
            std::stringstream sstr;
            sstr << muP[p1].id << " and " << muM[p2].id;
            ids[i++] = sstr.str();

        }
    }

    DayThreeFuncs::bubbleSortWithKey(indices, masses, nPairs);

    std::cout << "Top 10 Invariant Masses:" << std::endl;
    if (nPairs > 10) {
        for (int j = 0; j < 10; ++j) {
            std::cout << ids[indices[j]] << " " << masses[indices[j]] << std::endl;
        }
    }

    delete[] muP;
    delete[] muM;
    delete[] ids;

}

double DayThreeFuncs::invariantMass(const Particle & p1, const Particle & p2)
{
    return (p1.p4 + p2.p4).mag();
}

Particle DayThreeFuncs::makeMuon(int id, int pdg, double px, double py,  double pz)
{
    const double muonMass = 0.10565837; // GeV

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

void DayThreeFuncs::bubbleSortWithKey(int * array, const double * key, int size)
{
    assert(array && key && "Null pointers");

    bool done;

    do {
        done = false;
        for (int i = 1; i < size; ++i) {
            if (key[i - 1] < key[i]) {
                DayThreeFuncs::swap(array[i - 1], array[i]);
                done = true;
            }
        }
    } while (done);
}

void DayThreeFuncs::swap(int & a, int & b)
{
    int tmpA = a;
    a = b;
    b = tmpA;
}
