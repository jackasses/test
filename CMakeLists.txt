cmake_minimum_required(VERSION 3.5)
project(grilll_projekt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp max31865.h max31865.cpp L6470.h L6470.cpp ads1220.h ads1220.cpp IOcontroll.h IOcontroll.cpp)
add_executable(grilll_projekt ${SOURCE_FILES})