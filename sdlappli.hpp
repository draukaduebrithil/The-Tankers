#ifndef SDLAPPLI_HPP
#define SDLAPPLI_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "sdlobject.hpp"

class SDLAppli
{
    /* SDL thinks */
	SDL_Window *win_;
	SDL_Renderer *ren_;

    /* SDL object to render on the screen */
    std::vector<SDLObject*> sdlobjects_;

public:
	SDLAppli();
	~SDLAppli();

	void test();

    /** main_loop() should be executed in the main loop() */
	void main_loop();

    void addSDLObject(SDLObject *obj);

    SDL_Renderer *getRen() const;
};

#endif // SDLAPPLI_HPP
