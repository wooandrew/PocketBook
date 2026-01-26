// pocketbook - proto/transaction.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef PROTO_TRANSACTION_HPP
#define PROTO_TRANSACTION_HPP

#include <transaction.pb.h>
#include <transaction.grpc.pb.h>

namespace pocketbook::proto {

    class TransactionImpl final : public TransactionProto::Service {

    public:

        grpc::Status NewTransaction(grpc::ServerContext* context,
            const ::NewTransactionRequest* request, ::NewTransactionResponse* response) override;
    };
}

#endif // !PROTO_TRANSACTION_HPP
