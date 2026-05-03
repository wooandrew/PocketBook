# src/CMakeLists.txt

add_subdirectory(arcxh)
add_subdirectory(pblib)
add_subdirectory(proto)

# === Main Server Application === =================================================================
add_executable(pocketbook
    main.cpp
)

# Set output directory
set_target_properties(pocketbook PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Link Libraries
target_link_libraries(pocketbook PRIVATE arcxhlib)
target_link_libraries(pocketbook PRIVATE pblib)
target_link_libraries(pocketbook PRIVATE protolib)
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
target_link_libraries(client PRIVATE pblib)
target_link_libraries(client PRIVATE protolib)
# === =============================================================================================
