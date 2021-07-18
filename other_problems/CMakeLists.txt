find_package(pprint CONFIG REQUIRED)

add_executable(topK topK.cpp)
add_executable(bts_2arr bts_2arr.cpp)
add_executable(heapSort heapSort.cpp)
add_executable(fiveGold fiveGold.cpp)

target_link_libraries(topK PRIVATE pprint::pprint)
target_link_libraries(bts_2arr PRIVATE pprint::pprint)