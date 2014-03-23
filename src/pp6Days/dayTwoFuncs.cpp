#include "dayTwoFuncs.h"

void DayTwoFuncs::menu(void)
{
    while(1) {

        DayTwoFuncs::displayMenu();

        std::string input;
        std::getline(std::cin, input);

        char c = toupper(input.c_str()[0]);

        switch (c) {
            case '1':
                std::cout << "Generating 100 random particles..." << std::endl;
                DayTwoFuncs::genParticles();
                break;
            case '2':
                std::cout << "Reading in muons from data file..." << std::endl;
                std::cout << "NOT IMPLEMENTED" << std::endl;
                DayTwoFuncs::readMuons("observedparticles.dat");
                break;
            case 'Q':
                return;
        }
    }
}

void DayTwoFuncs::displayMenu(void)
{
    std::cout << "Day Two Menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Q. Back" << std::endl;
    std::cout << "1. Generate 100 particles" << std::endl;
    std::cout << "2. Read in muons" << std::endl;
    std::cout << std:: endl;
}

void DayTwoFuncs::bubbleSort(double * array, int size)
{
    assert(array && "Null pointer");

    bool done;

    do {
        done = false;
        for (int i = 1; i < size; ++i) {
            if (array[i - 1] > array[i]) {
                DayTwoFuncs::swap(array[i - 1], array[i]);
                done = true;
            }
        }
    } while (done);
}

void DayTwoFuncs::swap(double & a, double & b)
{
    double tmpA = a;
    a = b;
    b = tmpA;
}

double DayTwoFuncs::sum(const double * array, int size)
{
    assert(array && "Null pointer");

    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return sum;
}

double DayTwoFuncs::mean(const double * array, int size)
{
    assert(array && "Null pointer");

    double sum = DayTwoFuncs::sum(array, size);

    return sum / size;
}

double DayTwoFuncs::stdDev(const double * array, int size)
{
    assert(array && "Null pointer");

    double sqArray[size];
    DayTwoFuncs::square(array, size, sqArray);

    double meanSq = DayTwoFuncs::mean(sqArray, size);
    double mean = DayTwoFuncs::mean(array, size);
    double sqMean = pow(mean, 2);

    return sqrt(meanSq - sqMean);
}

void DayTwoFuncs::square(const double * array, int size, double * out)
{
    assert(array && out && "Null pointer");
    
    for (int i = 0; i < size; ++i) {
        out[i] = pow(array[i], 2);
    }
}

void DayTwoFuncs::genParticles(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());

    std::normal_distribution<double> normalPx(100, 10);
    std::normal_distribution<double> normalPy(300, 10);
    std::normal_distribution<double> normalPz(120, 10);
    std::normal_distribution<double> normalM(150, 3);

    double energies[100] = {0};

    for (int i = 0; i < 100; ++i) {
        double px = normalPx(mt);
        double py = normalPy(mt);
        double pz = normalPz(mt);
        double m = normalM(mt);

        double p2 = pow(px, 2) + pow(py, 2) + pow(pz, 2);

        energies[i] = sqrt(p2 + pow(m, 2));
    }

    std::cout << "Mean energy: " << DayTwoFuncs::mean(energies, 100) << std::endl;
    std::cout << "Standard deviation: " << DayTwoFuncs::stdDev(energies, 100) << std::endl;
}

void DayTwoFuncs::readMuons(std::string fileName)
{
    // const double muonMass = 0.10565837; // GeV

    // FileReader f(fileName);

    // if (f.isValid()) {
    //     while (f.nextLine()) {

    //         // Event   Name  p_x p_y p_z Data Source

    //         std::string particle = f.getFieldAsString(2);
    //         std::string source = f.getFieldAsString(6);

    //         if (source == "run4.dat" &&
    //            (particle == "mu+" || particle == "mu-")) {

    //             int pdg = (particle = "mu-") ? 13 : -13;

    //             int id = f.getFieldAsInt(1);
    //             double px = f.getFieldAsFloat(3);
    //             double py = f.getFieldAsFloat(4);
    //             double pz = f.getFieldAsFloat(5);

    //             Vector3

    //         }
    //     }

    // }
}