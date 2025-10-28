// finmanp - an mServArcxh microservice
// Copyright (c) 2025 Andrew Woo

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

#include "account.hpp"
#include "transaction.hpp"

std::vector<std::string> tokenize(const std::string& input, const char delimiter) {

    std::vector<std::string> tokens;
    std::string token;

    std::istringstream iss(input);
    while (std::getline(iss, token, delimiter))
        tokens.push_back(token);

    return tokens;
}

int main(int argc, char* argv[]) {

    std::cout << ">>> finmanp <<<" << std::endl;

    std::shared_ptr<arcxh::finmanp::Account> testAcc = std::make_shared<arcxh::finmanp::Account>("testAcc", 0.f);


    bool exit = false;

    while (!exit) {

        std::cout << ":$ ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> tokens = tokenize(input, ' ');
        std::string cmd = tokens[0];

        if (cmd == "exit")
            exit = true;
        else if (cmd == "bal") {
            std::cout << testAcc->getBalanceS() << std::endl;
        }
        else if (cmd == "set-bal") {
            float bal = std::stof(tokens[1]);
            testAcc->setBalance(bal);
        }
        else if (cmd == "new-transaction") {

            if (tokens.size() != 3) {
                std::cerr << "\tUsage: new-transaction [TYPE] [AMOUNT]" << std::endl;
                continue;
            }

            arcxh::finmanp::Transaction::Type type = arcxh::finmanp::Transaction::typeFromStr(tokens[1]);
            if (type != arcxh::finmanp::Transaction::Type::unknown) {

                std::shared_ptr<arcxh::finmanp::Transaction> transaction = std::make_shared<arcxh::finmanp::Transaction>(type, std::stof(tokens[2]));
                transaction->setAccount(testAcc);
                testAcc->newTransaction(transaction);
            }
            else {
                std::cerr << "Unknown transaction type [" << tokens[1] << "]" << std::endl;
            }
        }
    }

    return 0;
}
