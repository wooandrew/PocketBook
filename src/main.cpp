// finmanp - an mServArcxh microservice
// Copyright (c) 2025 Andrew Woo

#include <iostream>
#include <sstream>
#include <string>

#include "accounts.hpp"

int main(int argc, char* argv[]) {

    std::cout << ">>> finmanp <<<" << std::endl;

    arcxh::finmanp::Account testAcc("testAcc", 0);

    bool exit = false;

    while (!exit) {

        std::cout << ":$ ";

        std::string input;
        std::getline(std::cin, input);

        if (input == "exit")
            exit = true;
        else if (input == "bal") {
            std::cout << testAcc.getBalance_S() << std::endl;
        }

        std::cout << input << std::endl;
    }

    return 0;
}
