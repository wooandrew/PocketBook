// finmanp - money.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include "money.hpp"

// stdlib
#include <iostream>
#include <format>
#include <string>

// arcxhlib
#include "arcxh.hpp"
#include "common.hpp"


namespace arcxh::finmanp {

    Money::Money() : Money(0, 0) { }

    Money::Money(int unit, int nano) : 
        unit(unit), 
        nano(nano) 
    {
        normalize();
    }

    Money::~Money() {}

    std::string Money::MoneyAsString(const Money& m, const int decimals) {

        std::string isNegative = (m.unit < 0 || m.nano < 0) ? "-" : "";
        
        // Use unsigned to avoid LLONG_MIN overflow
        unsigned long long absUnit = (m.unit < 0) ? -static_cast<unsigned long long>(m.unit) : m.unit;
        unsigned long long absNano = (m.nano < 0) ? -static_cast<unsigned long long>(m.nano) : m.nano;

        // Scale without floating point ; 10^9 is the base for nanos
        long long divisor = 1;
        for (int i = 0; i < (9 - decimals); ++i) {
            divisor *= 10;
        }

        return std::format("{}{}.{:0{}}", isNegative, absUnit, absNano / divisor, decimals);
    }

    Money Money::StringAsMoney(const std::string& s) {

        std::vector<std::string> tokens = tokenize(s, '.');

        Money m;
        m.setUnit(std::stoi(tokens[0]));

        long long divisor = 1;
        for (int i = 0; i < tokens[1].size(); ++i) {
            divisor *= 10;
        }

        m.setNano(std::stoi(tokens[1]) * (NANO_BASE / divisor));
        std::cout << m.nano << std::endl;

        return m;
    }

    int Money::setUnit(const int unit) {
        this->unit = unit;
        return ARCXH_SUCCESS;
    }

    int Money::setNano(const int nano) {
        this->nano = nano;
        return ARCXH_SUCCESS;
    }

    void Money::normalize() {
    
        unit += nano / NANO_BASE;
        nano %= NANO_BASE;

        // Fix mixed-sign cases
        if (unit > 0 && nano < 0) {
            nano += NANO_BASE;
            --unit;
        }
        else if (unit < 0 && nano > 0) {
            nano -= NANO_BASE;
            ++unit;
        }
    }

    // Arithmetic Operators
    Money& Money::operator+=(const Money& m) {

        unit += m.unit;
        nano += m.nano;
        normalize();

        return *this;
    }

    Money Money::operator+(const Money& m) const {

        Money ret = *this;
        ret += m;

        return ret;
    }

    Money& Money::operator-=(const Money& m) {

        unit -= m.unit;
        nano -= m.nano;
        normalize();

        return *this;
    }

    Money Money::operator-(const Money& m) const {

        Money result = *this;
        result -= m;

        return result;
    }

    Money Money::operator-() const {
        return Money{-unit, -nano};
    }

    // Comparison operators
    bool Money::operator==(const Money& m) const {
        return unit == m.unit && nano == m.nano;
    }

    bool Money::operator!=(const Money& m) const {
        return !(*this == m);
    }

    bool Money::operator<(const Money& m) const {
        if (unit != m.unit) return unit < m.unit;
        return nano < m.nano;
    }

    bool Money::operator<=(const Money& m) const {
        return !(*this > m);
    }

    bool Money::operator>(const Money& m) const {
        return m < *this;
    }

    bool Money::operator>=(const Money& m) const {
        return !(*this < m);
    }
}
