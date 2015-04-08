cmake_minimum_required(VERSION 3.1)
project(game1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp)
add_executable(game1 ${SOURCE_FILES} src/Texture.cpp src/Texture.h src/Coordinates.cpp src/Coordinates.h src/Player.cpp src/Player.h)
target_link_libraries(game1 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})