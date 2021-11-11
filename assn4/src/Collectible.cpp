#include "Collectible.h"

Collectible::Collectible(){
    collectible_rect.x = 0;
    collectible_rect.y = 347;
    collectible_rect.w = 25;
    collectible_rect.h = 25;
    collected = false;
}

Collectible::~Collectible(){}

void Collectible::collectible_serve_texture(SDL_Surface* collectible_surface, SDL_Renderer* object_renderer){
    collectible_texture = SDL_CreateTextureFromSurface(object_renderer, collectible_surface);
}

void Collectible::collectible_render(SDL_Renderer* obj_renderer){
    SDL_RenderCopy(obj_renderer, collectible_texture, NULL, &collectible_rect);
}

void Collectible::collectible_set_rect_x(int x_change){
    collectible_rect.x += x_change;
}

void Collectible::collectible_set_rect_y(int y_change){
    collectible_rect.y += y_change;
}

int Collectible::collectible_get_x_pos(){
    return collectible_rect.x;
}

int Collectible::collectible_get_y_pos(){
    return collectible_rect.y;
}

void Collectible::collectible_set_collected(){
    collected = true;
}

bool Collectible::collectible_collected(){
    return collected;
}

void Collectible::collectible_destroy(){
    SDL_DestroyTexture(collectible_texture);
}
