#ifndef DARWIN_NEURAL_NETWORK_NEURAL_NETWORK_H
#define DARWIN_NEURAL_NETWORK__NEURAL_NETWORK_H

#include <vector>

class Connector;
class Node;

class NeuralNetwork {
private:
  std::vector<Node*> nodes;
  std::vector<Connector*> connectors;
  Node* inputNodes;
  Node* outputNodes;
  int inputNodeCount;
  int outputNodeCount;
public:
  NeuralNetwork(int input, int output);
  std::vector<double>* calc(const std::vector<double>* input);
};

#endif
