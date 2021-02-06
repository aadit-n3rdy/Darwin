cmake_minimum_required(VERSION 3.10)

set(proj_name Darwin)
project(${proj_name} VERSION 0.1)
add_library(NeuralNetwork NeuralNetwork/neural_network.cpp NeuralNetwork/node.cpp NeuralNetwork/connector.cpp )
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Darwin Darwin/main.cpp)
target_link_libraries(Darwin sfml-graphics sfml-audio)
