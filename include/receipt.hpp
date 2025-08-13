// finmanp - receipt.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_RECEIPT
#define ARCXH_FINMANP_RECEIPT

#include <string>
#include <chrono>
#include <vector>
#include <utility>

namespace arcxh::finmanp {

    class Receipt {

    public:

        Receipt();
        Receipt(const std::string& vendor, const std::chrono::year_month_day ymd);
        ~Receipt();

        int addItem(const std::string& item, const float cost);
        int addDiscount(const std::string& discount, const float amount);

        int setTax(const float tax);
        int setTip(const float tip);

        float getTotal() const;

    private:

        std::string vendor;

        std::vector<std::pair<std::string, float>> items;
        std::vector<std::pair<std::string, float>> discounts;

        float subtotal;
        float tax;
        float tip;

        // Date
        std::chrono::year_month_day ymd;

        // In case of emergencies...
        void reset();
    };
}

#endif // !ARCXH_FINMANP_RECEIPT