# src/CMakeLists.txt

add_executable(finmanp
    main.cpp
    account.cpp
    
    ledger.cpp
    transaction.cpp
    receipt.cpp
)

# Add include directory
target_include_directories(finmanp PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Set output directory
set_target_properties(finmanp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Link Protos
target_link_libraries(finmanp PRIVATE protolib)
