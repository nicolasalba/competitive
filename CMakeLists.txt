cmake_minimum_required(VERSION 3.22)
project(competitive)

set(CMAKE_CXX_STANDARD 11)

set(A main.cpp)
foreach(X IN LISTS A)
    add_executable("${X}" "${X}")
    target_compile_definitions("${X}" PRIVATE NICOLAS=1)
    target_compile_definitions("${X}" PRIVATE DEBUG_NICO=1)
endforeach()
