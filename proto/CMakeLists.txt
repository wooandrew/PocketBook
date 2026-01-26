# proto/CMakeLists.txt

# Manually include the generation macro from the fetched source
include(${grpc_SOURCE_DIR}/third_party/protobuf/cmake/protobuf-generate.cmake)

# Generate Protobufs
add_library(protogen STATIC "")

target_link_libraries(protogen PUBLIC grpc++ libprotobuf)


set(PROTO_IMPORT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(ALL_PROTOS 
    "common.proto"
    "service.proto"
    "transaction.proto"
)

# Generate Standard Protobuf Code
protobuf_generate(TARGET protogen LANGUAGE cpp 
    IMPORT_DIRS ${PROTO_IMPORT_DIR}
    PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
    PROTOS ${ALL_PROTOS}
)

# Generate gRPC Protobuf Code
protobuf_generate(TARGET protogen LANGUAGE grpc 
    IMPORT_DIRS ${PROTO_IMPORT_DIR} 
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
    PLUGIN "protoc-gen-grpc=$<TARGET_FILE:grpc_cpp_plugin>"
    PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
    PROTOS ${ALL_PROTOS}
)

target_include_directories(protogen PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
