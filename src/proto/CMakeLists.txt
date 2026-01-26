# src/proto/CMakeLists.txt

# PROTOLIB
add_library(protolib STATIC
    "server.cpp"
    "service.cpp"
    "transaction.cpp"
)

target_link_libraries(protolib 
    PUBLIC protogen
    PRIVATE pblib
)

target_include_directories(protolib PUBLIC ${PROJECT_SOURCE_DIR}/include)
