#ifndef SDLOBJECT_H
#define SDLOBJECT_H

#include <SDL2/SDL.h>
#include <string>
class SDLAppli;


class SDLObject
{
protected:
	SDL_Renderer *ren_ = nullptr;
    SDL_Texture *texture_ = nullptr;
	SDL_Rect bounds_ = {0,0,0,0};
public:
	SDLObject(SDL_Renderer *ren, std::string filename);
    ~SDLObject();
    virtual void step();
};

#endif // SDLOBJECT_H
