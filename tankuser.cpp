#include "tankuser.hpp"

TankUser::TankUser(SDL_Renderer *ren) :
	Tank(ren)
{
	bounds_.x = 40;
	bounds_.y = 50;
}

void TankUser::event(SDL_Event &event)
{
	switch(event.type) {
	case SDL_KEYDOWN:
		switch( event.key.keysym.sym ) {
		case SDLK_UP:
			bounds_.y--;
			break;
		case SDLK_DOWN:
			bounds_.y++;
			break;
		case SDLK_RIGHT:
			bounds_.x++;
			break;
		case SDLK_LEFT:
			bounds_.x--;
			break;
		}
	}
}



void TankUser::step()
{
	SDLObject::step();
}

