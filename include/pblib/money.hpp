// pblib/money.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef POCKETBOOK_MONEY_HPP
#define POCKETBOOK_MONEY_HPP

// stdlib
#include <string>

// pblib

namespace pocketbook {
    
    class Money {

    public:

        Money();
        Money(int unit, int nano);
        ~Money();

        static std::string MoneyAsString(const Money& m, const int decimals=2);
        static Money StringAsMoney(const std::string& s);

        // Setters
        int setUnit(const int unit);
        int setNano(const int nano);

        // Arithmetic operators
        Money& operator+=(const Money& m);          // Add-equals
        Money operator+(const Money& m) const;      // Addition

        Money& operator-=(const Money& m);          // Sub-equals
        Money operator-(const Money& m) const;      // Subtraction

        Money operator-() const;                    // Unary minus (negation)

        // Comparison operators
        bool operator==(const Money& m) const;
        bool operator!=(const Money& m) const;
        bool operator<(const Money& m) const;
        bool operator<=(const Money& m) const;
        bool operator>(const Money& m) const;
        bool operator>=(const Money& m) const;

    private:
        int unit;       // unit currency
        int nano;       // billionth ; -999,999,999 <> +999,999,999

        void normalize();

        static constexpr int NANO_BASE = 1000000000;
    };
}

#endif // !POCKETBOOK_MONEY_HPP