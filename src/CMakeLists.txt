add_executable(TaskManager main.cpp TaskManager.cpp)

target_include_directories(TaskManager PRIVATE ${CMAKE_SOURCE_DIR}/include)

message(${CMAKE_SOURCE_DIR}/include)
