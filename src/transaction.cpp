// finmanp - transaction.cpp
// Copyright (c) 2025 Andrew Woo

#include "transaction.hpp"

#include "arcxh.hpp"

namespace arcxh::finmanp {

    Transaction::Transaction() {
        prev.reset();
        next.reset();
    }

    Transaction::~Transaction() {

    }

    int Transaction::setPrev(const std::shared_ptr<Transaction> prev) {
        this->prev = prev;
        return ARCXH_SUCCESS;
    }

    int Transaction::setNext(const std::shared_ptr<Transaction> next) {
        this->next = next;
        if (next)
            next->setPrev(shared_from_this());
            
        return ARCXH_SUCCESS;
    }
}
