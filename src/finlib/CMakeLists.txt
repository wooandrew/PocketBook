# src/finlib/CMakeLists.txt

add_library(finlib STATIC
    account.cpp
    ledger.cpp
    money.cpp
    receipt.cpp
    transaction.cpp
)

target_include_directories(finlib PUBLIC ${PROJECT_SOURCE_DIR}/include)
