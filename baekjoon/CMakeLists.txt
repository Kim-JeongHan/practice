cmake_minimum_required(VERSION 3.5)
project(baekjoon)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(BOJ1406
              code/BOJ1406.cpp)
 
add_executable(BOJ1148
              code/BOJ1148.cpp)

add_executable(BOJ10828
              code/BOJ10828.cpp)

add_executable(BOJ10845
              code/BOJ10845.cpp)

add_executable(BOJ10866
              code/BOJ10866.cpp)

add_executable(BOJ4949
              code/BOJ4949.cpp)

add_executable(BOJ10799
              code/BOJ10799.cpp)
add_executable(BOJ2504
              code/BOJ2504.cpp)