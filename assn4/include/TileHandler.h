#ifndef _TILEHANDLER_H
#define _TILEHANDLER_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

class TileHandler{
    private:
        SDL_Texture* tile_texture[5]; //stores the 3 textures background, ground, and ground2
        SDL_Rect tile_rect[5]; //stores the SDL_Rect information for the different textures
        SDL_RendererFlip flip; //controls where the sprite is flipped or not
        int screen_left; //represents the left edge camera view
    public:
        TileHandler();
        ~TileHandler();

        void tile_serve_texture(SDL_Surface* tile_surface, SDL_Renderer* object_renderer, int tile_num); //serves a tile texture to TileHandler class which is stored in the tile_texture array
        void tile_render(SDL_Renderer* obj_renderer); //renders all the tiles that are in the camera view
        void tile_update_screen_left(int x_change); //changes the left side of the camera view
        bool tile_reach_screen_end(); //returns true if the screen_left variable (representing the left edge camera view) reaches the bounds
};

#endif
