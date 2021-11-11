#include "Particle.h"

Particle::Particle(){}

Particle::~Particle(){}

void Particle::particle_init(const char* texture, SDL_Renderer* ren, int x_start, int y_start, int wid, int hei){
    obj_renderer = ren;
    SDL_Surface* temp = IMG_Load(texture);
    particle_texture = SDL_CreateTextureFromSurface(obj_renderer, temp);
    x_pos = x_start;
    y_pos = y_start;
    width = wid;
    height = hei;
}

void Particle::particle_update_glee(){
    x_pos += x_vel; //move the object pos old pos + one timestep x vel
    y_pos += y_vel; //move the object pos old pos ane timestep y vel
    y_vel += 9.8 * 100.0/700.0;
    if (lifetime > 0){
        particle_rect.x = x_pos;
        particle_rect.y = y_pos;
        particle_rect.w = width/2 + width * (int) (10 * lifetime/100);
        particle_rect.h = height/2 + width * (int) (10 * lifetime/100);
    }
    lifetime -= 1;
}

void Particle::particle_draw_glee(SDL_Renderer* ren){
    if(lifetime > 0){
        SDL_SetTextureAlphaMod(particle_texture, (int) 255 * lifetime/20.0);
        SDL_RenderCopy(ren, particle_texture, NULL, &particle_rect);
    }else{
        SDL_SetTextureAlphaMod (particle_texture,255);
    }
}

void Particle::particle_set_x_vel(int vel){
    x_vel = vel;
}

void Particle::particle_set_y_vel(int vel){
    y_vel = vel;
}

void Particle::particle_set_lifetime(int lt){
    lifetime = lt;
}

void Particle::particle_set_x_pos(int pos){
    x_pos = pos;
}
void Particle::particle_set_y_pos(int pos){
    y_pos = pos;
}

int Particle::particle_get_x_pos(){
    return x_pos;
}
int Particle::particle_get_y_pos(){
    return y_pos;
}
