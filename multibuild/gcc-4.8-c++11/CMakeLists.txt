set(profile gcc-4.8-c++11-)
set(USE_CXX11 1)
add_definitions(-std=c++11)
cmake_force_cxx_compiler(g++-4.8 GNU)
add_subdirectory(../../ work)

