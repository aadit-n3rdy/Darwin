#include <N3rdNEAT/neural_network.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv) {
	NeuralNetwork randomBs(10, 20);
	printf("Hello World");
	if(SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cerr <<"Couldnt init SDL " << SDL_GetError() << " :`(";
	}
	if (!(IMG_Init(IMG_INIT_JPG))) {
		std::cerr << "Couldn't init SDL_image " << SDL_GetError() << " :`(";
	}
	return 0;
}
