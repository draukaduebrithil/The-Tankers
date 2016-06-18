#ifndef TANKUSER_HPP
#define TANKUSER_HPP

#include "tank.hpp"
#include <SDL2/SDL_events.h>

class TankUser : public Tank
{
public:
	TankUser(SDL_Renderer *ren);

	void event(SDL_Event &event);

	// SDLObject interface
public:
	void step();
};

#endif // TANKUSER_HPP
