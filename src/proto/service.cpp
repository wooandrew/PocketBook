// pocketbook - proto/server.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <proto/service.hpp>

// stdlib
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// pblib
#include <proto/common.hpp>
    
namespace pocketbook::proto {

    grpc::Status ServiceImpl::Connect(grpc::ServerContext* context,
        const ::ConnectRequest* request, ::ConnectResponse* response)
    {
        std::string ConnectMessage = request->connectmessage();

        std::cout << "[Server] ConnectRequest received: " << ConnectMessage << std::endl;

        response->set_status(common::Status::OK);

        return grpc::Status::OK;
    }

    grpc::Status ServiceImpl::Disconnect(grpc::ServerContext* context,
        const ::DisconnectRequest* request, ::DisconnectResponse* response)
    {
        std::string DisconnectMessage = request->disconnectmessage();

        std::cout << "[Server] DisconnectRequest received: " << DisconnectMessage << std::endl;

        response->set_status(common::Status::OK);

        return grpc::Status::OK;
    }
}
