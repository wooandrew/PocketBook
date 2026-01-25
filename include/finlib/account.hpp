// finmanp - account.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef ARCXH_FINMANP_ACCOUNT
#define ARCXH_FINMANP_ACCOUNT

// stdlib
#include <string>

// arcxhlib
#include <finlib/money.hpp>
#include <finlib/ledger.hpp>
#include <finlib/serialize.hpp>
#include <finlib/transaction.hpp>

namespace arcxh::finmanp {

    class Ledger;       // Forward Declaration
    class Transaction;  // Forward Declaration
    
    class Account : 
        public std::enable_shared_from_this<Account>,
        public ISerializable
    {

    public:

        Account(const std::string& name);
        Account(const std::string& name, const Money& balance);    
        ~Account();

        int setName(const std::string& name);
        std::string getName() const;

        int setBalance(const Money& balance);
        Money getBalance() const;
        std::string getBalanceS() const;

        int addBalance(const Money& amount);
        int subBalance(const Money& amount);

        int newTransaction(const std::shared_ptr<Transaction>& transaction);

    private:

        std::string name;
        Money balance;

        std::shared_ptr<Ledger> ledger;

        void serialize() override;
    };
}

#endif // !ARCXH_FINMANP_ACCOUNT
