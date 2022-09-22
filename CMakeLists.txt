cmake_minimum_required (VERSION 3.11)


project ( hooray CXX )

set (CMAKE_CXX_STANDARD 20)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release")
    message (STATUS "Build type not specified: Use Release by default")
endif (NOT CMAKE_BUILD_TYPE)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# executable
add_executable (hooray main.cpp)
#target_include_directories(hooray src)
target_link_libraries(hooray ${SDL2_LIBRARIES})

