// finmanp - an mServArcxh microservice
// Copyright (c) 2025 Andrew Woo

// stdlib
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <ranges>
#include <memory>
#include <map>

// extlib
#include <grpcpp/grpcpp.h>

// protolib
#include <proto/transaction.h>

// arcxhlib
#include "money.hpp"
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

    arcxh::finmanp::Money m1(2, 750000000);
    arcxh::finmanp::Money m2(3, 250000000);
    arcxh::finmanp::Money m3 = m1 + m2;

    std::cout << arcxh::finmanp::Money::MoneyAsString(m3) << std::endl;

    std::map<std::string, std::shared_ptr<arcxh::finmanp::Account>> accounts;
    accounts["Savings"] = std::make_shared<arcxh::finmanp::Account>("Savings", arcxh::finmanp::Money{0, 0});
    accounts["Checking"] = std::make_shared<arcxh::finmanp::Account>("Checking", arcxh::finmanp::Money{0, 0});

    std::shared_ptr<arcxh::finmanp::Account> activeAccount = accounts["Savings"];

    bool exit = false;

    while (!exit) {

        std::cout << ":$ ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> tokens = tokenize(input, ' ');
        std::string cmd = tokens[0];

        if (cmd == "exit")
            exit = true;
        else if (cmd == "list-acc") {
            for (const auto& key : accounts | std::views::keys) {
                std::cout << '\t' << key << std::endl;
            }
        }
        else if (cmd == "use-acc") {
            std::map<std::string, std::shared_ptr<arcxh::finmanp::Account>>::iterator it = accounts.find(tokens[1]);
            if (it == accounts.end()) {
                std::cout << "Error: Unknown Account specified";
                continue;
            }
            
            activeAccount = it->second;
        }
        else if (cmd == "which-acc") {
            std::cout << activeAccount->getName() << std::endl;
        }
        else if (cmd == "bal") {
            std::cout << activeAccount->getBalanceS() << std::endl;
        }
        else if (cmd == "set-bal") {
            std::vector<std::string> balParts = tokenize(tokens[1], '.');
            activeAccount->setBalance(arcxh::finmanp::Money{std::stoi(balParts[0]), std::stoi(balParts[1]) * 10000000});
        }
        else if (cmd == "new-transaction") {

            if (tokens.size() != 3) {
                std::cerr << "\tUsage: new-transaction [TYPE] [AMOUNT]" << std::endl;
                continue;
            }

            arcxh::finmanp::Transaction::Type type = arcxh::finmanp::Transaction::typeFromStr(tokens[1]);
            if (type != arcxh::finmanp::Transaction::Type::unknown) {
                std::vector<std::string> transactionParts = tokenize(tokens[2], '.');
                std::shared_ptr<arcxh::finmanp::Transaction> transaction = std::make_shared<arcxh::finmanp::Transaction>(type, arcxh::finmanp::Money{std::stoi(transactionParts[0]), std::stoi(transactionParts[1]) * 10000000});
                activeAccount->newTransaction(transaction);
            }
            else {
                std::cerr << "Unknown transaction type [" << tokens[1] << "]" << std::endl;
            }
        }
    }

    return 0;
}
