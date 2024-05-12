cmake_minimum_required(VERSION 3.27.7)
project(fun)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(DEBUG "Build on debug mode" OFF)
if(DEBUG)
	set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(lib)

enable_testing()
add_subdirectory(test)
