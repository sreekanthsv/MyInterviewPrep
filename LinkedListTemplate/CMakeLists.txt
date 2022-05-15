cmake_minimum_required(VERSION 2.8.11)

project(MyLinkListApp C CXX)
     
set (CMAKE_CXX_STANDARD 17)

set(SRC_FILES source/main.cpp)
add_executable(MyLinkListApp ${SRC_FILES})

target_include_directories(MyLinkListApp PUBLIC  include)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -lm -g -pipe -Wall ")

target_link_libraries(MyLinkListApp )
