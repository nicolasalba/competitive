cmake_minimum_required(VERSION 3.22)
project(competitive)

set(CMAKE_CXX_STANDARD 11) # This could different

set(A main.cpp C.cpp) # Add file names here
foreach(X IN LISTS A)
    add_executable("${X}" "${X}")
    target_compile_definitions("${X}" PRIVATE NICOLAS=1) # add ENV_VAR
    target_compile_definitions("${X}" PRIVATE DEBUG_NICO=1)
endforeach()

