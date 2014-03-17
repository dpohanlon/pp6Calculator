#include "pp6Calculator.h"

double evalBFunc(std::string input)
{
    static MyMap::Map<std::string, MyMath::bFunc> * bFuncs = new MyMap::Map<std::string, MyMath::bFunc>();

    MyMap::insert(bFuncs, std::string("add"), MyMath::add);
    MyMap::insert(bFuncs, std::string("subtract"), MyMath::subtract);
    MyMap::insert(bFuncs, std::string("multiply"), MyMath::multiply);
    MyMap::insert(bFuncs, std::string("divide"), MyMath::divide);
    MyMap::insert(bFuncs, std::string("modulo"), MyMath::modulo);
    MyMap::insert(bFuncs, std::string("pow"), MyMath::pow);
    MyMap::insert(bFuncs, std::string("intercept"), MyMath::intercept);

    std::istringstream ss(input);
    std::string tok;

    std::string toks[3] = {""};

    int i = 0;
    while(std::getline(ss, tok, ' ')) {
        if (i > 2) break;
        toks[i] = tok;
        i++;
    }

    MyMath::bFunc f = MyMap::get(bFuncs, toks[0]);

    double output = 0;

    if (f != nullptr) {
        output = f(atof(toks[1].c_str()), atof(toks[2].c_str()));
    }
    else {
        throw Exception::input();
    }

    delete bFuncs;

    return output;
}

void displayMenu(void)
{
    std::cout << "This is PP6 calculator." << std::endl;
    std::cout << std::endl;
    std::cout << "Available binary functions: add, subtract, ";
    std::cout << "multiply, divide, modulo, pow, intercept." << std::endl;
    std::cout << std::endl;
    std::cout << "Q. Quit" << std::endl;
    std::cout << "1. Day One" << std::endl;
    std::cout << "2. Day Two" << std::endl;
    std::cout << "9. Global Thermonuclear War" << std::endl;
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{

    bool loop = true;
    while(loop) {

        displayMenu();

        std::string input;
        std::getline(std::cin, input);

        char c = toupper(input.c_str()[0]);

        switch (c) {
            case 'Q':
                loop = false;
                break;
            case '1':
                DayOneFuncs::menu();
                break;
            case '2':
                DayTwoFuncs::menu();
                break;
            case '9':
                std::cout << "Wouldn't you prefer a good game of chess?" << std::endl;
                break;
            default:
                try {
                    double output = evalBFunc(input);
                    std::cout << "Output: " << output << std::endl;
                }
                catch (Exception::input) {
                    std::cout << "Operation not found!" << std::endl;
                }
                catch (Exception::divByZero) {
                    std::cout << "Division by zero!" << std::endl;
                }
        }
    }

    return 0;
}
