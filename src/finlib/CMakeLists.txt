# === finmanp library === =========================================================================
add_library(finlib STATIC
    account.cpp
    ledger.cpp
    money.cpp
    receipt.cpp
    transaction.cpp
    server.cpp
)

target_include_directories(finlib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(finlib PUBLIC ${PROJECT_SOURCE_DIR}/proto)

target_link_libraries(finlib PUBLIC protolib)
# === =============================================================================================
