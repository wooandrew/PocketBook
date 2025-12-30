# proto/CMakeLists.txt

# Manually include the generation macro from the fetched source
include(${grpc_SOURCE_DIR}/third_party/protobuf/cmake/protobuf-generate.cmake)

add_library(protolib STATIC
    transaction.proto
)

target_link_libraries(protolib PUBLIC
    grpc++
    libprotobuf
)

# Generate Standard Protobuf Code
protobuf_generate(
    TARGET protolib
    LANGUAGE cpp
    PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
)

# Generate gRPC Protobuf Code
protobuf_generate(
    TARGET protolib
    LANGUAGE grpc
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
    PLUGIN "protoc-gen-grpc=$<TARGET_FILE:grpc_cpp_plugin>"
    PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
)

target_include_directories(protolib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
