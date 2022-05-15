cmake_minimum_required(VERSION 2.8.11)

project(MyStackApp C CXX)
     
set (CMAKE_CXX_STANDARD 17)

set(SRC_FILES source/main.cpp)
add_executable(MyStackApp ${SRC_FILES})

target_include_directories(MyStackApp PUBLIC  include)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lrt -lm -g -pipe -Wall -lpthread ")

target_link_libraries(MyStackApp rt pthread)
