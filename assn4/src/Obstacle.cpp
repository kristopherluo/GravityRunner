#include "Obstacle.h"

Obstacle::Obstacle(){
    obstacle_rect.x = 0;
    obstacle_rect.y = 0;
    obstacle_rect.w = 0;
    obstacle_rect.h = 0;

    int num = (rand() % 20) * 4;
    obstacle_frame.x = num;
    obstacle_frame.y = 0;
    obstacle_frame.w = 32;
    obstacle_frame.h = 10;

    collected = false;
    if(num % 2){
        forwards = true;
    }else{
        forwards = false;
    }
}

Obstacle::~Obstacle(){}

void Obstacle::obstacle_serve_texture(SDL_Surface* obstacle_surface, SDL_Renderer* object_renderer){
    obstacle_texture = SDL_CreateTextureFromSurface(object_renderer, obstacle_surface);
}

void Obstacle::obstacle_update(){
    if(forwards){
        if((obstacle_frame.x + 4) < 100){
            obstacle_frame.x += 4;
        }else forwards = false;
    }else{
        if((obstacle_frame.x - 4) > 0){
            obstacle_frame.x -= 4;
        }else forwards = true;
    }
}

void Obstacle::obstacle_render(SDL_Renderer* obj_renderer){
    if(type == BOTTOM) SDL_RenderCopyEx(obj_renderer, obstacle_texture, &obstacle_frame, &obstacle_rect, 0.0, NULL, SDL_FLIP_NONE);
    if(type == MIDDLE) SDL_RenderCopyEx(obj_renderer, obstacle_texture, &obstacle_frame, &obstacle_rect, 0.0, NULL, SDL_FLIP_NONE);
    if(type == TOP) SDL_RenderCopyEx(obj_renderer, obstacle_texture, &obstacle_frame, &obstacle_rect, 0.0, NULL, SDL_FLIP_VERTICAL);
}

void Obstacle::obstacle_change_rect_x(int x_change){
    obstacle_rect.x += x_change;
}

void Obstacle::obstacle_change_rect_y(int y_change){
    obstacle_rect.y += y_change;
}

void Obstacle::obstacle_set_rect_x(int x_pos){
    obstacle_rect.x = x_pos;
}

void Obstacle::obstacle_set_rect_y(int y_pos){
    obstacle_rect.y = y_pos;
}

void Obstacle::obstacle_set_rect_w(int width){
    obstacle_rect.w = width;
}

void Obstacle::obstacle_set_rect_h(int height){
    obstacle_rect.h = height;
}

void Obstacle::obstacle_set_type(int t){
    type = t;
}

int Obstacle::obstacle_get_type(){
    return type;
}

int Obstacle::obstacle_get_x_pos(){
    return obstacle_rect.x;
}

int Obstacle::obstacle_get_y_pos(){
    return obstacle_rect.y;
}

void Obstacle::obstacle_set_collected(){
    collected = true;
}

bool Obstacle::obstacle_collected(){
    return collected;
}

void Obstacle::obstacle_destroy(){
    SDL_DestroyTexture(obstacle_texture);
}
