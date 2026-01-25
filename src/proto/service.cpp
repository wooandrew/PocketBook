// finmanp - proto/server.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <proto/service.h>

// stdlib
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// arcxhlib
    
namespace arcxh::finmanp::proto {

    grpc::Status ServerImpl::Connect(grpc::ServerContext* context,
        const ::ConnectRequest* request, ::ConnectResponse* response)
    {
        std::string ConnectMessage = request->connectmessage();

        std::cout << "[Server] Connection request received: " << ConnectMessage << std::endl;

        response->set_status(::Status::OK);

        return grpc::Status::OK;
    }

    grpc::Status ServerImpl::Disconnect(grpc::ServerContext* context,
        const ::DisconnectRequest* request, ::DisconnectResponse* response)
    {
        std::string DisconnectMessage = request->disconnectmessage();

        std::cout << "[Server] Disconnect request received: " << DisconnectMessage << std::endl;

        response->set_status(::Status::OK);

        return grpc::Status::OK;
    }
}
