#include "sdlappli.hpp"
#include <iostream>

SDL_Renderer *SDLAppli::getRen() const
{
    return ren_;
}

SDLAppli::SDLAppli()
{
    // start SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
		throw std::string("SDL_Init Error: " + std::string( SDL_GetError() ));
	}

	// open window - nazwa ekranu, wielkość - to mogą być parametry klasy
	win_ = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win_ == nullptr){
		SDL_Quit();
        throw std::runtime_error("SDL_CreateWindow Error: " + std::string( SDL_GetError() ));
	}

	// start renderer
	ren_ = SDL_CreateRenderer(win_, -1, SDL_RENDERER_ACCELERATED);
	if (ren_ == nullptr){
		SDL_DestroyWindow(win_);
		SDL_Quit();
        throw std::runtime_error("SDL_CreateRenderer Error: " + std::string( SDL_GetError() ));
	}

	// background color! , color w rgb + nasycenie
	SDL_SetRenderDrawColor(ren_, 255, 0, 0, 255);
}

SDLAppli::~SDLAppli()
{
	if ( ren_ )
		SDL_DestroyRenderer(ren_);
	if ( win_ )
		SDL_DestroyWindow(win_);
	SDL_Quit();
}

void SDLAppli::test()
{
	// bierzemy sobie hello.bmp
	std::string path = "img/hello.bmp";
	SDL_Surface *bmp = SDL_LoadBMP(path.c_str());
	if (bmp == nullptr) {
        throw std::runtime_error("SDL_LoadBMP Error: " + std::string( SDL_GetError() ));
	}

	// łączymy nasze hello.bmp z rendererem
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren_, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr){
        throw std::runtime_error("SDL_CreateTextureFromSurface Error: " + std::string( SDL_GetError() ));
	}

	// no i wyswietlamy przez 3 sekundy
	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    for (int i = 0; i < 0; ++i){
		//First clear the renderer
		SDL_RenderClear(ren_);
		//Draw the texture
		SDL_RenderCopy(ren_, tex, NULL, NULL);
		//Update the screen
		SDL_RenderPresent(ren_);
		//Take a quick break after all that hard work
		SDL_Delay(1000);
	}

    SDL_DestroyTexture(tex);
}

void SDLAppli::main_loop()
{
    //Clear screen
    SDL_RenderClear( ren_ );

	/* dla każdego obiektu w sdlobjects_ */
    for(SDLObject* &obj : sdlobjects_ ) {
        obj->step();
    }

    //Update screen
    SDL_RenderPresent( ren_ );
}

void SDLAppli::addSDLObject(SDLObject *obj)
{
    sdlobjects_.push_back(obj);
}

