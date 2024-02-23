project(${CMAKE_PROJECT_NAME})

add_executable(tests doubly_linked_list_test.c)

target_link_libraries(tests
	PRIVATE
	interface_lib
	doubly_linked_list)

add_test(NAME run_tests COMMAND tests)
