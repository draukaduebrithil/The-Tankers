#include "sdlobject.hpp"
#include "sdlappli.hpp"
#include <SDL2/SDL_image.h>
#include <stdexcept>

SDLObject::SDLObject(SDL_Renderer *ren, std::string filename) :
	ren_(ren)
{
    SDL_Surface *surf = IMG_Load(filename.c_str());
    if  ( !surf ) {
        throw std::runtime_error("SDL_LoadBMP " + std::string(__PRETTY_FUNCTION__));
    }
	texture_ = SDL_CreateTextureFromSurface(ren_, surf);
    if ( !texture_ ) {
        throw std::runtime_error("SDL_CreateTextureFromSurface " +std::string( __PRETTY_FUNCTION__) );
    }
    SDL_FreeSurface(surf);
}

SDLObject::~SDLObject()
{
    SDL_DestroyTexture(texture_);
}

void SDLObject::step()
{
	SDL_RenderCopy(ren_, texture_, nullptr, &bounds_);
}
