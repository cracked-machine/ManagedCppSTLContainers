cmake_minimum_required(VERSION 3.1...3.29)

project(
  managedcontainers
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_compile_options(
  -g 
  -O0 
  -Wall  
  -Wextra 
  --std=gnu++20
  -fsanitize=address
  -fprofile-arcs -ftest-coverage
)

add_link_options(
  -fsanitize=address
  -lgcov --coverage
)

include_directories(${CMAKE_SOURCE_DIR}/inc)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

