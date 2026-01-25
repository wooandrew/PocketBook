// proto - server.h
// Copyright (c) 2025 - present <> Andrew Woo

#ifndef PROTO_SERVER_H
#define PROTO_SERVER_H

#include <server.pb.h>
#include <server.grpc.pb.h>

namespace pocketbook::proto {
 
    class ServerImpl final : public ServerProto::Service {

    public:

        grpc::Status Connect(grpc::ServerContext* context,
            const ::ConnectRequest* request, ::ConnectResponse* response) override;

        grpc::Status Disconnect(grpc::ServerContext* context,
            const ::DisconnectRequest* request, ::DisconnectResponse* response) override;

    private:

    };

}

#endif // !PROTO_SERVER_H
