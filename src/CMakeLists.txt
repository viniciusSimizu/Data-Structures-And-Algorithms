project(${CMAKE_PROJECT_NAME})

add_library(doubly_linked_list linked_list/doubly_linked_list.c)

target_link_libraries(doubly_linked_list
	PUBLIC
	interface_lib)
