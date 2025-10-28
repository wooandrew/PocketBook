// finmanp - an mServArcxh microservice
// Copyright (c) 2025 Andrew Woo

#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "account.hpp"
#include "transaction.hpp"

int main(int argc, char* argv[]) {

    std::cout << ">>> finmanp <<<" << std::endl;

    std::shared_ptr<arcxh::finmanp::Account> testAcc = std::make_shared<arcxh::finmanp::Account>("testAcc", 0.f);


    bool exit = false;

    while (!exit) {

        std::cout << ":$ ";

        std::string input;
        std::getline(std::cin, input);

        if (input == "exit")
            exit = true;
        else if (input == "bal") {
            std::cout << testAcc->getBalanceS() << std::endl;
        }
        else if (input == "new-transaction") {

            arcxh::finmanp::Transaction transaction;
            std::shared_ptr<arcxh::finmanp::Transaction> __t = std::make_shared<arcxh::finmanp::Transaction>();

            __t->setAccount(testAcc);
        }

        std::cout << input << std::endl;
    }

    return 0;
}
