// pocketbook - serialize.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <pblib/serialize.hpp>

// stdlib
#include <iostream>
#include <iomanip>
#include <sstream>

// arxchlib
#include <arcxh/arcxh.hpp>

namespace pocketbook {

    void ISerializable::save() {
        if (isDirty) {
            serialize();
        }
        else {
            std::cout << "No need to save, isDirty == false." << std::endl;
        }

        isDirty = false;
    }

}
