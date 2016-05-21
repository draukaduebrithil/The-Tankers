#ifndef SDLAPPLI_HPP
#define SDLAPPLI_HPP

#include <SDL2/SDL.h>

class SDLAppli
{
	SDL_Window *win_;
	SDL_Renderer *ren_;
public:
	SDLAppli();
	~SDLAppli();
	void test();
};

#endif // SDLAPPLI_HPP
