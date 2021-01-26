cmake_minimum_required(VERSION 3.10)

set(proj_name Darwin)
project(${proj_name} VERSION 0.1)
add_library(NeuralNetwork NeuralNetwork/neural_network.cpp NeuralNetwork/node.cpp)
