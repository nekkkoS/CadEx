cmake_minimum_required(VERSION 3.26)
project(CadEx)

set(CMAKE_CXX_STANDARD 17)

add_executable(CadEx main.cpp
        Inc/Curve3D.h
        Src/Circle.cpp
        Inc/Circle.h
        Src/Ellipse.cpp
        Inc/Ellipse.h
        Src/Helix.cpp
        Inc/Helix.h)
