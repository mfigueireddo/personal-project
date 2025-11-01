cmake_minimum_required(VERSION 4.0)
project(personal_project)

set(CMAKE_CXX_STANDARD 26)

add_executable(personal_project
        # src
        src/main.cpp
        src/common_std_libraries.h

        # Managers
        src/Managers/File.cpp
        src/Managers/File.h
        src/Managers/Log.cpp
        src/Managers/Log.h
        src/Managers/ObjectDestroyer.cpp
        src/Managers/ObjectDestroyer.h
        src/Managers/Error.h
        src/Managers/Error.cpp
        src/common_project_libraries.h
)
