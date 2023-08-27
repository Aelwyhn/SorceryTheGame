cmake_minimum_required(VERSION 3.19.5)
project(sorcery LANGUAGES CXX)

add_executable(sorcery main.cpp Game.cpp TextureManager.cpp GameObject.cpp)
target_include_directories(sorcery PRIVATE ${CMAKE_SOURCE_DIR}/external)
target_link_libraries(sorcery PRIVATE SDL2 SDL2main SDL2_image)

add_custom_command(
    TARGET sorcery POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:sorcery>/assets
)
