// finmanp - receipt.cpp
// Copyright (c) 2025 Andrew Woo

#include "receipt.hpp"

#include "arcxh.hpp"

namespace arcxh::finmanp {

    Receipt::Receipt() {

        vendor = "";
        ymd = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    }

    Receipt::Receipt(const std::string& vendor, const std::chrono::year_month_day ymd) {

        this->vendor = vendor;
        this->ymd = ymd;

        subtotal = 0.0F;
        tax = 0.0F;
        tip = 0.0F;
    }

    Receipt::~Receipt() {

    };

    int Receipt::addItem(const std::string& item, const float cost) {
        items.push_back(std::make_pair(item, cost));
        subtotal += cost;
        return ARCXH_SUCCESS;
    }

    int Receipt::addDiscount(const std::string& discount, const float amount) {
        discounts.push_back(std::make_pair(discount, amount));
        subtotal -= amount;
        return ARCXH_SUCCESS;
    }

    int Receipt::setTax(const float tax) {
        this->tax = tax;
        return ARCXH_SUCCESS;
    }

    int Receipt::setTip(const float tip) {
        this->tip = tip;
        return ARCXH_SUCCESS;
    }

    float Receipt::getTotal() const {
        return subtotal + tax + tip;
    }

    void Receipt::reset() {

        vendor = "";

        items = std::vector<std::pair<std::string, float>>();
        discounts = std::vector<std::pair<std::string, float>>();

        subtotal = 0.0F;
        tax = 0.0F;
        tip = 0.0F;
    }
}
