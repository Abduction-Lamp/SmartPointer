cmake_minimum_required(VERSION 3.3)
project(Smart_Pointer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Array.cpp Array.h IOArray.cpp IOArray.h Scoped.cpp Scoped.h Auto.cpp Auto.h Shared.cpp Shared.h)
add_executable(Smart_Pointer ${SOURCE_FILES})