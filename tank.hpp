#ifndef TANK_H
#define TANK_H
#include "sdlobject.hpp"


class Tank : public SDLObject
{
    enum {
        right,
        left,
    } direction_ = right;

public:
	Tank(SDL_Renderer *ren);


    // SDLObject interface
public:
    void step();
};

#endif // TANK_H
