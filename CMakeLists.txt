cmake_minimum_required(VERSION 3.10)
set(proj_name Darwin)
project(${proj_name} VERSION 0.1)
add_subdirectory(N3rdNEAT)

find_package(SFML REQUIRED system window graphics audio)

set_source_files_properties(tags PROPERTIES GENERATED true)
add_custom_target(tags
	    COMMAND ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .
	    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(Darwin src/main.cpp Deb/deb.cpp src/UnivParent.cpp)

target_compile_options(Darwin PRIVATE N3rdNEAT)
target_include_directories(Darwin PRIVATE N3rdNEAT/include/ PRIVATE Deb/ )

target_link_libraries(Darwin N3rdNEAT sfml-graphics sfml-window sfml-system)
