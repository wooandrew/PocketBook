// finmanp - ledger.cpp
// Copyright (c) 2025 Andrew Woo

// Header
#include "ledger.hpp"

// stdlib
#include <vector>
#include <memory>

// arcxhlib
#include "arcxh.hpp"

namespace arcxh::finmanp {

    Ledger::Ledger() {

    }

    Ledger::~Ledger() {

    }

    int Ledger::addTransaction(const std::shared_ptr<Transaction>& transaction) {
        transactions.push_back(transaction);
        return ARCXH_SUCCESS;
    }

    int Ledger::addTransaction(const Money& amount, const Transaction::Type type) {

        std::shared_ptr<Transaction> transaction = std::make_shared<Transaction>(type, amount);
        transactions.push_back(transaction);

        return ARCXH_SUCCESS;
    }
}
