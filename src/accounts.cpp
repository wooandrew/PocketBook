// finmanp - accounts.cpp
// Copyright (c) 2025 Andrew Woo

#include "accounts.hpp"

#include <iomanip>
#include <sstream>

constexpr int ARCXH_SUCCESS = 1;

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

    float Account::getBalance_F() const {
        return balance;
    }

    std::string Account::getBalance_S() const {

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

}
