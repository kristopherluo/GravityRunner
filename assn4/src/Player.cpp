#include "Player.h"

Player::Player(){
  player_pos_x = 270;
  player_pos_y = 280;
  player_vel = 10;
  player_step = 40;
}

Player::~Player(){}

int Player::player_get_pos_x(){
    return player_pos_x;
}

int Player::player_get_pos_y(){
    return player_pos_y;
}

int Player::player_get_vel(){
    return player_vel;
}

int Player::player_get_step(){
    return player_step;
}

void Player::player_set_pos_x(int x){
    player_pos_x = x;
}

void Player::player_set_pos_y(int y){
    player_pos_y = y;
}