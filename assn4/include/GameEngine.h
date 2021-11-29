#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H

#include "Player.h"
#include "PlayerSprite.h"
#include "TileHandler.h"
#include "Collectible.h"
#include "ParticleEmitter.h"

class GameEngine{
    private:
        SDL_Renderer* obj_renderer;
        SDL_Window* obj_window;
        SDL_Event obj_event;

        int screen_width, screen_height; //screen dimensions
        int this_start_time, this_duration, fps, frame_duration; //fps controller variables;
        int collectible_rect_x, collectible_rect_y; //collectible helper variables
        bool key_down; //keeps track of whether or not a key is down

        Player player; //variable of type Player to call that class' functions
        PlayerSprite sprite; //variable of type PlayerSprite to call that class' functions
        TileHandler tile; //variable of type TileHandler to call that class' functions
        Collectible collectible[10]; //array of type Collectible to create instances of that GameObject
        Particle particle; //variable of type Particle to call that class' functions
        ParticleEmitter particle_emit; //variable of type ParticleEmitter to call that class' functions
    public:
        GameEngine(SDL_Renderer* ren);
        ~GameEngine();

        bool game_is_running;
        
        void obj_init(); //initializes game
        void obj_updateUI(); //updates based off of user input
        void obj_update(); //update mechanics
        void obj_render(); //draws onto screen
        void obj_quit(); //cleans up and quits
};

#endif
