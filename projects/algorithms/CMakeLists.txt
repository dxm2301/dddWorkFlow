cmake_minimum_required(VERSION 3.10)
project(Algorithms)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置可执行文件输出目录 - 移到这里，在添加子目录之前
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加包含目录
include_directories(${CMAKE_SOURCE_DIR}/utils)

# 添加子目录
add_subdirectory(sorting)
add_subdirectory(linked_list)
add_subdirectory(binary_tree)
add_subdirectory(dynamic_programming)
add_subdirectory(graph)
add_subdirectory(string)