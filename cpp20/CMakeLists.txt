find_package(fmt CONFIG REQUIRED)
find_package(pprint CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)    

# add_executable(hello_cpp20 hello_cpp20.cpp ldc_math.mpp)
add_executable(hello_cpp20 hello_cpp20.cpp)
add_executable(hello_thread hello_thread.cpp)
add_executable(thread_ref_local_var thread_ref_local_var.cpp)
add_executable(vector_range_constructor vector_range_constructor.cpp)

target_link_libraries(hello_cpp20 PRIVATE fmt::fmt-header-only)
target_link_libraries(hello_cpp20 PRIVATE pprint::pprint)
target_link_libraries(vector_range_constructor PRIVATE pprint::pprint)
# Note: 2 target(s) were omitted.
target_link_libraries(vector_range_constructor PRIVATE range-v3 range-v3-meta range-v3::meta range-v3-concepts)