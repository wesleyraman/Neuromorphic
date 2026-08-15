cmake_minimum_required(VERSION 3.18)
project(SpikeCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  add_compile_options(/02 /W4)
else()
  add_compile_options(-03 -Wall -Wextra -march=native)
endif()

include_directories(include)
add_executable(spike_core src/main.cpp)
