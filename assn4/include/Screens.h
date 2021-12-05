#ifndef _SCREENS_H
#define _SCREENS_H

#include <iostream>
#include <string>
<<<<<<< HEAD
=======
#include <cstdlib>
#include <fstream>
using namespace std;
>>>>>>> 37fc6dad21b1d1da897a7222ea6112ef0f04308c

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
using namespace std;

<<<<<<< HEAD

=======
>>>>>>> 37fc6dad21b1d1da897a7222ea6112ef0f04308c
class Screens
{
    // private:

    public:

<<<<<<< HEAD
    
    bool start_game;
    bool restart_game;
=======
    bool in_main_menu; //false if user starts game from main menu
    bool restart_game; //true if user restarts the game
    bool end_game; //true if user ends game
    bool pause_game; //true if user pauses game

    Screens();
    ~Screens();
>>>>>>> 37fc6dad21b1d1da897a7222ea6112ef0f04308c

    TTF_Font* ethnocentic = TTF_OpenFont("../Fonts/ethnocentric rg.ttf", 12);
    SDL_Color black = { 0, 0, 0 };


    void main_menu(SDL_Renderer* obj_renderer); //menu that appears when game is launched
    void pause_menu(SDL_Renderer* obj_renderer); //menu that appears while pausing in game
    void render_death_screen(SDL_Renderer* obj_renderer); //screen that appears when player dies

};

#endif
