add_executable(finmanp
    main.cpp
)

# Add include directory
target_include_directories(finmanp PRIVATE ${PROJECT_SOURCE_DIR}/include)

set_target_properties(finmanp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
