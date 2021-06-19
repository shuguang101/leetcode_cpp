cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(leetcode_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

# c++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# 编译器
set(CMAKE_C_COMPILER "/usr/local/Cellar/gcc/11.1.0_1/bin/gcc-11")
set(CMAKE_CXX_COMPILER "/usr/local/Cellar/gcc/11.1.0_1/bin/g++-11")
# vcpkg路径
set(CMAKE_TOOLCHAIN_FILE "/usr/local/Cellar/vcpkg/2021.05.12/libexec/scripts/buildsystems/vcpkg.cmake")

# 编译标志
add_compile_options(-fmodules-ts)

# 子目录
add_subdirectory(cpp20)
add_subdirectory(problems)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
