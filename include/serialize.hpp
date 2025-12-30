// finmanp - serialize.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_SERIALIZE
#define ARCXH_FINMANP_SERIALIZE

namespace arcxh::finmanp {

    class ISerializable {

    public:

    private:
        virtual void serialize() = 0;
    };
}

#endif // !ARCXH_FINMANP_SERIALIZE
