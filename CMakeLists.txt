cmake_minimum_required(VERSION 3.15)

set(namespace "brainstone")
project("mod_math"
    VERSION 0.0.1
    DESCRIPTION "Integer modular arithmetic library"
)

add_library(${PROJECT_NAME} STATIC)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/mod_math.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# without it public headers won't get installed
set(public_headers
    include/mod_math.hpp
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(Installing)

# Testing
add_subdirectory(test)
