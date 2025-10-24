// finmanp - account.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_ACCOUNT
#define ARCXH_FINMANP_ACCOUNT

#include <string>

#include "ledger.hpp"
#include "transaction.hpp"

namespace arcxh::finmanp {

    class Ledger;       // Forward Declaration
    class Transaction;  // Forward Declaration
    
    class Account {

    public:

        Account(const std::string& name);
        Account(const std::string& name, const float balance);    
        ~Account();

        int setName(const std::string& name);

        int setBalance(const float balance);
        float getBalanceF() const;
        std::string getBalanceS() const;

        int addBalance(const float amount);
        int subBalance(const float amount);

        int newTransaction(const std::shared_ptr<Transaction> transaction);

    private:

        std::string name;
        float balance;

        std::shared_ptr<Ledger> ledger;
    };
}

#endif // !ARCXH_FINMANP_ACCOUNT
