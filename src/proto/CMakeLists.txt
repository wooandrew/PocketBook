# PROTOLIB
add_library(protolib STATIC
    "proto/server.cpp"      "proto/server.h"
    # "proto/transaction.cpp" "proto/transaction.h"
)

target_link_libraries(protolib PUBLIC protogen)
