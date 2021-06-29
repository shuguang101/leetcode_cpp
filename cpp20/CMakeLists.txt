find_package(fmt CONFIG REQUIRED)
find_package(pprint CONFIG REQUIRED)
    
# add_executable(hello_cpp20 hello_cpp20.cpp ldc_math.mpp)
add_executable(hello_cpp20 hello_cpp20.cpp)
add_executable(hello_thread hello_thread.cpp)
add_executable(thread_ref_local_var thread_ref_local_var.cpp)

target_link_libraries(hello_cpp20 PRIVATE fmt::fmt-header-only)
target_link_libraries(hello_cpp20 PRIVATE pprint::pprint)