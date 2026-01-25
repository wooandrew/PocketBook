// pocketbook - client.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// stdlib
#include <iostream>
#include <memory>
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// protolib
#include <proto/service.h>


int main(int argc, char* argv[]) {

    std::string addr = "127.0.0.1:29800";
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(addr, grpc::InsecureChannelCredentials());
    std::unique_ptr<ServerProto::Stub> mstub = ServerProto::NewStub(channel);

    ConnectRequest request;
    ConnectResponse response;

    request.set_connectmessage("Hello World!");

    grpc::ClientContext context;
    grpc::Status status = mstub->Connect(&context, request, &response);

    if (status.ok()) {
        std::cout << "Connected successfully!" << std::endl;
    } else {
        std::cout << "Connection failed!" << std::endl;
    }

    return 0;
}
