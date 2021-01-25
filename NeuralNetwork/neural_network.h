#ifndef DARWIN_NEURAL_NETWORK_H
#define DARWIN_NEURAL_NETWORK_H

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <vector>

class NeuralNetwork {
 private:
  std::vector<gsl_matrix *> weights;
  std::vector<gsl_matrix *> biases;
 public:
  NeuralNetwork(std::vector<int>* shapes, int inputCountForEachRepeated);
  NeuralNetwork(const NeuralNetwork* parent);
  std::vector<double> calculate(std::vector<double> input);
};

#endif
