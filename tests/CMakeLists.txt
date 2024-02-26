project(${CMAKE_PROJECT_NAME})

add_executable(doubly_linked_list_test doubly_linked_list_test.c)
add_executable(ring_buffer_test ring_buffer_test.c)

target_link_libraries(doubly_linked_list_test
	PRIVATE
	interface_lib
	doubly_linked_list)

target_link_libraries(ring_buffer_test
	PRIVATE
	interface_lib
	ring_buffer)

add_test(NAME run_doubly_linked_list_test COMMAND doubly_linked_list_test)
add_test(NAME run_ring_buffer_test COMMAND ring_buffer_test)
