// proto - server.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef POCKETBOOK_SERVER
#define POCKETBOOK_SERVER

// stdlib
#include <iostream>
#include <memory>

// extlib

// arcxhlib
#include <arcxh/arcxh.hpp>

// pblib

// protolib
#include <proto/service.h>

namespace pocketbook {

    class Server {
    
    public:

        ~Server();

        void init();
        
    private:
        std::unique_ptr<grpc::Server> server;
    };
}

#endif // !POCKETBOOK_SERVER
