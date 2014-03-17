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
