cmake_minimum_required(VERSION 3.28)
project(Main)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(Main
	src/sensor.cpp
    src/main.cpp
	src/sensorapp.cpp
)

add_executable(Benchmark
	src/sensor.cpp
	src/benchmark.cpp
)
