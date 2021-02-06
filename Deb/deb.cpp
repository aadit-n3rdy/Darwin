#include "deb.h"
#include "../NeuralNetwork/neural_network.h"

Deb::Deb() {
  x= 0;
  y = 0;
  velX = 0;
  velY = 0;
  brain = NeuralNetwork::NeuralNetwork(
