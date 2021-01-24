cmake_minimum_required(VERSION 3.10)

set(proj_name Darwin)
project(${proj_name} VERSION 0.1)
find_package(GSL REQUIRED)
add_library(NeuralNetwork NeuralNetwork/neural_network.cpp)
target_link_libraries(NeuralNetwork GSL::gsl)

