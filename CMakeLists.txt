cmake_minimum_required(VERSION 3.8)
project(WinRTSystemHardener)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(WinRTSystemHardener main.cpp src/hardener.cpp)
