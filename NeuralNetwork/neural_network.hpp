#ifndef DARWIN_NEURAL_NETWORK_HPP
#define DARWIN_NEURAL_NETWORK_HPP

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <vector>

class NeuralNetwork {
private:
  std::vector<gsl_matrix *> weights;
  std::vector<gsl_matrix *> biases;

public:
  NeuralNetwork(const int *shape_array, int shape_count);
  NeuralNetwork(const NeuralNetwork *parent);

  std::vector<double> calculate(std::vector<double> input);
};

#endif
