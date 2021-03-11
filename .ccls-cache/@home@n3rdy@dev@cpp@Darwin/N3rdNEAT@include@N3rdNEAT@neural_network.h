#ifndef N3RD_NEAT_NETWORK_H
#define N3RD_NEAT_NETWORK_H

#include <vector>

class Connector;
class Node;

class NeuralNetwork {
private:
  std::vector<Node *> nodes;
  std::vector<Connector *> connectors;
  Node *inputNodes;
  Node *outputNodes;
  int inputNodeCount;
  int outputNodeCount;

public:
  NeuralNetwork(int input, int output);
  NeuralNetwork();
  std::vector<double> *calc(const std::vector<double> *input);
};

#endif
