# Define a library target for json_lib
# 'json_lib' is the name of the library that will be built
# STATIC means it will be a static library (.a or .lib)
add_library(json_lib STATIC json_lib.cpp)

# Specify include directories for this library
# PUBLIC means that any target linking to json_lib will also get this include directory
# CMAKE_CURRENT_SOURCE_DIR is a CMake variable that points to the current directory
target_include_directories(json_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})