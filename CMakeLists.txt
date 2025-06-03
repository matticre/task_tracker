cmake_minimum_required(VERSION 3.10)
project(TaskTracker VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
# Uncomment if needed:
# find_package(nlohmann_json REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/TaskManager.cpp
)

# Header files
set(HEADERS
    include/TaskManager.h
    include/TaskStructure.h
)

# Create executable
add_executable(TaskTracker ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(TaskTracker PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Install rules
install(TARGETS TaskTracker
    RUNTIME DESTINATION bin
)

include(CPack)