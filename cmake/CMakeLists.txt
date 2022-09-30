# Dev note : https://decovar.dev/blog/2021/03/08/cmake-cpp-library/

cmake_minimum_required( VERSION 3.22 )

project(
    "integers"
    DESCRIPTION "A library, which convert a string to an integer."
    VERSION 1.0.0
)

set( CMAKE_CXX_STANDARD 20 )
set( namespace ${PROJECT_NAME} )
set( CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" )
set(
    public_headers
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/integer.hpp
)

add_executable( ${PROJECT_NAME} src/${PROJECT_NAME}/integer.cpp )

add_library( ${PROJECT_NAME} STATIC )
target_sources(
    ${PROJECT_NAME}
    PRIVATE
    src/${PROJECT_NAME}/integer.cpp
)

target_include_directories(
    ${PROJECT_NAME}

    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"

    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/"
)

set( CMAKE_MODULE_PATH "." )
include( install )
