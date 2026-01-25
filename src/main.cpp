// finmanp - an mServArcxh microservice
// Copyright (c) 2025 - present <> Andrew Woo

// stdlib
#include <iostream>

// extlib
#include <grpcpp/grpcpp.h>

// protolib
#include <proto/server.h>
#include <proto/transaction.h>

// arcxhlib
#include "server.hpp"

int main(int argc, char* argv[]) {

    std::cout << "Started FINMANP Server" << std::endl;

    arcxh::finmanp::Server server;
    server.init();

    return 0;
}
