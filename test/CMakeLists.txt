# test/CMakeLists.txt

# === Unit Tests === ==============================================================================
add_executable(unittest
    main.cpp
)

# Set output directory
set_target_properties(unittest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Include include/pblib
target_include_directories(pblib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link Libraries
target_link_libraries(unittest PRIVATE arcxhlib)
target_link_libraries(unittest PRIVATE pblib)
target_link_libraries(unittest PRIVATE protolib)
# === =============================================================================================
