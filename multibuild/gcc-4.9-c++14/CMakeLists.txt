set(profile gcc-4.9-c++14-)
set(USE_CXX11 1)
add_definitions(-std=c++14 -DQTPROPERTY_VARIADIC)
cmake_force_cxx_compiler(g++-4.9 GNU)
add_subdirectory(../../ work)

