// finmanp - common.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include "common.hpp"

// stdlib
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& input, const char delimiter) {

    std::vector<std::string> tokens;
    std::string token;

    std::istringstream iss(input);
    while (std::getline(iss, token, delimiter))
        tokens.push_back(token);

    return tokens;
}
