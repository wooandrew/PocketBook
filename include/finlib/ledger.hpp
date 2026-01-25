// finmanp - ledger.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef ARCXH_FINMANP_LEDGER
#define ARCXH_FINMANP_LEDGER

// stdlib
#include <vector>
#include <memory>

// arcxhlib
#include <finlib/money.hpp>
#include <finlib/transaction.hpp>

namespace arcxh::finmanp {

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

#endif // !ARCXH_FINMAP_LEDGER
