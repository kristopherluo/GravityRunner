#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter(){}

ParticleEmitter::~ParticleEmitter(){}

void ParticleEmitter::particle_emitter_init(const char* texture, SDL_Renderer* ren, int x_start, int y_start, int width_start, int height_start, int type){
    srand(5);
    part_type = type;
    int max_parts = MAX_PARTS;
    if(part_type == PART_TYPE_GLEE){
        for (int i = 0; i < max_parts; i++){
            particles[i].particle_init(texture, ren, x_start, y_start, width_start, height_start);
            particles[i].particle_set_x_vel(3.0 - (rand() % 60)/10.0);
            particles[i].particle_set_y_vel(0 - (rand() % 60)/10.0);
            particles[i].particle_set_lifetime(10 + (rand() % 10));
        }
    }
}


void ParticleEmitter::particle_emitter_update(){
    int max_parts = MAX_PARTS;
    if(part_type == PART_TYPE_GLEE){
        max_parts = MAX_PARTS_GLEE;
        for (int i = 0; i < max_parts; i++){
            particles[i].particle_update_glee();
        }
    }
}

void ParticleEmitter::particle_emitter_draw(SDL_Renderer* ren){
    int max_parts = MAX_PARTS;
    if(part_type == PART_TYPE_GLEE){
        max_parts = MAX_PARTS_GLEE;
        for (int i = 0; i < max_parts; i++){
            particles[i].particle_draw_glee(ren);
        }
    }
}
