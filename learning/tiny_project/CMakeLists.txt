cmake_minimum_required(VERSION 3.20)
project(Module1 LANGUAGES CXX)

# Require modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable (src/main.cpp is the entry point)
add_executable(module1 src/main.cpp)

# If you have headers in include/, make them visible
target_include_directories(module1 PRIVATE include)