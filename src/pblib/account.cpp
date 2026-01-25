// pocketbook - account.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <pblib/account.hpp>

// stdlib
#include <iostream>
#include <iomanip>
#include <sstream>

// arxchlib
#include <arcxh/arcxh.hpp>

namespace pocketbook {

    Account::Account(const std::string& name) : Account(name, Money{0, 0}) { };

    Account::Account(const std::string& name, const Money&balance) :
        name(name),
        balance(balance),
        ledger(std::make_shared<Ledger>())
    {

    };

    Account::~Account() {

    };

    void Account::serialize() {

    }

    int Account::setName(const std::string& name) {
        this->name = name;
        return ARCXH_SUCCESS;
    }
    std::string Account::getName() const {
        return name;
    }

    int Account::setBalance(const Money& balance) {
        this->balance = balance;
        return ARCXH_SUCCESS;
    }

    Money Account::getBalance() const {
        return balance;
    }

    std::string Account::getBalanceS() const {
        return Money::MoneyAsString(balance);
    }

    int Account::addBalance(const Money& amount) {
        balance += amount;
        return ARCXH_SUCCESS;
    }

    int Account::subBalance(const Money& amount) {
        balance -= amount;
        return ARCXH_SUCCESS;
    }

    int Account::newTransaction(const std::shared_ptr<Transaction>& transaction) {
        
        int results = ledger->addTransaction(transaction);
        transaction->setAccount(shared_from_this());
        
        if (transaction->getType() == Transaction::Type::deposit) {
            addBalance(transaction->getAmount());
        }
        else if (transaction->getType() == Transaction::Type::withdraw) {
            subBalance(transaction->getAmount());
        }
        else {
            results = ARCXH_FAIL;
        }

        return results;
    }
}
