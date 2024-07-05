cmake_minimum_required(VERSION 3.14)
project(MyProject)
# 添加第一个目标
add_executable(main main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")