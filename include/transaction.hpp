// finmanp - transaction.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_TRANSACTION
#define ARCXH_FINMANP_TRANSACTION

#include "receipt.hpp"
#include "account.hpp"

#include <memory>
#include <string>
#include <chrono>

namespace arcxh::finmanp {

    class Transaction {
      
    public:

        Transaction();
        ~Transaction();

        int setReceipt(const std::shared_ptr<Receipt> receipt);

        int setRefID(const std::string ref_id);
        int setVendor(const std::string vendor);
        int setCategory(const std::string category);
        int setDatetime(const std::chrono::year_month_day datetime);
        int setAccount(const std::weak_ptr<Account> payment_method);
        int setAmount(const float amount);

        int setInternalRef(const std::string internal_ref);

    private:

        std::shared_ptr<Receipt> receipt;
  
        std::string ref_id;
        std::string vendor;
        std::string category;
        std::chrono::year_month_day datetime;
        std::weak_ptr<Account> payment_method;
        float amount;
        
        std::string internal_ref;
    };
}

#endif // !ARCXH_FINMANP_TRANSACTION
