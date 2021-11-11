#ifndef _PARTICLE_H
#define _PARTICLE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

class Particle{
    private:
        SDL_Texture* particle_texture; //stores the particle texture
        SDL_Rect particle_rect; //stores the SDL_Rect information for the particle textures
        SDL_Renderer* obj_renderer;
        int x_pos, y_pos; //position (x,y)
        int x_vel, y_vel; //velocities in x and y direction
        int width, height; 
        int lifetime; //time on screen
    public:
        Particle();
        ~Particle();
        void particle_init(const char* texture, SDL_Renderer* ren, int x_start, int y_start, int wid, int hei);
        void particle_draw_glee(SDL_Renderer* ren);
        void particle_update_glee();
        void particle_set_x_vel(int vel); //sets particle x_vel
        void particle_set_y_vel(int vel); //sets particle y_vel
        void particle_set_lifetime(int lt); //sets particle liftetime
        void particle_set_x_pos(int pos); //sets particle x_pos
        void particle_set_y_pos(int pos); //sets particle y_pos
        int particle_get_x_pos(); //gets particle x_pos
        int particle_get_y_pos(); //gets particle y_pos
};

#endif
