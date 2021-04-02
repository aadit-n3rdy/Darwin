#pragma once

#include <N3rdNEAT/neural_network.h>
#include <SFML/Graphics.hpp>

class UnivParent;

//#define FOOD_INPUT_NODES
//#define FOOD_OUTPUT_NODES
#define FOOD_INPUT_NODES 2
// 4 position, 2 quality
#define FOOD_OUTPUT_NODES 2
#define BRAIN_INPUT_NODES 5
// 2 for input from food, 1 for energy, 2 for velocity
#define BRAIN_OUTPUT_NODES 2
// 2 for motion, 1 for attack/eat
#define START_ENERGY 20.0
#define MOVE_EFF 0.001
#define DEFAULT_VISION_RANGE 50

#define DEB_ALIVE 0
#define DEB_DEAD 1

#define EVOLVE_CHANCE 0.5
class Deb {
	private:
		sf::Vector2f position;
		sf::Vector2f velocity;
		double energy;
		double visionRange;
		NeuralNetwork foodNetwork;
		NeuralNetwork brain;
		void calc();
		const sf::Texture *texture;
		sf::RenderWindow *window;
		sf::Sprite sprite;
		std::vector<sf::Vector2f>* (*getFoodNearPos)(sf::Vector2f pos);
		void (*foodEaten)(sf::Vector2f foodPos);


	public:
		Deb();
		~Deb();
		Deb(sf::Vector2f pos, sf::RenderWindow *win, sf::Texture *tex, std::vector<sf::Vector2f>* (*getFoodNearPosCallback)(sf::Vector2f pos), void (*foodEatenCallback)(sf::Vector2f foodPos));
		int update(double dt, UnivParent* p);
		void setPosition(float x, float y);
		void mutate();
		void setEnergy(float e);
};
