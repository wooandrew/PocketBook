// finmanp - ledger.cpp
// Copyright (c) 2025 Andrew Woo

#include "ledger.hpp"

#include "arcxh.hpp"

namespace arcxh::finmanp {

    Ledger::Ledger() {

    }

    Ledger::~Ledger() {

    }

    int Ledger::addTransaction(std::weak_ptr<Transaction> transaction) {
        transactions.push_back(transaction);
        return ARCXH_SUCCESS;
    }
}
