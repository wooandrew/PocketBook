// pblib/receipt.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef POCKETBOOK_RECEIPT_HPP
#define POCKETBOOK_RECEIPT_HPP

// stdlib
#include <string>
#include <chrono>
#include <vector>
#include <utility>

// pblib
#include <pblib/money.hpp>

namespace pocketbook {

    class Receipt {

    public:

        Receipt();
        Receipt(const std::string& vendor, const std::chrono::year_month_day ymd);
        ~Receipt();

        int addItem(const std::string& item, const Money& cost);
        int addDiscount(const std::string& discount, const Money& amount);

        int setTax(const Money& tax);
        int setTip(const Money& tip);

        Money getTotal() const;

    private:

        std::string vendor;

        std::vector<std::pair<std::string, Money>> items;
        std::vector<std::pair<std::string, Money>> discounts;

        Money subtotal;
        Money tax;
        Money tip;

        // Date
        std::chrono::year_month_day ymd;

        // In case of emergencies...
        void reset();
    };
}

#endif // !POCKETBOOK_RECEIPT_HPP