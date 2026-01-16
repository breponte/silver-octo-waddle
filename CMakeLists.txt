cmake_minimum_required(VERSION 3.23)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
    Please don't run CMake in the source folder.

    Delete 'CMakeCache.txt' if it was created,
    then run CMake in a separate 'build' folder.

    If you're in the build folder and still see this,
    delete any 'CMakeCache.txt' files outside the build folder.
    ")
endif()

project(SilverOctoWaddle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dependencies/sdl EXCLUDE_FROM_ALL)

add_subdirectory(src/server)
