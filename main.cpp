#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "sdlappli.hpp"
#include "tank.hpp"
#include "tankuser.hpp"

int main(int, char**){
	SDLAppli sdlappli;
	Tank tank(sdlappli.getRen());
	TankUser user(sdlappli.getRen());
	sdlappli.addSDLObject(&tank);
	sdlappli.addSDLObject(&user);

	for(int i=0;i<1000;++i ) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
			case SDL_QUIT:
				return 0;
			case SDL_KEYDOWN:
				user.event(event);
				break;
			case SDL_MOUSEMOTION:
				printf("We got a motion event.\n");
				printf("Current mouse position is: (%d, %d)\n", event.motion.x, event.motion.y);
				break;
			default:
				printf("Unhandled Event!\n");
				break;
			}
		}

		sdlappli.main_loop();

		// 50 ms to dobra liczba
		SDL_Delay(50);
	}

	return 0;
}
