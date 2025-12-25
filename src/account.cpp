// finmanp - account.cpp
// Copyright (c) 2025 Andrew Woo

#include "account.hpp"

#include "arcxh.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

namespace arcxh::finmanp {

    Account::Account(const std::string& name) {
        Account(name, 0.F);
    };

    Account::Account(const std::string& name, const float balance) {

        this->name = name;
        this->balance = balance;
        ledger = std::make_shared<Ledger>();
    };

    Account::~Account() {

    };

    int Account::setName(const std::string& name) {
        this->name = name;
        return ARCXH_SUCCESS;
    }
    std::string Account::getName() const {
        return name;
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

    int Account::newTransaction(const std::shared_ptr<Transaction>& transaction) {
        
        int results = ledger->addTransaction(transaction);
        transaction->setAccount(shared_from_this());
        
        if (transaction->getType() == Transaction::Type::deposit)
            addBalance(transaction->getAmount());
        else if (transaction->getType() == Transaction::Type::withdraw)
            subBalance(transaction->getAmount());
        else
            results = ARCXH_FAIL;

        return results;
    }
}
