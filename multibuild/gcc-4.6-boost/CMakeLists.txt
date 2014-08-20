set(profile gcc-4.6-boost-)
add_definitions(-DQTPROPERTY_BOOST)
cmake_force_cxx_compiler(g++-4.6 GNU)
add_subdirectory(../.. work)

