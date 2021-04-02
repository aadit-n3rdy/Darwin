#include "deb.h"

#include <N3rdNEAT/neural_network.h>
#include <cmath>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../src/UnivParent.h"

// TODO: Might wanna replace std::vector with linked list

Deb::Deb() {
	position = sf::Vector2f(0.0f, 0.0f);
	velocity = sf::Vector2f(0.0f, 0.0f);
	brain = NeuralNetwork(BRAIN_INPUT_NODES, BRAIN_OUTPUT_NODES);
	energy = START_ENERGY;
	visionRange = DEFAULT_VISION_RANGE;
	window = nullptr;
	texture = nullptr;
	sprite = sf::Sprite();
	sprite.setTexture(*texture, false);
}
Deb::Deb(sf::Vector2f pos, sf::RenderWindow *win, sf::Texture *tex, std::vector<sf::Vector2f>* (*getFoodNearPosCallback)(sf::Vector2f pos), void (*foodEatenCallback)(sf::Vector2f foodPos)) {
	if (win == nullptr || tex == nullptr) {
		std::cout << "ERROR: Passed nullptr to Deb constructor" << std::endl;
	}
	window = win;
	texture = tex;
	position = pos;
	velocity = sf::Vector2f(0.0f, 0.0f);
	brain = NeuralNetwork(BRAIN_INPUT_NODES, BRAIN_OUTPUT_NODES);
	energy = START_ENERGY;
	visionRange = DEFAULT_VISION_RANGE;
	sprite = sf::Sprite();
	sprite.setTexture(*tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite.scale(3, 3);
/*	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	double r = distribution(*random);*/
	//TODO: Add condition for mutation
	brain.mutate();
	getFoodNearPos = getFoodNearPosCallback;
	foodEaten = foodEatenCallback;
	//foodNetwork.mutate();

}

void Deb::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	velocity.x = 0;
	velocity.y = 0;
}

void Deb::setEnergy(float e) {
	energy = e;
}

int Deb::update(double dt, UnivParent* p) {
	std::cout << "LOG: Started deb update\n";
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;
	energy -= (velocity.x * velocity.x + velocity.y * velocity.y + 1) * MOVE_EFF;
	if (velocity.x + velocity.y > 1.0) {
		std::cout << "RG: MOVING " << velocity.x << " " << velocity.y << '\n';
	}
	if (energy < 0 || position.x < 0.0 || position.y < 0.0 || position.x > 800.0 || position.y > 600.0) {
		std::cout << "LOG: Deb died " << this << '\n';
		return DEB_DEAD;
	}
	sf::Vector2f acceleration;
	std::vector<sf::Vector2f>* foodThingies = p->getFood();
	std::cout << "LOG: Got foodThingies\n";
	// TODO: Use a callback to get list of food
	size_t visibleCount = foodThingies->size();
	sf::Vector2f weightedSum = sf::Vector2f(0, 0);
	sf::Vector2f vector;
	int count = 0;

	for (size_t i = 0; i < visibleCount; i++) {
		std::cout << "LOG: " << foodThingies->size() << "\n";
		vector.x = foodThingies->at(i).x - position.x;
		vector.y = foodThingies->at(i).y - position.y;
		float dSquare = vector.x*vector.x + vector.y*vector.y;
		if(dSquare <= 100) {
			energy += float(START_ENERGY) * 0.1;
			int index = 0;
			foodThingies->erase(foodThingies->begin() + index);
			visibleCount-=1;
			i--;
			std::cout << "LOG: ate\n";
		}
		else if(dSquare <= 1000) {
			double output[FOOD_OUTPUT_NODES];
			double input[FOOD_INPUT_NODES] = { foodThingies->at(i).x - position.x, foodThingies->at(i).y - position.y};
			foodNetwork.calc(input, output);
			weightedSum.x += output[0];
			weightedSum.y += output[1];
			count+=1;
		}
	}

	std::cout << "LOG: Done with food loop\n";
	sf::Vector2f foodWeightedAvg;
	foodWeightedAvg = (count==0) ? sf::Vector2f(0, 0) : sf::Vector2f(weightedSum.x/count, weightedSum.y/count);

	std::cout << "LOG: Done with redundant portion\n";

	//std::vector<double> brainOutput(3);
	double brainOutput[BRAIN_OUTPUT_NODES] = {0, 0};
	double brainInput[BRAIN_INPUT_NODES] = {velocity.x,
				velocity.y,
				energy,
				foodWeightedAvg.x,
				foodWeightedAvg.y,
				};

	std::cout << "LOG: Created brainOutput\n";

	brain.calc(brainInput, brainOutput);

	acceleration.x = brainOutput[0];
	acceleration.y = brainOutput[1];
	velocity.x += acceleration.x * dt * 10.0;
	velocity.y += acceleration.y * dt * 10.0;

	std::cout << "LOG: Done with brain calcs\n";

	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite.setPosition((int)position.x, (int)position.y);
	sprite.setScale(3.0*energy/START_ENERGY, 3.0*energy/START_ENERGY);
	window->draw(sprite);
	std::cout << "LOG: Ended deb update\n";
	return DEB_ALIVE;
}

Deb::~Deb() {
	// TODO: If allocating memmory, remember to free
}

void Deb::mutate() {
	brain.mutate();
}
