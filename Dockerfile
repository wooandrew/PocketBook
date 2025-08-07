FROM ubuntu:24.04

# Install build tools and CMake
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        cmake \
        git \
        && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source files
COPY . .

# Create build directory and configure
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Build the project
RUN cmake --build build --config Release

# Default command (optional)
CMD ["./bin/finmanp"]
