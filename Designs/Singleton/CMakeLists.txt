cmake_minimum_required(VERSION 2.8.11)

project(SingleTonApp C CXX)
     
set (CMAKE_CXX_STANDARD 17)

set(SRC_FILES  source/main.cpp source/SingleTon.cpp)
add_executable(SingleTonApp ${SRC_FILES})

target_include_directories(SingleTonApp PUBLIC  include)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -lm -g -pipe -Wall ")

target_link_libraries(SingleTonApp )
