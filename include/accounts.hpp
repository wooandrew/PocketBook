// finmanp - accounts.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_ACCOUNTS
#define ARCXH_FINMANP_ACCOUNTS

#include <string>

namespace arcxh::finmanp {
    
    class Account {

    public:

        Account(const std::string& name);
        Account(const std::string& name, const float balance);    
        ~Account();

        int setName(const std::string& name);

        int setBalance(const float balance);
        float getBalance_F() const;
        std::string getBalance_S() const;

        int addBalance(const float amount);
        int subBalance(const float amount);

    private:

        std::string name;
        float balance;
    };
}

#endif // !ARCXH_FINMANP_ACCOUNTS
