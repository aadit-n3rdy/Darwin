cmake_minimum_required(VERSION 3.10)

set(proj_name Darwin)
project(${proj_name} VERSION 0.1)
add_subdirectory(N3rdNEAT)

find_package(SDL2 REQUIRED)
find_package(SDL_image REQUIRED)

add_executable(Darwin Darwin/main.cpp Deb/deb.cpp)

target_compile_options(Darwin PRIVATE N3rdNEAT)
target_include_directories(Darwin PRIVATE N3rdNEAT/include/ PRIVATE ${SDL2_INCLUDE_DIRS} PRIVATE Deb/)

target_link_libraries(Darwin N3rdNEAT SDL2 SDL_image)
