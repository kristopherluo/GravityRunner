#ifndef _SCREENS_H
#define _SCREENS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
using namespace std;

class Screens
{
    // private:

    public:

    bool in_main_menu; //false if user starts game from main menu
    bool restart_game; //true if user restarts the game
    bool end_game; //true if user ends game
    bool pause_game; //true if user pauses game

    Screens();
    ~Screens();


    void main_menu(SDL_Renderer* obj_renderer); //menu that appears when game is launched
    void pause_menu(SDL_Renderer* obj_renderer); //menu that appears while pausing in game
    void render_death_screen(SDL_Renderer* obj_renderer); //screen that appears when player dies

    void render_score(SDL_Renderer* obj_renderer, int);
};

#endif
