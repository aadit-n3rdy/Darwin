#pragma once

#include <N3rdNEAT/neural_network.h>

//#define FOOD_INPUT_NODES
//#define FOOD_OUTPUT_NODES
#define INTERACT_INPUT_NODES 6
//4 position, 2 quality
#define INTERACT_OUTPUT_NODES 6
#define BRAIN_INPUT_NODES 15
//12 from interacts, 2 for position, 1 for energy
#define BRAIN_OUTPUT_NODES 3
// 2 for motion, 1 for attack
#define START_ENERGY 20.0

#define DEFAULT_VISION_RANGE 50

#define DEFAULT_MANEUVARIBILITY

typedef std::pair<double, double> dVector;

class Deb {
	private:
		std::pair<double, double> position;
		std::pair<double, double> velocity;
		double energy;
		double visionRange;
		NeuralNetwor interactNetwork;
		NeuralNetwork brain;
		void calc();

	public:
		Deb();
		Deb(std::pair<double, double> pos);
		void update(double dt);
};
