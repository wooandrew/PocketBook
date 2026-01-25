// pocketbook - test.cpp
// Copyright (c) 2025 - present <> Andrew Woo

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

// arcxhlib
#include <arcxh/common.hpp>

// pblib
#include <pblib/money.hpp>
#include <pblib/account.hpp>
#include <pblib/transaction.hpp>

// protolib
#include <proto/service.hpp>
#include <proto/transaction.hpp>

int main(int argc, char* argv[]) {

    std::cout << ">>> pocketbook <<<" << std::endl;

    pocketbook::Money m1(2, 750000000);
    pocketbook::Money m2(3, 250000000);
    pocketbook::Money m3 = m1 + m2;
    pocketbook::Money m4 = pocketbook::Money::StringAsMoney("2.751");

    std::cout << pocketbook::Money::MoneyAsString(m3) << std::endl;
    std::cout << pocketbook::Money::MoneyAsString(m4, 3) << std::endl;

    std::map<std::string, std::shared_ptr<pocketbook::Account>> accounts;
    accounts["Savings"] = std::make_shared<pocketbook::Account>("Savings", pocketbook::Money{0, 0});
    accounts["Checking"] = std::make_shared<pocketbook::Account>("Checking", pocketbook::Money{0, 0});

    std::shared_ptr<pocketbook::Account> activeAccount = accounts["Savings"];

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
            std::map<std::string, std::shared_ptr<pocketbook::Account>>::iterator it = accounts.find(tokens[1]);
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
            activeAccount->setBalance(pocketbook::Money{std::stoi(balParts[0]), std::stoi(balParts[1]) * 10000000});
        }
        else if (cmd == "new-transaction") {

            if (tokens.size() != 3) {
                std::cerr << "\tUsage: new-transaction [TYPE] [AMOUNT]" << std::endl;
                continue;
            }

            pocketbook::Transaction::Type type = pocketbook::Transaction::typeFromStr(tokens[1]);
            if (type != pocketbook::Transaction::Type::unknown) {
                std::vector<std::string> transactionParts = tokenize(tokens[2], '.');
                std::shared_ptr<pocketbook::Transaction> transaction = std::make_shared<pocketbook::Transaction>(type, pocketbook::Money{std::stoi(transactionParts[0]), std::stoi(transactionParts[1]) * 10000000});
                activeAccount->newTransaction(transaction);
            }
            else {
                std::cerr << "Unknown transaction type [" << tokens[1] << "]" << std::endl;
            }
        }
    }

    return 0;
}
