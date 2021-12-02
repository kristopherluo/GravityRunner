#include <iostream>
#include <string>
// #include <cstdlib>
// #include <fstream>
using namespace std;

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include <SDL2/SDL_ttf.h>

class Screens
{
    private:



    public:

    bool start_game;
    bool restart_game;
    bool end_game;

    SDL_Event death_event;

    void main_menu();
    void render_death_screen(SDL_Renderer* );

};