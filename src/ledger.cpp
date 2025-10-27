// finmanp - ledger.cpp
// Copyright (c) 2025 Andrew Woo

#include "ledger.hpp"

#include "arcxh.hpp"

namespace arcxh::finmanp {

    Ledger::Ledger() {

    }

    Ledger::~Ledger() {

    }

    int Ledger::addTransaction(std::shared_ptr<Transaction> transaction) {
        transactions.push_back(transaction);
        return ARCXH_SUCCESS;
    }

    int Ledger::addTransaction(const float amount, const Transaction::Type type) {

        int ret = 0;

        Transaction transaction = Transaction();
        ret = transaction.setAmount(amount);
        ret &= transaction.setType(type);

        return ret;
    }
}
