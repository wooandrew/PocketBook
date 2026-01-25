// pocketbook - receipt.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <pblib/receipt.hpp>

// stdlib
#include <string>
#include <chrono>
#include <vector>
#include <utility>

// arcxhlib
#include <arcxh/arcxh.hpp>

// pblib
#include <pblib/money.hpp>

namespace pocketbook {

    Receipt::Receipt() {

        vendor = "";
        ymd = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    }

    Receipt::Receipt(const std::string& vendor, const std::chrono::year_month_day ymd) :
        vendor(vendor),
        ymd(ymd),
        subtotal(Money{0, 0}),
        tax(Money{0, 0}),
        tip(Money{0, 0})
    {

    }

    Receipt::~Receipt() {

    };

    int Receipt::addItem(const std::string& item, const Money& cost) {
        items.push_back(std::make_pair(item, cost));
        subtotal += cost;
        return ARCXH_SUCCESS;
    }

    int Receipt::addDiscount(const std::string& discount, const Money& amount) {
        discounts.push_back(std::make_pair(discount, amount));
        subtotal -= amount;
        return ARCXH_SUCCESS;
    }

    int Receipt::setTax(const Money& tax) {
        this->tax = tax;
        return ARCXH_SUCCESS;
    }

    int Receipt::setTip(const Money& tip) {
        this->tip = tip;
        return ARCXH_SUCCESS;
    }

    Money Receipt::getTotal() const {
        return subtotal + tax + tip;
    }

    void Receipt::reset() {

        vendor = "";

        items = std::vector<std::pair<std::string, Money>>();
        discounts = std::vector<std::pair<std::string, Money>>();

        subtotal = Money{0, 0};
        tax = Money{0, 0};
        tip = Money{0, 0};
    }
}
