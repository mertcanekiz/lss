cmake_minimum_required(VERSION 3.7)
project(lss)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
file(GLOB SOURCES
    "src/*.h"
    "src/*.cpp"
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} SDL2)