// finmanp - server.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef ARCXH_FINMANP_SERVER
#define ARCXH_FINMANP_SERVER

// stdlib
#include <iostream>
#include <memory>

// extlib

// protolib
#include <proto/service.h>

// arcxhlib
#include <arcxh/arcxh.hpp>


namespace arcxh::finmanp {

    class Server {
    
    public:

        ~Server();

        void init();
        
    private:
        std::unique_ptr<grpc::Server> server;
    };
}

#endif // !ARCXH_FINMANP_SERVER
