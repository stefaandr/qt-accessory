set(profile gcc-4.6-c++0x-)
set(USE_CXX11 1)
add_definitions(-std=c++0x)
cmake_force_cxx_compiler(g++-4.6 GNU)
add_subdirectory(../../ work)

