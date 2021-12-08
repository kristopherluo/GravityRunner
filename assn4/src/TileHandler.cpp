#include "TileHandler.h"

TileHandler::TileHandler(){
    tile_rect[0].y = 410; //rect initialization for tileGradient
    tile_rect[0].w = 40;
    tile_rect[0].h = 40;

    tile_rect[1].y = tile_rect[0].y + tile_rect[0].w; //rect initialization for ground2
    tile_rect[1].w = tile_rect[0].w;
    tile_rect[1].h = tile_rect[0].h;

    tile_rect[2].y = 70; //rect initialization for background
    tile_rect[2].w = 320; //width of the screen
    tile_rect[2].h = 340; //height of the screen

    tile_rect[3].y = 330; //rect initialization for background
    tile_rect[3].w = 80; //width of the screen
    tile_rect[3].h = 80; //height of the screen

    screen_left = 0;
    flip = SDL_FLIP_VERTICAL;
}

TileHandler::~TileHandler(){}

void TileHandler::tile_serve_texture(SDL_Surface* tile_surface, SDL_Renderer* object_renderer, int tile_num){
    tile_texture[tile_num] = SDL_CreateTextureFromSurface(object_renderer, tile_surface);
}

void TileHandler::tile_render(SDL_Renderer* obj_renderer){
    tile_rect[0].y = 410;
    tile_rect[0].x = screen_left % tile_rect[2].w;
    tile_rect[1].x = screen_left % tile_rect[1].w;
    while(tile_rect[0].x <= SCREEN_WIDTH){ //while loop that goes through all the bottom ground tiles and prints the ones in the camera view
        SDL_RenderCopy(obj_renderer, tile_texture[0], NULL, &tile_rect[0]);
        tile_rect[1].y = tile_rect[0].y + tile_rect[0].w;
        SDL_RenderCopy(obj_renderer, tile_texture[1], NULL, &tile_rect[1]);
        tile_rect[0].x += tile_rect[0].w;
        tile_rect[1].x += tile_rect[1].w;
    }

    tile_rect[0].y = 30;
    tile_rect[0].x = screen_left % tile_rect[0].w;
    tile_rect[1].x = screen_left % tile_rect[1].w;
    while(tile_rect[1].x <= SCREEN_WIDTH){ //while loop that goes through all the top ground tiles and prints the ones in the camera view
        SDL_RenderCopyEx(obj_renderer, tile_texture[0], NULL, &tile_rect[0], 0.0, NULL, flip);
        tile_rect[1].y = tile_rect[0].y - tile_rect[0].w;
        SDL_RenderCopyEx(obj_renderer, tile_texture[1], NULL, &tile_rect[1], 0.0, NULL, flip);
        tile_rect[0].x += tile_rect[0].w;
        tile_rect[1].x += tile_rect[1].w;
    }

    tile_rect[2].x = screen_left/2;
    while(tile_rect[2].x <= SCREEN_WIDTH){ //while loop that goes through all the backdrop tiles and prints the ones in the camera view
        SDL_RenderCopy(obj_renderer, tile_texture[2], NULL, &tile_rect[2]);
        tile_rect[2].x += tile_rect[2].w;
    }

    tile_rect[3].x = screen_left/2 + 120;
    while(tile_rect[3].x <= SCREEN_WIDTH){
        SDL_RenderCopy(obj_renderer, tile_texture[3], NULL, &tile_rect[3]);
        tile_rect[3].x += 640;
    }
}

void TileHandler::tile_update_screen_left(int x_change){
    screen_left += x_change;
    if(screen_left <= -1 * (SCREEN_WIDTH * 4)){
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


