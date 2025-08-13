// finmanp - transaction.cpp
// Copyright (c) 2025 Andrew Woo

#include "transaction.hpp"

#include "arcxh.hpp"

namespace arcxh::finmanp {

    Transaction::Transaction() {

    }

    Transaction::~Transaction() {

    }

    int Transaction::setReceipt(const std::shared_ptr<Receipt> receipt) {
        this->receipt = receipt;
        return ARCXH_SUCCESS;
    }

    int Transaction::setRefID(const std::string ref_id) {
        this->ref_id = ref_id;
        return ARCXH_SUCCESS;
    }

    int Transaction::setVendor(const std::string vendor) {
        this->vendor = vendor;
        return ARCXH_SUCCESS;
    }

    int Transaction::setCategory(const std::string category) {
        this->category = category;
        return ARCXH_SUCCESS;
    }

    int Transaction::setDatetime(const std::chrono::year_month_day datetime) {
        this->datetime = datetime;
        return ARCXH_SUCCESS;
    }
    int Transaction::setAccount(const std::weak_ptr<Account> payment_method) {
        this->payment_method = payment_method;
        return ARCXH_SUCCESS;
    }
    int Transaction::setAmount(const float amount) {
        this->amount = amount;
        return ARCXH_SUCCESS;
    }

    int Transaction::setInternalRef(const std::string internal_ref) {
        this->internal_ref = internal_ref;
        return ARCXH_SUCCESS;
    }
}
