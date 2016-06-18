#include "tank.hpp"
#include <cmath>

Tank::Tank(SDL_Renderer *ren) :
	SDLObject(ren, "img/0015-512.png")
{
    bounds_.x = 10;
    bounds_.y = 10;
    bounds_.w = 40;
    bounds_.h = 40;
}

void Tank::step()
{
    if ( direction_ == right ){
        bounds_.x++;
        if ( bounds_.x > 100 ) {
			direction_ = left;
        }
		SDL_RenderCopyEx(ren_,
						 texture_,
						 nullptr, &bounds_,
						 0, NULL, SDL_FLIP_NONE );
	} else {
        bounds_.x--;
		if ( bounds_.x < 10 ) {
			direction_ = right;
		}
		SDL_RenderCopyEx(ren_,
						 texture_,
						 nullptr, &bounds_,
						 0, NULL, SDL_FLIP_HORIZONTAL );
	}
}

