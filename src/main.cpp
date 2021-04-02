#include <N3rdNEAT/neural_network.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "UnivParent.h"

int main(int argc, char** argv) {

  // NeuralNetwork randomBs(10, 20);
  // printf("Hello World");
  // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  // sf::CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);

  // while (window.isOpen()) {
  //   sf::Event event;
  //   while (window.pollEvent(event)) {
  //     if (event.type == sf::Event::Closed)
  // 	window.close();
  //   }
  //   window.clear();
  //   window.draw(shape);
  //   window.display();
  // }
  UnivParent univParent;
  std::cout << "LOG: UnivParent initialised successfully" << std::endl;
  univParent.mainLoop();
  return 0;
}
