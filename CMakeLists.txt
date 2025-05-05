# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(MyJsonProject CXX)

# Add the json_lib subdirectory
# This will process the CMakeLists.txt file inside json_lib
add_subdirectory(json_lib)

# Add the main executable
# 'my_app' is the name of the executable that will be created
add_executable(my_app main.cpp)

# Link the executable to the json_lib library
# This tells the compiler where to find the functions declared in json_lib.h
# and defined in json_lib.cpp
target_link_libraries(my_app PRIVATE json_lib)