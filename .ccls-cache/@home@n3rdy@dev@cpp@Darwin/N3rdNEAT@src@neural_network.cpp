#include "neural_network.h"
#include "node.h"

#include <cstdlib>
#include <list>
#include <iostream>

NeuralNetwork::NeuralNetwork(int input, int output) {
  inputNodeCount = input;
  outputNodeCount = output;
  inputNodes = (Node*)std::calloc(input, sizeof(Node));
  outputNodes = (Node*)std::calloc(output, sizeof(Node));
}

NeuralNetwork::NeuralNetwork() {
	inputNodeCount=5;
	outputNodeCount=5;
	inputNodes=(Node*)std::calloc(5, sizeof(Node));
	outputNodes=(Node*)std::calloc(5, sizeof(Node));
	std::cout << "Using default constructor. why tf is this happening? ";
}

std::vector<double>* NeuralNetwork::calc(const std::vector<double>* input) {
  if(input==nullptr) {
    std::__throw_invalid_argument("input argument of NeuralNetwork::calc was nullptr");
  }
  else if(input->size() != inputNodeCount) {
    std::__throw_invalid_argument("input argument of NeuralNetwork::calc was of wrong size");
  }
  for(int i= 0; i < inputNodeCount; i++) {
    inputNodes[i].val = input->at(i);
  }
  for(int i = 0; i < outputNodeCount; i++) {
    outputNodes[i].calc();
  }
  std::vector<double>* results = (std::vector<double>*)std::calloc(1, sizeof(std::vector<double>));
  results->resize(outputNodeCount);
  for(int i = 0; i < outputNodeCount; i++) {
    results->at(i) = outputNodes[i].getVal();
  }
  return results;
}
