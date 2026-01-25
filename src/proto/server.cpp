// pocketbook - server.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include <proto/server.hpp>

// stdlib
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// pblib

// protolib
#include <proto/service.h>
#include <proto/transaction.h>

namespace pocketbook {

    Server::~Server() {
        server->Shutdown();
    }

    void Server::init() {
        proto::ServerImpl service;
        grpc::ServerBuilder builder;
        builder.AddListeningPort("127.0.0.1:29800", grpc::InsecureServerCredentials());
        builder.RegisterService(&service);

        server = builder.BuildAndStart();
        server->Wait();
    }
}
