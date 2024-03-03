# CMake minimum version required
cmake_minimum_required(VERSION 3.12)

# Project name
project(AsaphusCodingProject)

# Set C++ standard (e.g., C++14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files
set(SOURCES
    asaphus_coding_challenge.cpp
    )

# Add an executable target
add_executable(challenge ${SOURCES})

# Link against Catch2
target_include_directories(challenge PRIVATE external_headers)


