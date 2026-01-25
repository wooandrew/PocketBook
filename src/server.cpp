// finmanp - server.cpp
// Copyright (c) 2025 - present <> Andrew Woo

// Header
#include "server.hpp"

// stdlib
#include <string>

// extlib
#include <grpcpp/grpcpp.h>

// protolib
#include <proto/server.h>
#include <proto/transaction.h>

// arcxhlib

namespace arcxh::finmanp {

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
