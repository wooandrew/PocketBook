// finmanp - ledger.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_LEDGER
#define ARCXH_FINMANP_LEDGER

#include "transaction.hpp"

#include <vector>

namespace arcxh::finmanp {

    class Ledger {

    public:

        Ledger();
        ~Ledger();

        int addTransaction(const std::shared_ptr<Transaction>& transaction);
        int addTransaction(const float amount, const Transaction::Type type);

    private:

        std::vector<std::shared_ptr<Transaction>> transactions;
    };
}

#endif // !ARCXH_FINMAP_LEDGER
