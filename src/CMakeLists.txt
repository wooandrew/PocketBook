# src/CMakeLists.txt

add_subdirectory(arcxh)
add_subdirectory(finlib)
add_subdirectory(proto)

# === Main Server Application === =================================================================
add_executable(finmanp
    main.cpp
)

# Set output directory
set_target_properties(finmanp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Link Libraries
target_link_libraries(finmanp PRIVATE arcxhlib)
target_link_libraries(finmanp PRIVATE finlib)
target_link_libraries(finmanp PRIVATE protolib)
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
target_link_libraries(client PRIVATE protolib)
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
target_link_libraries(unittest PRIVATE arcxhlib)
target_link_libraries(unittest PRIVATE finlib)
target_link_libraries(unittest PRIVATE protolib)
