// finmanp - account.cpp
// Copyright (c) 2025 Andrew Woo

#include "account.hpp"

#include "arcxh.hpp"

#include <iomanip>
#include <sstream>

namespace arcxh::finmanp {

    Account::Account(const std::string& name) {

        this->name = name;
        this->balance = 0.0F;
    };

    Account::Account(const std::string& name, const float balance) {

        this->name = name;
        this->balance = balance;
    };

    Account::~Account() {

    };

    int Account::setName(const std::string& name) {

        this->name = name;
        return ARCXH_SUCCESS;
    }

    int Account::setBalance(const float balance) {
        this->balance = balance;
        return ARCXH_SUCCESS;
    }

    float Account::getBalanceF() const {
        return balance;
    }

    std::string Account::getBalanceS() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << balance;
        return oss.str();
    }

    int Account::addBalance(const float amount) {
        balance += amount;
        return ARCXH_SUCCESS;
    }

    int Account::subBalance(const float amount) {
        balance -= amount;
        return ARCXH_SUCCESS;
    }

    int Account::newTransaction(const std::shared_ptr<Transaction> transaction) {
        int results = ledger->addTransaction(transaction);
        return results;
    }
}
