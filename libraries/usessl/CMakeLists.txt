cmake_minimum_required(VERSION 3.9)
project(usessl)

set(CMAKE_CXX_STANDARD 11)
find_library(SSL openssl)

add_executable(usessl main.cpp)
target_link_libraries(usessl crypto ssl)