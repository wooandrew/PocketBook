// pblib/ledger.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef POCKETBOOK_LEDGER_HPP
#define POCKETBOOK_LEDGER_HPP

// stdlib
#include <vector>
#include <memory>

// pblib
#include <pblib/money.hpp>
#include <pblib/transaction.hpp>

namespace pocketbook {

    class Ledger {

    public:

        Ledger();
        ~Ledger();

        int addTransaction(const std::shared_ptr<Transaction>& transaction);
        int addTransaction(const Money& amount, const Transaction::Type type);

    private:

        std::vector<std::shared_ptr<Transaction>> transactions;
    };
}

#endif // !ARCXH_FINMAP_LEDGER_HPP
