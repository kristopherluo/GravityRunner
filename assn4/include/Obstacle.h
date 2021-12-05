#ifndef _OBSTACLE_H
#define _OBSTACLE_H

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

class Obstacle{
    private:
        SDL_Texture* obstacle_texture; //stores the obstacle texture
        SDL_Rect obstacle_rect; //stores the SDL_Rect information for the different textures
        SDL_Rect obstacle_frame;
        int type; //varible to tell if the obstacle is on top middle or bottom
        bool collected; //keeps track of if a obstacle has been collected
        bool forwards;
    public:
        Obstacle();
        ~Obstacle();

        void obstacle_serve_texture(SDL_Surface* obstacle_surface, SDL_Renderer* object_renderer); //serves obstacle texture to Obstacle class which is stored in the obstacle_texture variable
        void obstacle_update(); //updates obstacle
        void obstacle_render(SDL_Renderer* obj_renderer); //renders the obstacle

        void obstacle_change_rect_x(int x_change); //adds x_change to the obstacle_rect_x
        void obstacle_change_rect_y(int y_change); //adds y_change to the obstacle_rect_y

        void obstacle_set_rect_x(int x_pos); //sets the obstacle_rect_x
        void obstacle_set_rect_y(int y_pos); //sets the obstacle_rect_y
        void obstacle_set_rect_w(int width); //sets the obstacle width to width parameter
        void obstacle_set_rect_h(int height); //sets the obstacle heigt to height parameter
        void obstacle_set_type(int t); //sets the type to bottom, middle, or top

        int obstacle_get_type(); //returns the type
        int obstacle_get_x_pos(); //returns obstacle's x position
        int obstacle_get_y_pos(); //returns obstacle's y position

        void obstacle_set_collected(); //sets the obstacle as collected
        bool obstacle_collected(); //returns if the obstacle has been collected
        void obstacle_destroy(); //destroys obstacle
};

#endif
