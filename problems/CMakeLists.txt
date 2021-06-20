find_package(pprint CONFIG REQUIRED)

add_executable(p001_two_sum p001_two_sum.cpp)
add_executable(p015_3Sum p015_3Sum.cpp)
add_executable(p017_phone_number p017_phone_number.cpp)
add_executable(p018_4Sum p018_4Sum.cpp)

target_link_libraries(p015_3Sum PRIVATE pprint::pprint)
target_link_libraries(p017_phone_number PRIVATE pprint::pprint)
target_link_libraries(p018_4Sum PRIVATE pprint::pprint)