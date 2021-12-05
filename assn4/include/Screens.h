#include <iostream>
#include <string>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
using namespace std;


class Screens
{
    // private:

    public:

    
    bool start_game;
    bool restart_game;

    TTF_Font* ethnocentic = TTF_OpenFont("../Fonts/ethnocentric rg.ttf", 12);
    SDL_Color black = { 0, 0, 0 };


    void main_menu();
    void render_death_screen(SDL_Renderer* );

};