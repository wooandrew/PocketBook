// finmanp - account.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_ACCOUNT
#define ARCXH_FINMANP_ACCOUNT

// stdlib
#include <string>

// arcxhlib
#include "serialize.hpp"
#include "ledger.hpp"
#include "transaction.hpp"

namespace arcxh::finmanp {

    class Ledger;       // Forward Declaration
    class Transaction;  // Forward Declaration
    
    class Account : 
        public std::enable_shared_from_this<Account>,
        public Serializable
    {

    public:

        Account(const std::string& name);
        Account(const std::string& name, const float balance);    
        ~Account();

        int setName(const std::string& name);
        std::string getName() const;

        int setBalance(const float balance);
        float getBalanceF() const;
        std::string getBalanceS() const;

        int addBalance(const float amount);
        int subBalance(const float amount);

        int newTransaction(const std::shared_ptr<Transaction>& transaction);

    private:

        std::string name;
        float balance;          // TODO: Split into units and nanos ,,, REASON: Avoid floating point arithmetic and errors there related

        std::shared_ptr<Ledger> ledger;
    };
}

#endif // !ARCXH_FINMANP_ACCOUNT
