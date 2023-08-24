cmake_minimum_required(VERSION 3.19.5)
project(sorcery LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/src)

link_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(sorcery main.cpp Game.cpp)

target_link_libraries(sorcery SDL2 SDL2main SDL2_image)