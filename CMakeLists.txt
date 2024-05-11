cmake_minimum_required(VERSION 3.27.7)
project(fun)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(DEBUG "Build on debug mode" OFF)
if(DEBUG)
	set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(lib)

option(TEST "Should build tests" ON)
if(TEST)
	enable_testing()
	message(STATUS "Building tests")
	add_subdirectory(test)
endif()
