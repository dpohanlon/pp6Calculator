#include "dayOneFuncs.h"

void DayOneFuncs::menu(void)
{
    while(1) {

        DayOneFuncs::displayMenu();

        std::string input;
        std::getline(std::cin, input);

        char c = toupper(input.c_str()[0]);

        switch (c) {
            case '1':
                std::cout << "Enter A B C" << std::endl;
                break;
            case '2':
                std::cout << "Enter x y x" << std::endl;
                break;
            case '3':
                std::cout << "Enter t x y z" << std::endl;
                break;
            case '4':
                std::cout << "Enter E_1 PX_1 PY_1 PZ_1" << std::endl;
                std::cout << "Enter E_1 PX_1 PY_1 PZ_1" << std::endl;
                break;
            case 'Q':
                return;
        }
    }

}

void DayOneFuncs::displayMenu(void)
{
    std::cout << "Day One Menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Q. Back" << std::endl;
    std::cout << "M. Display this menu" << std::endl;
    std::cout << "1. Solve quadratic" << std::endl;
    std::cout << "2. Find 3-vector magnitude" << std::endl;
    std::cout << "3. Find 4-vector magnitude" << std::endl;
    std::cout << "4. Find invariant mass" << std::endl;
}

bool DayOneFuncs::quadratic(const double a, const double b, const double c,
               double & r1, double & r2)
{
    // Return false if no real roots

    double disc = pow(b, 2) - 4 * a * c;
    if (disc < 0) return false;

    // Provides increased numerical stability when b ~= sqrt(b^2 - 4 a c)

    double q = (b < 0) ? -0.5 * (b - sqrt(disc)) : -0.5 * (b + sqrt(disc));

    r1 = q / a;
    r2 = c / q;

    return true;
}

double DayOneFuncs::threeVecMag(double x, double y, double z)
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(x, 2));
}

double DayOneFuncs::fourVecMag(double t, double x, double y, double z)
{
    // Assuming g = diag(-1, 1, 1, 1)

    double sqrtArg = pow(t, 2) - (pow(x, 2) + pow(y, 2) + pow(z, 2));

    if (sqrtArg < 0) throw(Exception::noRealRoots());
    else return sqrt(sqrtArg);
}

double DayOneFuncs::invariantMass(double e1, double px1, double py1, double pz1,
                     double e2, double px2, double py2, double pz2)
{
    return fourVecMag(e1 + e2, px1 + px2, py1 + py2, pz1 + pz2);
}
