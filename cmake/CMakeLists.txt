# --------------------------------------------------------------------------------
# Integers - Safe conversion from a string to integer.
# Copyright (C) 2022 Xyphenore
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
# --------------------------------------------------------------------------------

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
