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

Vector4::Vector4 * DayThreeFuncs::boostZ(double t, double x, double y, double z, double v)
{
    double beta = v; // units where c == 1
    double gamma = sqrt(1 - pow(beta, 2));

    double tPrime = gamma * (t - beta * z);
    double xPrime = x;
    double yPrime = y;
    double zPrime = gamma * (z - beta * t);

    return Vector4::createVector4(tPrime, xPrime, yPrime, zPrime);
}

bool DayThreeFuncs::boostZ(const Vector4::Vector4 & vec, double v, Vector4::Vector4 & vecPrime)
{
    double beta = v; // units where c == 1
    double gamma = sqrt(1 - pow(beta, 2));

    Vector4::setT(vecPrime, gamma * (Vector4::getT(vec) - beta * Vector4::getZ(vec)));
    Vector4::setX(vecPrime, Vector4::getX(vec));
    Vector4::setY(vecPrime, Vector4::getY(vec));
    Vector4::setZ(vecPrime, gamma * (Vector4::getZ(vec) - beta * Vector4::getT(vec)));

    return true;
}

double DayThreeFuncs::fourVecMag(const Vector4::Vector4 & vec)
{
    double sqrtArg = pow(Vector4::getT(vec), 2) - (pow(Vector4::getX(vec), 2) +
                     pow(Vector4::getY(vec), 2) + pow(Vector4::getZ(vec), 2));

    if (sqrtArg < 0) throw(Exception::noRealRoots());
    else return sqrt(sqrtArg);
}

Vector4::causalType DayThreeFuncs::interval(const Vector4::Vector4 & vec)
{
    double mag = DayThreeFuncs::fourVecMag(vec);

    return (mag > 0) ? Vector4::SPACELIKE : Vector4::TIMELIKE;
    return Vector4::LIGHTLIKE;
}
