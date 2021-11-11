#ifndef _PARTICLE_EMITTER_H
#define _PARTICLE_EMITTER_H

#define MAX_PARTS 10
#define MAX_PARTS_SPARK 4
#define MAX_PARTS_GLEE 10
#define PART_TYPE_SPARK 0
#define PART_TYPE_GLEE 1

#include "Particle.h"

class ParticleEmitter{
    private:
        Particle particles[MAX_PARTS]; //array of type Particle to represent different particles
        int part_type; //particle type
    public:
        ParticleEmitter();
        ~ParticleEmitter();
        void particle_emitter_init(const char* texture, SDL_Renderer* ren, int x_start, int y_start, int width_start, int height_start, int type);
        void particle_emitter_draw(SDL_Renderer* ren);
        void particle_emitter_update();
};

#endif
