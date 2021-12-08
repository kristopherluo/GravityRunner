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

class Screens{
    public:
    bool in_main_menu; //false if user starts game from main menu
    bool restart_game; //true if user restarts the game
    bool end_game; //true if user ends game
    bool pause_game; //true if user pauses game
    bool credits; //true if user pulls up credits
    bool instructions; //true if user pulls up instructions

    Screens();
    ~Screens();

    void render_main_menu(SDL_Renderer* obj_renderer); //menu that appears when game is launched
    void render_pause_menu(SDL_Renderer* obj_renderer); //menu that appears while pausing in game
    void render_death_screen(SDL_Renderer* obj_renderer); //screen that appears when player dies

    void render_score(SDL_Renderer* obj_renderer, int); //score that appears during the game
    void render_credits(SDL_Renderer* obj_renderer); //renders the credits screen
    void render_instructions(SDL_Renderer* obj_renderer); //renders the instructions screen
};

#endif
