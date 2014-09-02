# Test multiple build configurations with a single CMake build
# Don't know whether CMake was intended to be used this way though ;-)

cmake_minimum_required(VERSION 2.8)

include(CMakeForceCompiler)

project(QtProperty-multibuild)

add_subdirectory(gcc-4.6-boost)
add_subdirectory(gcc-4.6-c++0x)
add_subdirectory(gcc-4.8-c++11)
add_subdirectory(gcc-4.9-c++14)

