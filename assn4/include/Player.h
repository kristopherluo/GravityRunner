#ifndef _PLAYER_H
#define _PLAYER_H

#include "PlayerSprite.h"

class Player{
    private:
        int player_pos_x, player_pos_y, player_vel; //player position and velocity vairables
        PlayerSprite sprite;
    public:
        float player_start_vel;

        Player();
        ~Player();

        int player_get_pos_x(); //returns current x position of player
        int player_get_pos_y(); //returns current y position of player
        int player_get_vel(); //returns velocity of player
        void player_add_vel(int v); //adds v to the velocity
        void player_set_pos_x(int x); //sets player x position to x parameter
        void player_set_pos_y(int y); //sets player y position to y parameter
        void player_set_vel(int v); //sets velocity of player
};

#endif
