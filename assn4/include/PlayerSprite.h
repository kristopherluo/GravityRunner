#ifndef _PLAYERSPRITE_H
#define _PLAYERSPRITE_H

#define IDLE 0
#define RUN 1
#define IDLE_FRAME_DURATION 250
#define RUN_FRAME_DURATION 150
#define IDLE_FRAME_COUNT 4
#define RUN_FRAME_COUNT 6

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

class PlayerSprite{
    private:
        SDL_Texture* sprite_texture_idle; //texture that holds the idle sprite sheet
        SDL_Texture* sprite_texture_run; //texture that holds the running sprite sheet
        SDL_Rect sprite_rect; //SDL_Rect used to store information to render the textures
        SDL_Rect sprite_frame; //SDL_Rect used to store information to render certain parts of the textures
        int sprite_state; //variable to track the current state of the player (idle, running)
        SDL_RendererFlip sprite_direc; //variable to track the current direction of the player (left, right)
        int frame_duration, frame_count;
        int gravity_change; //variable to state if gravity is currently changing
    public:
        PlayerSprite();
        ~PlayerSprite();

        void sprite_serve_texture_idle(SDL_Surface* sprite_surface, SDL_Renderer* object_renderer); //serves the sprite texture idle to PlayerSprite class
        void sprite_serve_texture_run(SDL_Surface* sprite_surface, SDL_Renderer* object_renderer); //serves the sprite texture run to PlayerSprite class
        void sprite_update_frame(); //updates the frame of the current sprite        
        void sprite_render(SDL_Renderer* obj_renderer/*, SDL_Texture* sprite_texture*/); //renders the sprite
        void sprite_set_state(int state); //sets the state of the sprite
        void sprite_change_gravity(); //sets the direction the sprite faces
        void sprite_set_gravity_change(); //sets changing gravity variable to false
        int sprite_get_state(); //returns the sprite's state (idle: 0 or running: 1)
        int sprite_get_direction(); //returns the direction the sprite is facing
        int sprite_get_gravity_state(); //returns whether the sprite is changing gravity
        void sprite_set_rect_x(int x); //sets the sprite rect x
        void sprite_set_rect_y(int y); //sets the sprite rect y
        void sprite_set_rect_w(int w); //sets the sprite rect w
        void sprite_set_rect_h(int h); //sets the sprite rect h
        int sprite_get_width(); //returns the sprite width
        int sprite_get_height(); //returns the sprite width  
};

#endif
