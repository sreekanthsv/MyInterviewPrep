cmake_minimum_required(VERSION 2.8.11)

project(TOP C CXX)
        
set (CMAKE_CXX_STANDARD 17)

set(ESSER_SRC_FILES top.cpp)

  
add_executable(TOP ${ESSER_SRC_FILES})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lrt -lm -g -pipe -Wall -lpthread ")

target_link_libraries(TOP rt pthread )
