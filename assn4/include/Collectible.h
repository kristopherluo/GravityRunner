#ifndef _COLLECTIBLE_H
#define _COLLECTIBLE_H

#define BOTTOM 1
#define MIDDLE 2
#define TOP 3

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

class Collectible{
    private:
        SDL_Texture* collectible_texture; //stores the collectible texture
        SDL_Rect collectible_rect; //stores the SDL_Rect information for the different textures
        int type; //varible to tell if the collectible is on top middle or bottom
        bool collected; //keeps track of if a collectible has been collected 
    public:
        Collectible();
        ~Collectible();

        void collectible_serve_texture(SDL_Surface* collectible_surface, SDL_Renderer* object_renderer); //serves collectible texture to Collectible class which is stored in the collectible_texture variable
        void collectible_render(SDL_Renderer* obj_renderer); //renders the collectible

        void collectible_change_rect_x(int x_change); //adds x_change to the collectible_rect_x
        void collectible_change_rect_y(int y_change); //adds y_change to the collectible_rect_y

        void collectible_set_rect_x(int x_pos); //sets the collectible_rect_x
        void collectible_set_rect_y(int y_pos); //sets the collectible_rect_y
        void collectible_set_rect_w(int width); //sets the collectible width to width parameter
        void collectible_set_rect_h(int height); //sets the collectible heigt to height parameter
        void collectible_set_type(int t); //sets the type to bottom, middle, or top

        int collectible_get_type(); //returns the type
        int collectible_get_x_pos(); //returns collectible's x position
        int collectible_get_y_pos(); //returns collectible's y position

        void collectible_set_collected(); //sets the collectible as collected
        bool collectible_collected(); //returns if the collectible has been collected
        void collectible_destroy(); //destroys collectible
};

#endif
