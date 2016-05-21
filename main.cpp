#include <iostream>
#include <SDL2/SDL.h>
#include "sdlappli.hpp"

int main(int, char**){
	// jest wywoływany konstruktor
	SDLAppli sdlappli;

	// wywołujemy funkcję test() w sdlappli
	sdlappli.test();

	// destruktor jest wywoływany automatycznie
	return 0;
}
