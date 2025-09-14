cmake_minimum_required(VERSION 3.10)
project(module_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(module_app
    src/main.cpp
    src/adapters/filesystem.cpp
    src/core/parser.cpp
)
