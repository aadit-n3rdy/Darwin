#include "deb.h"

#include <N3rdNEAT/neural_network.h>

//TODO: Might wanna replace std::vector with linked list

dVector* docMoveCalc(std::vector<dVector*> food, unsigned int start, unsigned int end) {
	unsigned int lim = (end-start % 2 == 1) ? end : end-1;
	for(unsigned int i = start, i <= lim) {

	}
}

Deb::Deb() {
	position = dVector(0.0f, 0.0f);
	velocity = dVector(0.0f, 0.0f);
	interactNetwork = NeuralNetwork(INTERACT_INPUT_NODES, INTERACT_OUTPUT_NODES);
	brain = NeuralNetwork(BRAIN_INPUT_NODES, BRAIN_OUTPUT_NODES);
	energy = START_ENERGY;
	visionRange = DEFAULT_VISION_RANGE;
}
Deb::Deb(dVector pos) {
	position = pos;
	velocity = dVector(0.0f, 0.0f);
	interactNetwork = NeuralNetwork(INTERACT_INPUT_NODES, INTERACT_OUTPUT_NODES);
	brain = NeuralNetwork(BRAIN_INPUT_NODES, BRAIN_OUTPUT_NODES);
	energy = START_ENERGY;
	visionRange = DEFAULT_VISION_RANGE;
}

void Deb::update(double dt) {
	position.first += velocity.first * dt;
	position.second += velocity.second * dt;
	dVector acceleration;
	std::vector<dVector> foodThingies = std::vector<dVector>();

	//TODO: Get list of food thingies using 
}
