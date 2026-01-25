// finmanp - receipt.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef ARCXH_FINMANP_RECEIPT
#define ARCXH_FINMANP_RECEIPT

// stdlib
#include <string>
#include <chrono>
#include <vector>
#include <utility>

// arcxhlib
#include <finlib/money.hpp>

namespace arcxh::finmanp {

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

#endif // !ARCXH_FINMANP_RECEIPT