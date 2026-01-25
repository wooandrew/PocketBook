// pblib/serialize.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef POCKETBOOK_SERIALIZE_HPP
#define POCKETBOOK_SERIALIZE_HPP

namespace pocketbook {

    class ISerializable {

    public:

    private:
        virtual void serialize() = 0;
    };
}

#endif // !POCKETBOOK_SERIALIZE_HPP
