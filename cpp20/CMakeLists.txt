find_package(fmt CONFIG REQUIRED)
find_package(pprint CONFIG REQUIRED)
    
# add_executable(hello_cpp20 hello_cpp20.cpp ldc_math.mpp)
add_executable(hello_cpp20 hello_cpp20.cpp)

target_link_libraries(hello_cpp20 PRIVATE fmt::fmt-header-only)
target_link_libraries(hello_cpp20 PRIVATE pprint::pprint)