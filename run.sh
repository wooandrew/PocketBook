#!/bin/bash

BUILD_DIR=build
EXECUTABLE=myapp

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
  all)
    clean
    configure
    build
    run
    ;;
  *)
    echo "Usage: $0 {clean|build|run|all}"
    exit 1
    ;;
esac
