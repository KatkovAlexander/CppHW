cmake_minimum_required(VERSION 3.14)
project(fhw)

set(CMAKE_CXX_STANDARD 17)

set(fhww main.cpp Matrix.h Vector.h Base.h Matrix.cpp Vector.cpp)

add_executable(fhw ${fhww})