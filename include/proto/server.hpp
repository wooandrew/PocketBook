// proto/server.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef POCKETBOOK_SERVER_HPP
#define POCKETBOOK_SERVER_HPP

// stdlib
#include <iostream>
#include <memory>

// extlib

// arcxhlib
#include <arcxh/arcxh.hpp>

// pblib

// protolib
#include <proto/service.hpp>

namespace pocketbook {

    class Server {
    
    public:

        void init();
        void shutdown();
        
    private:
        std::unique_ptr<grpc::Server> server;
    };
}

#endif // !POCKETBOOK_SERVER_HPP
