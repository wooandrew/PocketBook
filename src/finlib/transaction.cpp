// finmanp - transaction.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <finlib/transaction.hpp>

// stdlib
#include <string>
#include <chrono>

// arcxhlib
#include <arcxh/arcxh.hpp>
#include <finlib/money.hpp>

namespace arcxh::finmanp {

    Transaction::Type Transaction::typeFromStr(const std::string& str) {

        Transaction::Type type = Transaction::Type::deposit;

        if (str == "w" || str == "withdraw"){
            type = Transaction::Type::withdraw;
        }
        else if (str != "d" && str != "deposit") {
            type = Transaction::Type::unknown;
        }

        return type;
    }

    Transaction::Transaction() {

    }

    Transaction::Transaction(const Type type, const Money& amount) :
        type(type),
        amount(amount)
    {
    
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
    
    int Transaction::setAccount(const std::weak_ptr<Account> account) {
        this->account = account;
        return ARCXH_SUCCESS;
    }
    std::weak_ptr<Account> Transaction::getAccount() const {
        return account;
    }

    int Transaction::setAmount(const Money& amount) {
        this->amount = amount;
        return ARCXH_SUCCESS;
    }
    Money Transaction::getAmount() const {
        return amount;
    }

    int Transaction::setType(const Transaction::Type type) {
        this->type = type;
        return ARCXH_SUCCESS;
    }
    Transaction::Type Transaction::getType() const {
        return type;
    }

    int Transaction::setInternalRef(const std::string internal_ref) {
        this->internal_ref = internal_ref;
        return ARCXH_SUCCESS;
    }
}
