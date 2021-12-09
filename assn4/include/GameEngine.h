#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H

#include "Player.h"
#include "PlayerSprite.h"
#include "TileHandler.h"
#include "Obstacle.h"
#include "Screens.h"

class GameEngine{
    private:
        SDL_Renderer* obj_renderer;
        SDL_Window* obj_window;
        SDL_Event obj_event;
        SDL_Rect laser_end_rect[12];
        SDL_Texture* laser_end;

        int screen_width, screen_height; //screen dimensions
        int this_start_time, this_duration, fps, frame_duration; //fps controller variables;
        int obstacle_rect_x, obstacle_rect_y; //obstacle helper variables
        int score; //keeps track of score
        int lasers; //number of obstacle one's
        int total_cases; //keeps track of the difficulty
        bool key_down; //keeps track of whether or not a key is down
        int counter[6];

        Player player; //variable of type Player to call that class' functions
        PlayerSprite sprite; //variable of type PlayerSprite to call that class' functions
        TileHandler tile; //variable of type TileHandler to call that class' functions
        Obstacle obstacle[10]; //array of type Collectible to create instances of that GameObject
        Screens screens; //Variable of screens for start/end screens
    
    public:
        GameEngine(SDL_Renderer* ren);
        ~GameEngine();

        bool player_alive; //true if player is alive
        bool game_is_running; //true if game is running
        
        
        void obj_init(); //initializes game
        void obj_updateUI(); //updates based off of user input
        void obj_update(); //update mechanics
        void obj_render(); //draws onto screen
        void obj_quit(); //cleans up and quits
};

#endif
