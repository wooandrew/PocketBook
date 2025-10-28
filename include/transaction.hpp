// finmanp - transaction.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_TRANSACTION
#define ARCXH_FINMANP_TRANSACTION

#include "receipt.hpp"

#include <memory>
#include <string>
#include <chrono>

namespace arcxh::finmanp {

    class Account;      // Forward Declaration

    class Transaction {
      
    public:

        enum class Type {
            deposit,
            withdraw,
            unknown
        };

        static Type typeFromStr(const std::string& str);

        Transaction();
        Transaction(const Type type, const float amount);
        ~Transaction();

        int setReceipt(const std::shared_ptr<Receipt> receipt);

        int setRefID(const std::string ref_id);
        int setVendor(const std::string vendor);
        int setCategory(const std::string category);
        int setDatetime(const std::chrono::year_month_day datetime);
        
        int setAccount(const std::weak_ptr<Account> account);
        std::weak_ptr<Account> getAccount() const;
        
        int setAmount(const float amount);
        float getAmount() const;

        int setType(const Type type);
        Type getType() const;

        int setInternalRef(const std::string internal_ref);

    private:

        std::shared_ptr<Receipt> receipt;
  
        std::string ref_id;
        std::string vendor;
        std::string category;
        std::chrono::year_month_day datetime;
        std::weak_ptr<Account> account;
        float amount;

        Transaction::Type type;
        
        std::string internal_ref;
    };
}

#endif // !ARCXH_FINMANP_TRANSACTION
