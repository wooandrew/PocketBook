// finmanp - money.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_MONEY
#define ARCXH_FINMANP_MONEY

// stdlib
#include <string>

// arcxhlib

namespace arcxh::finmanp {
    
    class Money {

    public:
        
        Money(int unit, int nano);
        ~Money();

        static std::string MoneyAsString(const Money& m, const int decimals=2);

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

#endif // !ARCXH_FINMANP_MONEY