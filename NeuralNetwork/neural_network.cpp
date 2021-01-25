#include "neural_network.h"

#include <gsl/gsl_blas.h>

NeuralNetwork::NeuralNetwork(std::vector<int>* shapes) {
  int len = shapes->size();
  for(int i = 0; i < len-1; i++) {
    weights.push_back(gsl_matrix_alloc((*shapes)[i+1], (*shapes)[i]));
    biases.push_back(gsl_matrix_alloc(1, (*shapes)[i+1]));
  }
}
