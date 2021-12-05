#include "PlayerSprite.h"

PlayerSprite::PlayerSprite(){
    sprite_rect.w = 64;
    sprite_rect.h = 64;
    sprite_frame.x = 0;
    sprite_frame.y = 0;
    sprite_frame.w = 32;
    sprite_frame.h = 32;
    frame_duration = IDLE_FRAME_DURATION;
    frame_count = 4;
    sprite_state = 0;
    sprite_direc = SDL_FLIP_NONE;
    gravity_change = 0;
}

PlayerSprite::~PlayerSprite(){}

void PlayerSprite::sprite_serve_texture_idle(SDL_Surface* sprite_surface, SDL_Renderer* object_renderer){
    sprite_texture_idle = SDL_CreateTextureFromSurface(object_renderer, sprite_surface); //stores the idle sprite sheet into sprite_texture_idle
}

void PlayerSprite::sprite_serve_texture_run(SDL_Surface* sprite_surface, SDL_Renderer* object_renderer){
    sprite_texture_run = SDL_CreateTextureFromSurface(object_renderer, sprite_surface); //stores the run sprite sheet into sprite_texture_run
}

void PlayerSprite::sprite_update_frame(){
    int frame_time = (int)(SDL_GetTicks()/frame_duration) % frame_count; //code to control the speed at which the program loops through the sprite sheets
    static int last_frame_time = 0;
    if(last_frame_time != frame_time){
        if(sprite_frame.x < (sprite_frame.w*3) - sprite_frame.w){
            sprite_frame.x += sprite_frame.w;
        }else{
            sprite_frame.x = 0;
        }
    }
    last_frame_time = frame_time;
}

void PlayerSprite::sprite_render(SDL_Renderer* obj_renderer){
    if(sprite_state == IDLE) SDL_RenderCopyEx(obj_renderer, sprite_texture_idle, &sprite_frame, &sprite_rect, 0.0, NULL, sprite_direc); //renders idle sprite
    if(sprite_state == RUN) SDL_RenderCopyEx(obj_renderer, sprite_texture_run, &sprite_frame, &sprite_rect, 0.0, NULL, sprite_direc); //renders run sprite
}

void PlayerSprite::sprite_set_state(int state){
    sprite_state = state;
    if(sprite_state == IDLE){
        frame_duration = IDLE_FRAME_DURATION;
        frame_count = IDLE_FRAME_COUNT;
    }
    if(sprite_state == RUN){
        frame_duration = RUN_FRAME_DURATION;
        frame_count = IDLE_FRAME_COUNT;
    }
}

void PlayerSprite::sprite_change_gravity(){
    if(sprite_direc == SDL_FLIP_VERTICAL){
        sprite_direc = SDL_FLIP_NONE;
    }else{
        sprite_direc = SDL_FLIP_VERTICAL;
    }
    gravity_change = 1;
}

void PlayerSprite::sprite_set_gravity_change(){
    gravity_change = 0;
}

void PlayerSprite::sprite_set_direction(SDL_RendererFlip direc){
    sprite_direc = direc;
}

int PlayerSprite::sprite_get_state(){
    return sprite_state;
}

int PlayerSprite::sprite_get_direction(){
    if(sprite_direc == SDL_FLIP_VERTICAL) return 0;
    if(sprite_direc == SDL_FLIP_NONE) return 1;
    else return 1;
}

int PlayerSprite::sprite_get_gravity_state(){
    return gravity_change;
}

void PlayerSprite::sprite_set_rect_x(int x){
    sprite_rect.x = x;
}

void PlayerSprite::sprite_set_rect_y(int y){
    sprite_rect.y = y;
}

void PlayerSprite::sprite_set_rect_w(int w){
    sprite_rect.w = w;
}

void PlayerSprite::sprite_set_rect_h(int h){
    sprite_rect.h = h;
}

int PlayerSprite::sprite_get_width(){
    return sprite_rect.w;
}

int PlayerSprite::sprite_get_height(){
    return sprite_rect.h;
}
