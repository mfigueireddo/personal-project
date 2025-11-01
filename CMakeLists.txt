cmake_minimum_required(VERSION 4.0)
project(personal_project)

set(CMAKE_CXX_STANDARD 26)

add_executable(personal_project
        main.cpp
        common_libraries.h
        File.cpp
        File.h
        Log.cpp
        Log.h
        ObjectDestroyer.cpp
        ObjectDestroyer.h
        Error.h
        Error.cpp
)
