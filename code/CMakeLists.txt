cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11 -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -std=c11 -O0")

#Set the binary directory location; all the executable will be there
#   CMAKE_SOURCE_DIR points to the the top level directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

#A common place to put all the libraries
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#Contains the full path to the root of project source directory
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
