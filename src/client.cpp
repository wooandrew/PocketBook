// pocketbook - client.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// stdlib
#include <iostream>
#include <memory>
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// protolib
#include <proto/service.hpp>


int main(int argc, char* argv[]) {

    std::string addr = "127.0.0.1:29800";
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(addr, grpc::InsecureChannelCredentials());
    std::unique_ptr<ServiceProto::Stub> mstub = ServiceProto::NewStub(channel);

    grpc::ClientContext ccontext;
    ConnectRequest crequest;
    ConnectResponse cresponse;
    crequest.set_connectmessage("Connect World!");

    grpc::Status status = mstub->Connect(&ccontext, crequest, &cresponse);
    if (status.ok()) {
        std::cout << "Connected successfully!" << std::endl;
    } else {
        std::cout << "Connection failed!" << std::endl;
    }

    grpc::ClientContext dcontext;
    DisconnectRequest drequest;
    DisconnectResponse dresponse;
    drequest.set_disconnectmessage("Disconnect World!");

    status = mstub->Disconnect(&dcontext, drequest, &dresponse);
    if (status.ok()) {
        std::cout << "Disconnected successfully!" << std::endl;
    } else {
        std::cout << "Disconnection failed!" << std::endl;
    }

    return 0;
}
