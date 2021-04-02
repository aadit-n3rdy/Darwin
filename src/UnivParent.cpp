#include "UnivParent.h"
#include "constants.h"
#include "deb.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <list>
//#include <random>
#include <ctime>
#include <chrono>
#include <random>

std::vector<sf::Vector2f> UnivParent::food = std::vector<sf::Vector2f>();

UnivParent::UnivParent()  : window(sf::VideoMode(800, 600), "The Darwin Project") {
	//window = sf::RenderWindow(sf::VideoMode(800, 600), "The Darwin Project");
	sf::Vector2u windowSize = window.getSize();
	if (!debTexture.loadFromFile("resources/tmp_sprite.png")) {
		std::cerr << "ERROR: Could not load sprite texture" << std::endl;
	}
	//  std::uniform_real_distribution<float> xpos(0.0, windowSize.x),
	//      ypos(0.0, windowSize.y);
	srand(time(NULL));
	for (int i = 0; i < INIT_DEB_COUNT; i++) {
		/*debs.push_back(Deb(sf::Vector2f(xpos(randomEngine), ypos(randomEngine)),
		  window, &debTexture, &randomEngine));*/
		debs.push_back(Deb(sf::Vector2f(rand()%801, rand()%601), &window, &debTexture, getFoodNearPos, foodEaten));
	}
	std::random_device rd;
	randGen = std::minstd_rand(rd());

}

UnivParent::~UnivParent() {}

void UnivParent::mainLoop() {
	std::uniform_int_distribution<> distrib(0, 10);
	if(distrib(randGen) == 0) {
		std::uniform_int_distribution<> hori(0, 800), vert(0, 600);
		UnivParent::food.push_back(sf::Vector2f(hori(randGen), vert(randGen)));
	}
	std::chrono::high_resolution_clock::time_point start, end;
	float fps = 60;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}
		}

		start = std::chrono::high_resolution_clock::now();

		window.clear();

		for(int i = 0; i < INIT_DEB_COUNT; i++) {
			if(debs[i].update(1.0/fps, this) == DEB_DEAD) {
				debs[i].setPosition(rand()%801, rand()%601);
				debs[i].setEnergy(START_ENERGY);
				debs[i].mutate();
			}
			else {
			}
		}

		window.display();

		end = std::chrono::high_resolution_clock::now();
		fps = float(1e9)/(float)std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
	}
}

std::vector<sf::Vector2f>* UnivParent::getFood() {
	return &food;
}

std::vector<sf::Vector2f>* UnivParent::getFoodNearPos(sf::Vector2f pos) {
	std::vector<sf::Vector2f>* ret = (std::vector<sf::Vector2f>*)std::malloc(sizeof(std::vector<sf::Vector2f>));
	int len = food.size();
	for(int i = 0; i < len; i++) {
		if((pos.x-food[i].x)*(pos.x-food[i].x) + (pos.y-food[i].y)*(pos.y-food[i].y) < 400.0) {
			ret->push_back(food[i]);
		}
	}
	return ret;
}

void UnivParent::foodEaten(sf::Vector2f foodPos) {
	int len = food.size();
	int index = 0;
	for(int i = 0; i < len; i++) {
		if(food[i] == foodPos) {
			index = i;
		}
	}
	food.erase(food.begin() + index);
}
