# src/CMakeLists.txt

# === finmanp library === =========================================================================
add_library(finlib STATIC
    common.cpp

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

# === Main Server Application === =================================================================
add_executable(finmanp
    main.cpp
)

# Set output directory
set_target_properties(finmanp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Link Libraries
target_link_libraries(finmanp PRIVATE finlib)
# === =============================================================================================

# === Test Client Application === =================================================================
add_executable(client
    client.cpp
)

# Set output directory
set_target_properties(client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Link Libraries
target_link_libraries(client PRIVATE finlib)
# === =============================================================================================

# === Unit Tests === ==============================================================================
add_executable(unittest
    unit_test.cpp
)

# Set output directory
set_target_properties(unittest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Link Libraries
target_link_libraries(unittest PRIVATE finlib)
