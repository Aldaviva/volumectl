cmake_minimum_required(VERSION 3.24)
project(volumectl)

set(CMAKE_CXX_STANDARD 17)

add_executable(volumectl WIN32 main.cpp "icon.rc")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/versioninfo.rc.cmake.in versioninfo.rc @ONLY)
target_sources(volumectl PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/versioninfo.rc")