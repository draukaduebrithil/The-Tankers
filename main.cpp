#include <iostream>
#include <SDL2/SDL.h>
#include "sdlappli.hpp"
#include "tank.hpp"

int main(int, char**){
	SDLAppli sdlappli;
	Tank tank(sdlappli.getRen());
	sdlappli.addSDLObject(&tank);

	for(int i=0;i<1000;++i ) {
		sdlappli.main_loop();

		// 50 ms to dobra liczba
		SDL_Delay(50);
	}

	return 0;
}
