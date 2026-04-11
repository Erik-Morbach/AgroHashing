cmake_minimum_required(VERSION 3.31)
project(Main)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_executable(Main
    src/main.cpp
	src/sensor.cpp
	src/sensorapp.cpp
	)