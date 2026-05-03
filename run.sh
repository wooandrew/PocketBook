#!/bin/bash

BUILD_DIR=build
EXECUTABLE=myapp
TESTS=test

function clean() {
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
}

function configure() {
    echo "Configuring project..."
    cmake -S . -B "$BUILD_DIR"
}

function build() {
    echo "Building project..."
    cmake --build "$BUILD_DIR"
}

function run() {
    echo "Running executable..."
    ./"$BUILD_DIR"/"$EXECUTABLE"
}

function test() {
    echo "Running unit tests..."
    ./"$BUILD_DIR"/"$TESTS"
}

case "$1" in
    clean)
        clean
        ;;
    build)
        configure
        build
        ;;
    run)
        run
        ;;
    test)
        test
        ;;
    all)
        clean
        configure
        build
        test
        run
        ;;
    *)
        echo "Usage: $0 {clean|build|test|run|all}"
        exit 1
        ;;
esac
