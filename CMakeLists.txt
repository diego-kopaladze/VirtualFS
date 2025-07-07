cmake_minimum_required(VERSION 3.31)
project(FileSystemSimulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileSystemSimulation main.cpp
        FileSystemEntity.cpp
        FileSystemEntity.h
        I_Printable.h
        File.cpp
        File.h
        Directory.cpp
        Directory.h
        SymbolicLink.cpp
        SymbolicLink.h)
