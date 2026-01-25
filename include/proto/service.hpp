// proto/service.hpp
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef PROTO_SERVICE_HPP
#define PROTO_SERVICE_HPP

#include <service.pb.h>
#include <service.grpc.pb.h>

namespace pocketbook::proto {
 
    class ServiceImpl final : public ServiceProto::Service {

    public:

        grpc::Status Connect(grpc::ServerContext* context,
            const ::ConnectRequest* request, ::ConnectResponse* response) override;

        grpc::Status Disconnect(grpc::ServerContext* context,
            const ::DisconnectRequest* request, ::DisconnectResponse* response) override;

    private:

    };

}

#endif // !PROTO_SERVICE_HPP
