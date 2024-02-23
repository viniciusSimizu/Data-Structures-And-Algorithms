cmake_minimum_required(VERSION 3.27.7)
project(fun)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(include)
add_subdirectory(src)

option(TESTS "Should build tests" ON)

if (TESTS)
	enable_testing()
	message(STATUS "Building tests")
	add_subdirectory(tests)
endif()
