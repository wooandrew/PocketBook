# src/proto/CMakeLists.txt

# PROTOLIB
add_library(protolib STATIC
    "service.cpp"
    "server.cpp"
    # "proto/transaction.cpp" "proto/transaction.h"
)

target_link_libraries(protolib 
    PUBLIC protogen
    PRIVATE pblib
)

target_include_directories(protolib PUBLIC ${PROJECT_SOURCE_DIR}/include)
