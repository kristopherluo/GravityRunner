#include "TileHandler.h"

TileHandler::TileHandler(){
    tile_rect[0].y = -100; //rect initialization for background
    tile_rect[0].w = 640; //width of the screen
    tile_rect[0].h = 480; //height of the screen

    tile_rect[1].y = 370; //rect initialization for ground1
    tile_rect[1].w = 40;
    tile_rect[1].h = 40;

    tile_rect[2].y = tile_rect[1].y + tile_rect[1].w; //rect initialization for ground2
    tile_rect[2].w = tile_rect[1].w;
    tile_rect[2].h = tile_rect[1].h;

    screen_left = 0;
}

TileHandler::~TileHandler(){}

void TileHandler::tile_serve_texture(SDL_Surface* tile_surface, SDL_Renderer* object_renderer, int tile_num){
    tile_texture[tile_num] = SDL_CreateTextureFromSurface(object_renderer, tile_surface);
}

void TileHandler::tile_render(SDL_Renderer* obj_renderer){
    //cout << "screen_left: " << screen_left % tile_rect[1].w << endl;
    tile_rect[0].x = screen_left/2;
    while(tile_rect[0].x <= 640){ //while loop that goes through all the backdrop tiles and prints the ones in the camera view
        SDL_RenderCopy(obj_renderer, tile_texture[0], NULL, &tile_rect[0]);
        tile_rect[0].x += tile_rect[0].w;
    }

    tile_rect[1].x = screen_left % tile_rect[1].w;
    tile_rect[2].x = screen_left % tile_rect[2].w;
    while(tile_rect[1].x <= 640){ //while loop that goes through all the ground tiles and prints the ones in the camera view
        SDL_RenderCopy(obj_renderer, tile_texture[1], NULL, &tile_rect[1]);
        tile_rect[2].y = tile_rect[1].y + tile_rect[1].w;
        SDL_RenderCopy(obj_renderer, tile_texture[2], NULL, &tile_rect[2]);
        tile_rect[2].y += tile_rect[2].w;
        SDL_RenderCopy(obj_renderer, tile_texture[2], NULL, &tile_rect[2]);
        tile_rect[1].x += tile_rect[1].w;
        tile_rect[2].x += tile_rect[2].w;
    }
}

void TileHandler::tile_update_screen_left(int x_change){
    screen_left += x_change;
    if(screen_left <= -1280){
        screen_left = 0;
    }
}

bool TileHandler::tile_reach_screen_end(){
    if(screen_left == 0 || screen_left == tile_rect[0].w + tile_rect[0].w/2){ //checks if the screen has reached the edge
        return true;
    }else{
        return false;
    }
}


