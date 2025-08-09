// finmanp - transaction.hpp
// Copyright (c) 2025 Andrew Woo

#ifndef ARCXH_FINMANP_TRANSACTION
#define ARCXH_FINMANP_TRANSACTION

#include "receipt.hpp"

#include <memory>

namespace arcxh::finmanp {

    class Transaction 
        : public std::enable_shared_from_this<Transaction> {
      
    public:

        Transaction();
        ~Transaction();

        int setPrev(const std::shared_ptr<Transaction> prev);
        int setNext(const std::shared_ptr<Transaction> next);

    private:

        Receipt receipt;
        
        std::weak_ptr<Transaction> prev;
        std::shared_ptr<Transaction> next;
    };
}

#endif // !ARCXH_FINMANP_TRANSACTION
