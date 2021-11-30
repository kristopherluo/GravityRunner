#ifndef _PLAYER_H
#define _PLAYER_H

#include "PlayerSprite.h"

class Player{
    private:
        int player_pos_x, player_pos_y, player_vel, player_step; //player position and velocity vairables
        PlayerSprite sprite;
    public:
        Player();
        ~Player();

        int player_get_pos_x(); //returns current x position of player
        int player_get_pos_y(); //returns current y position of player
        int player_get_vel(); //returns velocity of player
        int player_get_step(); //returns step of player
        void player_set_pos_x(int x); //sets player x position to x parameter
        void player_set_pos_y(int y); //sets player y position to y parameter
};

#endif
