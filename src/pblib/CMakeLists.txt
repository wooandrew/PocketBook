# src/pblib/CMakeLists.txt

add_library(pblib STATIC
    account.cpp
    ledger.cpp
    money.cpp
    receipt.cpp
    transaction.cpp
    serialize.cpp
)

target_include_directories(pblib PUBLIC ${PROJECT_SOURCE_DIR}/include)
