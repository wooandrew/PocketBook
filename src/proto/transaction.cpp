// pocketbook - proto/transaction.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <proto/transaction.hpp>

// stdlib
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// pblib
#include <pblib/money.hpp>

// protolib
#include <proto/common.hpp>

namespace pocketbook::proto {

    grpc::Status TransactionImpl::NewTransaction(grpc::ServerContext* context,
            const ::NewTransactionRequest* request, ::NewTransactionResponse* response) 
    {
        std::string account = request->account();
        ::TransactionType type = request->type();
        ::Money amount = request->amount();

        pocketbook::Money money = pocketbook::Money(amount.units(), amount.nanos());

        std::cout << "[Server] NewTransactionRequest received: " << pocketbook::Money::MoneyAsString(money) << std::endl;

        response->set_status(common::Status::OK);

        return grpc::Status::OK;
    }
}
