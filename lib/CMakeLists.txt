project(${CMAKE_PROJECT_NAME})

add_library(doubly_linked_list list/doubly_linked_list.c)
add_library(ring_buffer list/ring_buffer.c)

target_link_libraries(doubly_linked_list
	PUBLIC
	interface_lib)

target_link_libraries(ring_buffer
	PUBLIC
	interface_lib)
