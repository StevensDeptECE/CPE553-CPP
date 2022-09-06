cmake_minimum_required (VERSION 3.6)
project (banking)
set(CMAKE_CXX_STANDARD 11)

set(MY_SOURCE src/Main.cpp src/Account.cpp)
add_executable(banking ${MY_SOURCE})
