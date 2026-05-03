# root CMakeLists.txt

# Project configuration
cmake_minimum_required(VERSION 3.15)

# Project name and language
project(pocketbook LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Add external directories === ================================================================
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)  # Disable build testing

# Add gRPC
set(ABSL_ENABLE_INSTALL ON CACHE BOOL "" FORCE)                 # Install ABSL (Abseil)
set(ABSL_BUILD_TESTING OFF CACHE BOOL "" FORCE)                 # Disable ABSL build tests
set(gRPC_BUILD_TESTS OFF CACHE BOOL "" FORCE)                   # Disable gRPC build tests
set(gRPC_BUILD_GRPC_CPP_PLUGIN_TARGET ON CACHE BOOL "" FORCE)   # Build grpc_cpp_plugin as target
set(gRPC_INSTALL OFF CACHE BOOL "" FORCE)

set(gRPC_PROTOBUF_PROVIDER  "module" CACHE STRING "" FORCE)
set(gRPC_ABSL_PROVIDER      "module" CACHE STRING "" FORCE)
set(gRPC_ZLIB_PROVIDER      "module" CACHE STRING "" FORCE)
set(gRPC_CARES_PROVIDER     "module" CACHE STRING "" FORCE)
set(gRPC_SSL_PROVIDER       "module" CACHE STRING "" FORCE)

FetchContent_Declare(
    gRPC
    GIT_REPOSITORY https://github.com/grpc/grpc
    GIT_TAG        v1.76.0
)

FetchContent_MakeAvailable(gRPC)
# === =============================================================================================

# === Add Project Files === =======================================================================
add_subdirectory(proto)     # Add the proto sub-directory
add_subdirectory(src)       # Add the src sub-directory
add_subdirectory(test)      # Add the test sub-directory
