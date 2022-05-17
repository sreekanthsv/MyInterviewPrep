cmake_minimum_required(VERSION 2.8.11)

project(MyQueueApp C CXX)
     
set (CMAKE_CXX_STANDARD 17)

set(SRC_FILES source/main.cpp)
add_executable(MyQueueApp ${SRC_FILES})

target_include_directories(MyQueueApp PUBLIC  include)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lrt -lm -g -pipe -Wall")

target_link_libraries(MyQueueApp )
