cmake_minimum_required(VERSION 2.8.11)

project(isPrimeApp C CXX)
     
set (CMAKE_CXX_STANDARD 17)

set(SRC_FILES  main.cpp ../../source/MyAlgorithm.cpp)
add_executable(isPrimeApp ${SRC_FILES})

target_include_directories(isPrimeApp PUBLIC  ../../include)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -lm -g -pipe -Wall ")

target_link_libraries(isPrimeApp )
