#ifndef _SCREENS_H
#define _SCREENS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

class Screens
{
    private:



    public:

    bool start_game; //
    bool restart_game; //true if user restarts the game
    bool end_game; //true if user ends game
    bool pause_game; //true if user pauses game

    SDL_Event death_event;

    void main_menu(SDL_Renderer* obj_renderer);
    void pause_menu(SDL_Renderer* obj_renderer);
    void render_death_screen(SDL_Renderer* obj_renderer);

};

#endif
