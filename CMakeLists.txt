cmake_minimum_required(VERSION 3.3)
project(Smart_Pointer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Array.h Array_impl.h IOArray.h IOArray_impl.h Scoped.h Scoped_impl.h Auto.h Auto_impl.h Shared.h Shared_impl.h)
add_executable(Smart_Pointer ${SOURCE_FILES})