// pocketbook - an mServArcxh microservice
// Copyright (c) 2025 - present <> Andrew Woo

// stdlib
#include <iostream>

// extlib
#include <grpcpp/grpcpp.h>

// arcxhlib

// pblib

// protolib
#include <proto/service.hpp>
#include <proto/server.hpp>
#include <proto/transaction.hpp>

int main(int argc, char* argv[]) {

    std::cout << "Started POCKETBOOK Server" << std::endl;

    pocketbook::Server server;
    server.init();

    return 0;
}
