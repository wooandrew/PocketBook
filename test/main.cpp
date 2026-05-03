// pocketbook unit tests
// Copyright (c) 2025 - present <> Andrew Woo

// stdlib
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>

// extlib

// pblib
#include <arcxh/arcxh.hpp>
#include <pblib/account.hpp>

static std::map<std::string, std::function<int()>> ut_registry;
struct TestRegistrar {
    TestRegistrar(std::string name, std::function<int()> func) {
        if (ut_registry.find(name) == ut_registry.end()) {
            ut_registry[name] = func;
        }
    }
};

#define REGISTER_TEST(func) static TestRegistrar global_reg_##func(#func, func)

// --- UNIT TESTS --- MONEY -----------------------------------------------------------------------

// --- --------------------------------------------------------------------------------------------

// --- UNIT TESTS --- ACCOUNT ---------------------------------------------------------------------
pocketbook::Account g_account_generator() {
    return pocketbook::Account("default_account", { 1000, 320000000 });
}

int ut_create_account_default() {
    pocketbook::Account account = g_account_generator();
    return (account.getName() == "default_account") ? ARCXH_SUCCESS : ARCXH_FAIL;
}
REGISTER_TEST(ut_create_account_default);


int ut_create_account_w_balance() {

    pocketbook::Account acc = pocketbook::Account(__func__, { 1000, 320000000 });

    return (acc.getBalanceS() == "1000.32") ? ARCXH_SUCCESS : ARCXH_FAIL;
}
REGISTER_TEST(ut_create_account_w_balance);


int ut_account_get_name() {
    pocketbook::Account account = g_account_generator();
    return (account.getName() == "default_account") ? ARCXH_SUCCESS : ARCXH_FAIL;
}
REGISTER_TEST(ut_account_get_name);


int ut_account_set_name() {

    pocketbook::Account acc = g_account_generator();
    std::string name = "new_name";

    acc.setName(name);

    return (acc.getName() == name) ? ARCXH_SUCCESS : ARCXH_FAIL;
}
REGISTER_TEST(ut_account_set_name);
// --- --------------------------------------------------------------------------------------------

int main() {

    std::cout << "Unit Test Runner Initialized..." << std::endl;
    
    int passed = 0;
    for (auto const& [name, test_func] : ut_registry) {
        std::cout << "[ RUN      ] " << name << std::endl;
        if (test_func() == ARCXH_SUCCESS) {
            std::cout << "[       OK ] " << name << std::endl;
            passed++;
        } else {
            std::cout << "[  FAILED  ] " << name << std::endl;
        }
    }

    std::cout << "\nResults: " << passed << "/" << ut_registry.size() << " passed." << std::endl;
    return 0;
}