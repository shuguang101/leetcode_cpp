find_package(pprint CONFIG REQUIRED)

add_executable(p001_two_sum p001_two_sum.cpp)
add_executable(p015_3Sum p015_3Sum.cpp)

target_link_libraries(p015_3Sum PRIVATE pprint::pprint)