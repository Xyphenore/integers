cmake_minimum_required( VERSION 3.22 )

project(
        "integers"
        DESCRIPTION "A library, which convert a string to an integer."
        VERSION 1.0.0
)

set( CMAKE_CXX_STANDARD 20 )

add_executable( ${PROJECT_NAME} tests/main.cpp src/${PROJECT_NAME}/integer.cpp )
