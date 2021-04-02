#pragma once

#include "../Deb/deb.h"
#include "constants.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

#include <SFML/Graphics.hpp>

class UnivParent {
private:
  std::vector<Deb> debs;
  sf::RenderWindow window;
  sf::Texture debTexture;
  int windowWidth;
  int windowHeight;
  static std::vector<sf::Vector2f> food;
  std::minstd_rand randGen;
  //std::default_random_engine randomEngine;

public:
  UnivParent();
  ~UnivParent();
  void mainLoop();
  static std::vector<sf::Vector2f>* getFoodNearPos(sf::Vector2f pos);
  static void foodEaten(sf::Vector2f foodPos);
  std::vector<sf::Vector2f>* getFood();
};
