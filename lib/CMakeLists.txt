add_library(doubly_linked_list doubly_linked_list.c)
add_library(ring_buffer ring_buffer.c)
add_library(min_heap min_heap.c)
add_library(quicksort quicksort.c)

target_include_directories(doubly_linked_list PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(min_heap PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(quicksort PUBLIC ${CMAKE_CURRENT_LIST_DIR})
