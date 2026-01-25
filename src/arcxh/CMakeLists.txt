# src/pocketbook/CMakeLists.txt

add_library(arcxhlib STATIC
    "common.cpp"
)

target_include_directories(arcxhlib PUBLIC ${PROJECT_SOURCE_DIR}/include)
